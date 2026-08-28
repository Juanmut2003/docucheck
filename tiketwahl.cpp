#include "tiketwahl.h"
#include "ui_tiketwahl.h"
#include <QMessageBox>

TiketWahl::TiketWahl(TicketList &ticketList, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TiketWahl)
    , tickets(ticketList)
{
    ui->setupUi(this);

    for (const Ticket &t : tickets.all()) {
        ui->comboBoxBestehendeTickets->addItem(t.title);
    }

    connect(ui->pushButtonOK, &QPushButton::clicked, this, &TiketWahl::accept);
    connect(ui->pushButtonAbbrechen, &QPushButton::clicked, this, &TiketWahl::reject);
    connect(ui->pushButton, &QPushButton::clicked, this, &TiketWahl::onTicketErstellenClicked);
}



TiketWahl::~TiketWahl()
{
    delete ui;
}

Ticket TiketWahl::getSelectedTicket() const
{
    int index = ui->comboBoxBestehendeTickets->currentIndex();
    if (index >= 0 && index < tickets.size())
        return tickets.at(index);
    return Ticket{};
}

int TiketWahl::getSelectedIndex() const
{
    int index = ui->comboBoxBestehendeTickets->currentIndex();
    if (index >= 0 && index < tickets.size())
        return index;
    return -1;
}

void TiketWahl::onTicketErstellenClicked()
{
    QString name = ui->lineEdit->text().trimmed();
    QString beschreibung = ui->textEdit->toPlainText().trimmed();

    if (name.isEmpty()) {
        QMessageBox::warning(this, "Fehler", "Bitte einen Namen für das Ticket eingeben.");
        return;
    }

    Ticket neuesTicket;
    neuesTicket.title = name;
    neuesTicket.description = beschreibung;

    tickets.add(neuesTicket);
    ui->comboBoxBestehendeTickets->addItem(neuesTicket.title);
    ui->comboBoxBestehendeTickets->setCurrentIndex(ui->comboBoxBestehendeTickets->count() - 1);

    ui->lineEdit->clear();
    ui->textEdit->clear();

    // Neu erstelltes Ticket direkt in der Detailansicht öffnen
    accept();
}

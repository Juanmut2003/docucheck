#include "tiketwahl.h"
#include "ui_tiketwahl.h"
#include <QMessageBox>

TiketWahl::TiketWahl(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TiketWahl)
{
    ui->setupUi(this);

    tickets = Ticket::dummyTickets();

    for (const Ticket &t : tickets) {
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
void TiketWahl::onTicketErstellenClicked()
{
    QString name = ui->lineEdit->text().trimmed();
    QString beschreibung = ui->textEdit->toPlainText().trimmed();

    if (name.isEmpty()) {
        QMessageBox::warning(this, "Fehler", "Bitte einen Namen für das Ticket eingeben.");
        return;
    }

    Ticket neuesTicket;
    neuesTicket.name = name;
    neuesTicket.beschreibung = beschreibung;

    tickets.append(neuesTicket);
    ui->comboBoxBestehendeTickets->addItem(neuesTicket.name);
    ui->comboBoxBestehendeTickets->setCurrentIndex(ui->comboBoxBestehendeTickets->count() - 1);

    ui->lineEdit->clear();
    ui->textEdit->clear();
}

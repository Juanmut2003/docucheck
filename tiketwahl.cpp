#include "tiketwahl.h"
#include "ui_tiketwahl.h"
#include <QMessageBox>
#include <QComboBox>

void TiketWahl::addTicketItem(const QString &title)
{
    QComboBox *combo = ui->comboExistingTickets;
    combo->addItem(title);
    // Vollstaendigen Titel als Tooltip hinterlegen, falls die Anzeige gekuerzt wird.
    combo->setItemData(combo->count() - 1, title, Qt::ToolTipRole);
}

TiketWahl::TiketWahl(TicketList &ticketList, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TiketWahl)
    , tickets(ticketList)
{
    ui->setupUi(this);

    for (const Ticket &t : tickets.all()) {
        addTicketItem(t.displayName());
    }

    connect(ui->pushButtonOpen, &QPushButton::clicked, this, &TiketWahl::accept);
    connect(ui->pushButtonCancel, &QPushButton::clicked, this, &TiketWahl::reject);
    connect(ui->pushButtonCreate, &QPushButton::clicked, this, &TiketWahl::onCreateTicketClicked);
}



TiketWahl::~TiketWahl()
{
    delete ui;
}

Ticket TiketWahl::getSelectedTicket() const
{
    int index = ui->comboExistingTickets->currentIndex();
    if (index >= 0 && index < tickets.size())
        return tickets.at(index);
    return Ticket{};
}

int TiketWahl::getSelectedIndex() const
{
    int index = ui->comboExistingTickets->currentIndex();
    if (index >= 0 && index < tickets.size())
        return index;
    return -1;
}

void TiketWahl::onCreateTicketClicked()
{
    QString name = ui->lineEditName->text().trimmed();
    QString beschreibung = ui->textEditDescription->toPlainText().trimmed();

    if (name.isEmpty()) {
        QMessageBox::warning(this, "Fehler", "Bitte einen Namen für das Ticket eingeben.");
        return;
    }

    Ticket neuesTicket;
    neuesTicket.title = name;
    neuesTicket.description = beschreibung;

    tickets.add(neuesTicket);
    addTicketItem(tickets.at(tickets.size() - 1).displayName());
    ui->comboExistingTickets->setCurrentIndex(ui->comboExistingTickets->count() - 1);

    ui->lineEditName->clear();
    ui->textEditDescription->clear();

    // Neu erstelltes Ticket direkt in der Detailansicht öffnen
    accept();
}

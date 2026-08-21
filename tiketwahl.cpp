#include "tiketwahl.h"
#include "ui_tiketwahl.h"

TiketWahl::TiketWahl(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TiketWahl)
{
    ui->setupUi(this);

    tickets = {
        {"Login-Bug", "Der Login-Button reagiert nicht auf Klick."},
        {"Ladezeit zu lang", "Die Startseite braucht über 5 Sekunden zum Laden."},
        {"Darkmode fehlt", "Es gibt noch keine Möglichkeit, den Darkmode zu aktivieren."}
    };

    for (const Ticket &t : tickets) {
        ui->comboBoxBestehendeTickets->addItem(t.name);
    }

    connect(ui->pushButtonOK, &QPushButton::clicked, this, &TiketWahl::accept);
    connect(ui->pushButtonAbbrechen, &QPushButton::clicked, this, &TiketWahl::reject);
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

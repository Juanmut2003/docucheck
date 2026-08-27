#include "tiketwahl.h"
#include "ui_tiketwahl.h"

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

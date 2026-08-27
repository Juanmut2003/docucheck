#include "frmmain.h"
#include "ui_frmmain.h"
#include "tiketwahl.h"

frmMain::frmMain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::frmMain)
{
    ui->setupUi(this);

    // Add a few dummy tickets right when the app opens (issue #7).
    tickets.addDummyTickets();
}

frmMain::~frmMain()
{
    delete ui;
}

void frmMain::on_pushButton_2_clicked()
{
    TiketWahl dialog(tickets, this);
    if (dialog.exec() == QDialog::Accepted) {
        Ticket t = dialog.getSelectedTicket();
        ui->labelName->setText(t.title);
        ui->labelBeschreibung->setText(t.description);
    }
}

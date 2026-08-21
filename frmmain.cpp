#include "frmmain.h"
#include "ui_frmmain.h"
#include "tiketwahl.h"

frmMain::frmMain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::frmMain)
{
    ui->setupUi(this);
}

frmMain::~frmMain()
{
    delete ui;
}

void frmMain::on_pushButton_2_clicked()
{
    TiketWahl dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        Ticket t = dialog.getSelectedTicket();
        ui->labelName->setText(t.name);
        ui->labelBeschreibung->setText(t.beschreibung);
    }
}





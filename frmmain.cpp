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
    TiketWahl *popup = new TiketWahl(this);
    popup->exec();
}


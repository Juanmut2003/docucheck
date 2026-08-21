#include "tiketwahl.h"
#include "ui_tiketwahl.h"

TiketWahl::TiketWahl(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TiketWahl)
{
    ui->setupUi(this);
}

TiketWahl::~TiketWahl()
{
    delete ui;
}

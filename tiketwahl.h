#ifndef TIKETWAHL_H
#define TIKETWAHL_H

#include <QDialog>

namespace Ui {
class TiketWahl;
}

class TiketWahl : public QDialog
{
    Q_OBJECT

public:
    explicit TiketWahl(QWidget *parent = nullptr);
    ~TiketWahl();

private:
    Ui::TiketWahl *ui;
};

#endif // TIKETWAHL_H

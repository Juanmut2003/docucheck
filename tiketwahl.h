#ifndef TIKETWAHL_H
#define TIKETWAHL_H

#include <QDialog>
#include <QString>
#include <QList>

#include "ticket.h"

namespace Ui {
class TiketWahl;
}

class TiketWahl : public QDialog
{
    Q_OBJECT

public:
    explicit TiketWahl(QWidget *parent = nullptr);
    ~TiketWahl();

    Ticket getSelectedTicket() const;

private:
    Ui::TiketWahl *ui;
    QList<Ticket> tickets;
};




#endif // TIKETWAHL_H

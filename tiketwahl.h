#ifndef TIKETWAHL_H
#define TIKETWAHL_H

#include <QDialog>
#include <QString>

#include "ticket.h"
#include "ticketlist.h"

namespace Ui {
class TiketWahl;
}

class TiketWahl : public QDialog
{
    Q_OBJECT

public:
    explicit TiketWahl(TicketList &ticketList, QWidget *parent = nullptr);
    ~TiketWahl();

    Ticket getSelectedTicket() const;

private:
    void onTicketErstellenClicked();
    void addTicketItem(const QString &title);
    Ui::TiketWahl *ui;
    // Shared ticket model owned by the main window.
    TicketList &tickets;
};




#endif // TIKETWAHL_H

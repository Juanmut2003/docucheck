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
    int getSelectedIndex() const;

private:
    void onProjectFilterChanged();
    void addTicketItem(const QString &title, int ticketIndex);
    void populateProjectCombo();
    void populateTicketCombo(const QString &projectFilter = QString());
    Ui::TiketWahl *ui;
    TicketList &tickets;
};




#endif // TIKETWAHL_H

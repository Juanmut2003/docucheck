#ifndef TIKETWAHL_H
#define TIKETWAHL_H

#include <QDialog>
#include <QString>

#include "projectlist.h"
#include "ticket.h"
#include "ticketlist.h"

namespace Ui {
class TiketWahl;
}

class TiketWahl : public QDialog
{
    Q_OBJECT

public:
    explicit TiketWahl(TicketList &ticketList, ProjectList &projectList, QWidget *parent = nullptr);
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
    ProjectList &projects;
};




#endif // TIKETWAHL_H

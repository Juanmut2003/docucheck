#ifndef TICKETERSTELLEN_H
#define TICKETERSTELLEN_H

#include <QDialog>

#include "ticket.h"
#include "ticketlist.h"
#include "projectlist.h"

namespace Ui {
class TicketErstellen;
}

class TicketErstellen : public QDialog
{
    Q_OBJECT

public:
    explicit TicketErstellen(TicketList &ticketList, ProjectList &projectList, QWidget *parent = nullptr);
    ~TicketErstellen();

    int getCreatedIndex() const;

private:
    void onCreateTicketClicked();
    Ui::TicketErstellen *ui;
    TicketList &tickets;
    ProjectList &projects;
    int createdIndex = -1;
};

#endif // TICKETERSTELLEN_H

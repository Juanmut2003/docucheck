#ifndef STAMMDATENVERWALTUNG_H
#define STAMMDATENVERWALTUNG_H

#include <QDialog>

#include "assigneelist.h"
#include "projectlist.h"
#include "ticketlist.h"

namespace Ui {
class StammdatenVerwaltung;
}

class StammdatenVerwaltung : public QDialog
{
    Q_OBJECT

public:
    explicit StammdatenVerwaltung(ProjectList &projectList, AssigneeList &assigneeList,
                                   TicketList &ticketList, QWidget *parent = nullptr);
    ~StammdatenVerwaltung();

private:
    void onAddProjectClicked();
    void onDeleteProjectsClicked();
    void onAddAssigneeClicked();
    void onDeleteAssigneesClicked();
    void populateProjectList();
    void populateAssigneeList();

    Ui::StammdatenVerwaltung *ui;
    ProjectList &projects;
    AssigneeList &assignees;
    TicketList &tickets;
};

#endif // STAMMDATENVERWALTUNG_H

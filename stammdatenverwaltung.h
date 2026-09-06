#ifndef STAMMDATENVERWALTUNG_H
#define STAMMDATENVERWALTUNG_H

#include <QDialog>
#include <QString>

#include "assigneelist.h"
#include "projectlist.h"
#include "ticketlist.h"
#include "userlist.h"

namespace Ui {
class StammdatenVerwaltung;
}

class StammdatenVerwaltung : public QDialog
{
    Q_OBJECT

public:
    explicit StammdatenVerwaltung(ProjectList &projectList, AssigneeList &assigneeList,
                                   TicketList &ticketList, UserList &userList,
                                   const QString &currentUsername, QWidget *parent = nullptr);
    ~StammdatenVerwaltung();

private:
    void onAddProjectClicked();
    void onDeleteProjectsClicked();
    void onAddAssigneeClicked();
    void onDeleteAssigneesClicked();
    void onAddUserClicked();
    void onDeleteUsersClicked();
    void populateProjectList();
    void populateAssigneeList();
    void populateUserList();

    Ui::StammdatenVerwaltung *ui;
    ProjectList &projects;
    AssigneeList &assignees;
    TicketList &tickets;
    UserList &users;
    QString currentUsername;
};

#endif // STAMMDATENVERWALTUNG_H

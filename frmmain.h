#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QMainWindow>

#include "assigneelist.h"
#include "projectlist.h"
#include "ticketlist.h"
#include "user.h"
#include "userlist.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class frmMain;
}
QT_END_NAMESPACE

class frmMain : public QMainWindow
{
    Q_OBJECT

public:
    frmMain(const User &currentUser, UserList &userList, QWidget *parent = nullptr);
    ~frmMain();

    // true, wenn das Fenster wegen "Logout" geschlossen wurde (statt Beenden).
    bool logoutRequested() const { return m_logoutRequested; }

private slots:
    void on_pushButtonSelectTicket_clicked();
    void on_pushButtonCreateTicket_clicked();
    void on_pushButtonManageProjects_clicked();
    void on_pushButtonSave_clicked();
    void on_pushButtonLogout_clicked();

private:
    void showTicket(const Ticket &ticket);
    void refreshProjectCombo();
    void refreshAssigneeCombo();
    void applyRolePermissions();

    Ui::frmMain *ui;
    TicketList tickets;
    ProjectList projects;
    AssigneeList assignees;
    UserList &users;
    User currentUser;
    int currentTicketIndex = -1;
    bool m_logoutRequested = false;
};
#endif // FRMMAIN_H

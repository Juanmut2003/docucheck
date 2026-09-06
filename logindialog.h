#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

#include "user.h"
#include "userlist.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(const UserList &userList, QWidget *parent = nullptr);
    ~LoginDialog();

    // Nur gueltig, wenn der Dialog mit Accepted geschlossen wurde.
    User authenticatedUser() const;

private:
    void onLoginClicked();

    Ui::LoginDialog *ui;
    const UserList &users;
    User m_user;
};

#endif // LOGINDIALOG_H

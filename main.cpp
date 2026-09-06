#include "frmmain.h"
#include "logindialog.h"
#include "userlist.h"
#include "appstyle.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    applyModernStyle(a);

    UserList users;
    users.addDefaults();

    // Login -> Hauptfenster -> (Logout) -> wieder Login. Beenden per "Quit" im
    // Login-Dialog oder Schliessen des Hauptfensters ohne Logout.
    while (true) {
        LoginDialog login(users);
        if (login.exec() != QDialog::Accepted)
            break;

        frmMain w(login.authenticatedUser(), users);
        w.show();
        a.exec();

        if (!w.logoutRequested())
            break;
    }

    return 0;
}

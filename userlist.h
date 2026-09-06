#ifndef USERLIST_H
#define USERLIST_H

#include <QList>
#include <QString>

#include "user.h"

// In-Memory-Benutzerverwaltung, analog zu ProjectList / AssigneeList.
class UserList
{
public:
    UserList() = default;

    void addDefaults();

    bool add(const QString &username, const QString &password, UserRole role);
    void remove(const QString &username);
    bool contains(const QString &username) const;

    // Bei korrekten Zugangsdaten den passenden Benutzer, sonst nullptr.
    const User *authenticate(const QString &username, const QString &password) const;
    // Benutzer per Name (ohne Passwortpruefung), sonst nullptr.
    const User *find(const QString &username) const;

    int adminCount() const;

    bool isEmpty() const;
    int size() const;
    const QList<User> &all() const;

private:
    int indexOf(const QString &username) const;

    QList<User> m_users;
};

#endif // USERLIST_H

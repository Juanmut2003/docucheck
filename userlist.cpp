#include "userlist.h"

void UserList::addDefaults()
{
    // Zwei Demo-Konten mit unterschiedlichen Rollen (siehe Login-Dialog-Hinweis).
    add(QStringLiteral("admin01"), QStringLiteral("admin"), UserRole::Admin);
    add(QStringLiteral("dev01"),   QStringLiteral("dev"),   UserRole::Developer);
}

bool UserList::add(const QString &username, const QString &password, UserRole role)
{
    if (username.isEmpty() || password.isEmpty() || contains(username))
        return false;

    m_users.append(User{username, password, role});
    return true;
}

void UserList::remove(const QString &username)
{
    const int index = indexOf(username);
    if (index >= 0)
        m_users.removeAt(index);
}

bool UserList::contains(const QString &username) const
{
    return indexOf(username) >= 0;
}

const User *UserList::authenticate(const QString &username, const QString &password) const
{
    const User *user = find(username);
    if (user && user->password == password)
        return user;
    return nullptr;
}

const User *UserList::find(const QString &username) const
{
    const int index = indexOf(username);
    return index >= 0 ? &m_users.at(index) : nullptr;
}

int UserList::adminCount() const
{
    int count = 0;
    for (const User &user : m_users)
        if (user.role == UserRole::Admin)
            ++count;
    return count;
}

bool UserList::isEmpty() const
{
    return m_users.isEmpty();
}

int UserList::size() const
{
    return m_users.size();
}

const QList<User> &UserList::all() const
{
    return m_users;
}

int UserList::indexOf(const QString &username) const
{
    for (int i = 0; i < m_users.size(); ++i)
        if (m_users.at(i).username.compare(username, Qt::CaseInsensitive) == 0)
            return i;
    return -1;
}

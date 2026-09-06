#include "user.h"

QString roleToString(UserRole role)
{
    switch (role) {
    case UserRole::Developer: return QStringLiteral("Developer");
    case UserRole::Admin:     return QStringLiteral("Admin");
    }
    return QString();
}

UserRole roleFromString(const QString &text)
{
    if (text == QStringLiteral("Admin"))
        return UserRole::Admin;
    return UserRole::Developer;
}

#ifndef USER_H
#define USER_H

#include <QString>

// Zwei Rollen mit unterschiedlichen Rechten in der Anwendung:
//  - Developer: darf nur an Tickets/Vorgaengen arbeiten.
//  - Admin:     zusaetzlich Projekte, Assignees und Benutzer verwalten (Teamlead).
enum class UserRole {
    Developer,
    Admin
};

QString roleToString(UserRole role);
UserRole roleFromString(const QString &text);

struct User {
    QString username;
    QString password;
    UserRole role = UserRole::Developer;

    // Sammelrecht fuer die Stammdatenverwaltung (Projekte / Assignees / Benutzer).
    bool canManageBaseData() const { return role == UserRole::Admin; }
};

#endif // USER_H

#ifndef TICKET_H
#define TICKET_H

#include <QString>
#include <QDateTime>
#include <QList>

enum class Priority {
    Low,
    Medium,
    High
};

enum class Status {
    Planning,
    InProgress,
    Testing,
    Production
};

enum class TicketType {
    Feature,
    Bug
};

QString priorityToString(Priority priority);
QString statusToString(Status status);
QString ticketTypeToString(TicketType type);

struct Ticket {
    QString title;
    QString description;
    QString project;
    QString assignee;
    Priority priority = Priority::Medium;
    Status status = Status::Planning;
    TicketType type = TicketType::Feature;
    int storyPoints = 0;
    QDateTime createdAt = QDateTime::currentDateTime();

    static QList<Ticket> dummyTickets();
};

#endif // TICKET_H

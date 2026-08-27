#ifndef TICKET_H
#define TICKET_H

#include <QString>
#include <QDateTime>
#include <QList>

// Priority of a ticket (see issue #6: Niedrig / Mittel / Hoch).
enum class Priority {
    Low,
    Medium,
    High
};

// Workflow state of a ticket. Mirrors the "State" combo box on the main window.
enum class Status {
    Planning,
    InProgress,
    Testing,
    Production
};

// Kind of work a ticket describes. Mirrors the "Type" combo box.
enum class TicketType {
    Feature,
    Bug
};

// Human readable text for the enum values (used for combo boxes / labels).
QString priorityToString(Priority priority);
QString statusToString(Status status);
QString ticketTypeToString(TicketType type);

// Simple data model for a single ticket. Holds every field shown in the UI:
// name, description, project, priority, type, state, assignee, story points
// and the creation date.
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

    // A handful of dummy tickets for testing / demo purposes.
    static QList<Ticket> dummyTickets();
};

#endif // TICKET_H

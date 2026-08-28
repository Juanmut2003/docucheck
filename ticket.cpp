#include "ticket.h"

QString priorityToString(Priority priority)
{
    switch (priority) {
    case Priority::Low:    return QStringLiteral("Low");
    case Priority::Medium: return QStringLiteral("Medium");
    case Priority::High:   return QStringLiteral("High");
    }
    return QString();
}

QString statusToString(Status status)
{
    switch (status) {
    case Status::Planning:   return QStringLiteral("Planning");
    case Status::InProgress: return QStringLiteral("In Progress");
    case Status::Testing:    return QStringLiteral("Testing");
    case Status::Production:  return QStringLiteral("Production");
    }
    return QString();
}

QString ticketTypeToString(TicketType type)
{
    switch (type) {
    case TicketType::Feature: return QStringLiteral("Feature");
    case TicketType::Bug:     return QStringLiteral("Bug");
    }
    return QString();
}

QString Ticket::displayName() const
{
    if (id <= 0)
        return title;
    return QStringLiteral("#%1 - %2").arg(id).arg(title);
}

QList<Ticket> Ticket::dummyTickets()
{
    QList<Ticket> tickets;

    Ticket loginBug;
    loginBug.title = QStringLiteral("Login-Bug");
    loginBug.description = QStringLiteral("The login button does not react to a click.");
    loginBug.project = QStringLiteral("Star Wars 10");
    loginBug.assignee = QStringLiteral("CR7 Juan Siuuuu");
    loginBug.priority = Priority::High;
    loginBug.status = Status::InProgress;
    loginBug.type = TicketType::Bug;
    loginBug.storyPoints = 3;
    tickets.append(loginBug);

    Ticket loadTime;
    loadTime.title = QStringLiteral("Loading time too long");
    loadTime.description = QStringLiteral("The start page needs more than 5 seconds to load.");
    loadTime.project = QStringLiteral("Atlantis");
    loadTime.assignee = QStringLiteral("Flooor");
    loadTime.priority = Priority::Medium;
    loadTime.status = Status::Planning;
    loadTime.type = TicketType::Bug;
    loadTime.storyPoints = 5;
    tickets.append(loadTime);

    Ticket darkMode;
    darkMode.title = QStringLiteral("Dark mode missing");
    darkMode.description = QStringLiteral("There is no way yet to enable the dark mode.");
    darkMode.project = QStringLiteral("Area 51");
    darkMode.assignee = QStringLiteral("Lionel Arian Pepsi");
    darkMode.priority = Priority::Low;
    darkMode.status = Status::Testing;
    darkMode.type = TicketType::Feature;
    darkMode.storyPoints = 8;
    tickets.append(darkMode);

    return tickets;
}

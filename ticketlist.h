#ifndef TICKETLIST_H
#define TICKETLIST_H

#include <QList>

#include "ticket.h"

// Model that holds every existing ticket. It is created once when the
// application starts and seeded with a few dummy tickets (see issue #7).
// The "Select Ticket" dialog reads from it to fill the "Existing Tickets"
// combo box; it is never shown directly in the main window.
class TicketList
{
public:
    TicketList() = default;

    // Adds a handful of dummy tickets so the list is not empty on start.
    void addDummyTickets();

    // Appends a single ticket (e.g. one created in the dialog).
    void add(const Ticket &ticket);
    void clear();

    bool isEmpty() const;
    int size() const;
    const Ticket &at(int index) const;
    const QList<Ticket> &all() const;

private:
    QList<Ticket> m_tickets;
};

#endif // TICKETLIST_H

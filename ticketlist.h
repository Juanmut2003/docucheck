#ifndef TICKETLIST_H
#define TICKETLIST_H

#include <QList>

#include "ticket.h"

class TicketList
{
public:
    TicketList() = default;

    void addDummyTickets();

    void add(const Ticket &ticket);
    void update(int index, const Ticket &ticket);
    void clear();

    bool isEmpty() const;
    int size() const;
    const Ticket &at(int index) const;
    const QList<Ticket> &all() const;

private:
    QList<Ticket> m_tickets;
};

#endif // TICKETLIST_H

#include "ticketlist.h"

void TicketList::addDummyTickets()
{
    m_tickets.append(Ticket::dummyTickets());
}

void TicketList::add(const Ticket &ticket)
{
    m_tickets.append(ticket);
}

void TicketList::update(int index, const Ticket &ticket)
{
    if (index >= 0 && index < m_tickets.size())
        m_tickets[index] = ticket;
}

void TicketList::clear()
{
    m_tickets.clear();
}

bool TicketList::isEmpty() const
{
    return m_tickets.isEmpty();
}

int TicketList::size() const
{
    return m_tickets.size();
}

const Ticket &TicketList::at(int index) const
{
    return m_tickets.at(index);
}

const QList<Ticket> &TicketList::all() const
{
    return m_tickets;
}

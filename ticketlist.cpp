#include "ticketlist.h"

void TicketList::addDummyTickets()
{
    const QList<Ticket> dummies = Ticket::dummyTickets();
    for (const Ticket &t : dummies)
        add(t);
}

void TicketList::add(const Ticket &ticket)
{
    Ticket t = ticket;
    t.id = m_nextId++;
    m_tickets.append(t);
}

void TicketList::update(int index, const Ticket &ticket)
{
    if (index >= 0 && index < m_tickets.size()) {
        Ticket t = ticket;
        t.id = m_tickets[index].id; // laufende Nummer bleibt erhalten
        m_tickets[index] = t;
    }
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

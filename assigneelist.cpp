#include "assigneelist.h"

void AssigneeList::addDefaults()
{
    static const QStringList defaults = {
        QStringLiteral("CR7 Juan Siuuuu"),
        QStringLiteral("Flooor"),
        QStringLiteral("Lionel Arian Pepsi"),
    };
    for (const QString &name : defaults)
        add(name);
}

bool AssigneeList::add(const QString &name)
{
    if (name.isEmpty() || contains(name))
        return false;

    m_assignees.append(name);
    m_assignees.sort(Qt::CaseInsensitive);
    return true;
}

void AssigneeList::remove(const QString &name)
{
    m_assignees.removeAll(name);
}

bool AssigneeList::contains(const QString &name) const
{
    return m_assignees.contains(name, Qt::CaseInsensitive);
}

bool AssigneeList::isEmpty() const
{
    return m_assignees.isEmpty();
}

int AssigneeList::size() const
{
    return m_assignees.size();
}

const QStringList &AssigneeList::all() const
{
    return m_assignees;
}

#include "projectlist.h"

void ProjectList::addDefaults()
{
    static const QStringList defaults = {
        QStringLiteral("Star Wars 10"),
        QStringLiteral("Bermuda Dreieck"),
        QStringLiteral("Atlantis"),
        QStringLiteral("Area 51"),
    };
    for (const QString &name : defaults)
        add(name);
}

bool ProjectList::add(const QString &name)
{
    if (name.isEmpty() || contains(name))
        return false;

    m_projects.append(name);
    m_projects.sort(Qt::CaseInsensitive);
    return true;
}

void ProjectList::remove(const QString &name)
{
    m_projects.removeAll(name);
}

bool ProjectList::contains(const QString &name) const
{
    return m_projects.contains(name, Qt::CaseInsensitive);
}

bool ProjectList::isEmpty() const
{
    return m_projects.isEmpty();
}

int ProjectList::size() const
{
    return m_projects.size();
}

const QStringList &ProjectList::all() const
{
    return m_projects;
}

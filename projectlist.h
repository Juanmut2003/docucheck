#ifndef PROJECTLIST_H
#define PROJECTLIST_H

#include <QStringList>

class ProjectList
{
public:
    ProjectList() = default;

    void addDefaults();

    bool add(const QString &name);
    void remove(const QString &name);
    bool contains(const QString &name) const;

    bool isEmpty() const;
    int size() const;
    const QStringList &all() const;

private:
    QStringList m_projects;
};

#endif // PROJECTLIST_H

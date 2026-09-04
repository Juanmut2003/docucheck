#ifndef ASSIGNEELIST_H
#define ASSIGNEELIST_H

#include <QStringList>

class AssigneeList
{
public:
    AssigneeList() = default;

    void addDefaults();

    bool add(const QString &name);
    void remove(const QString &name);
    bool contains(const QString &name) const;

    bool isEmpty() const;
    int size() const;
    const QStringList &all() const;

private:
    QStringList m_assignees;
};

#endif // ASSIGNEELIST_H

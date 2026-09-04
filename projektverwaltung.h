#ifndef PROJEKTVERWALTUNG_H
#define PROJEKTVERWALTUNG_H

#include <QDialog>

#include "projectlist.h"
#include "ticketlist.h"

namespace Ui {
class ProjektVerwaltung;
}

class ProjektVerwaltung : public QDialog
{
    Q_OBJECT

public:
    explicit ProjektVerwaltung(ProjectList &projectList, TicketList &ticketList, QWidget *parent = nullptr);
    ~ProjektVerwaltung();

private:
    void onAddProjectClicked();
    void onDeleteSelectedClicked();
    void populateProjectList();

    Ui::ProjektVerwaltung *ui;
    ProjectList &projects;
    TicketList &tickets;
};

#endif // PROJEKTVERWALTUNG_H

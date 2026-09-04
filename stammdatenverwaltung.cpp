#include "stammdatenverwaltung.h"
#include "ui_stammdatenverwaltung.h"
#include <QAbstractItemView>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QStyle>

StammdatenVerwaltung::StammdatenVerwaltung(ProjectList &projectList, AssigneeList &assigneeList,
                                             TicketList &ticketList, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StammdatenVerwaltung)
    , projects(projectList)
    , assignees(assigneeList)
    , tickets(ticketList)
{
    ui->setupUi(this);
    ui->listProjects->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->listAssignees->setSelectionMode(QAbstractItemView::ExtendedSelection);

    // Widgets auf einer QTabWidget-Seite, die bei setupUi() bereits als "aktueller Tab"
    // gilt, werden manchmal poliert, bevor uic die dynamischen Qt-Designer-Properties
    // (hier: role="destructive") setzt - das QSS-Attributselektor-Matching greift dann
    // fuer diese Seite nicht. Betroffene Widgets nach setupUi() explizit neu polieren.
    for (QWidget *w : {static_cast<QWidget *>(ui->pushButtonDeleteProjects),
                        static_cast<QWidget *>(ui->pushButtonDeleteAssignees)}) {
        w->style()->unpolish(w);
        w->style()->polish(w);
    }

    populateProjectList();
    populateAssigneeList();

    connect(ui->pushButtonAddProject, &QPushButton::clicked, this, &StammdatenVerwaltung::onAddProjectClicked);
    connect(ui->pushButtonDeleteProjects, &QPushButton::clicked, this, &StammdatenVerwaltung::onDeleteProjectsClicked);
    connect(ui->pushButtonAddAssignee, &QPushButton::clicked, this, &StammdatenVerwaltung::onAddAssigneeClicked);
    connect(ui->pushButtonDeleteAssignees, &QPushButton::clicked, this, &StammdatenVerwaltung::onDeleteAssigneesClicked);
    connect(ui->pushButtonClose, &QPushButton::clicked, this, &StammdatenVerwaltung::accept);
}

StammdatenVerwaltung::~StammdatenVerwaltung()
{
    delete ui;
}

void StammdatenVerwaltung::populateProjectList()
{
    ui->listProjects->clear();
    ui->listProjects->addItems(projects.all());
}

void StammdatenVerwaltung::populateAssigneeList()
{
    ui->listAssignees->clear();
    ui->listAssignees->addItems(assignees.all());
}

void StammdatenVerwaltung::onAddProjectClicked()
{
    QString name = ui->lineEditProjectName->text().trimmed();

    if (name.isEmpty()) {
        QMessageBox::warning(this, "Fehler", "Bitte einen Namen für das Projekt eingeben.");
        return;
    }
    if (!projects.add(name)) {
        QMessageBox::warning(this, "Fehler", "Dieses Projekt existiert bereits.");
        return;
    }

    populateProjectList();
    ui->lineEditProjectName->clear();
}

void StammdatenVerwaltung::onDeleteProjectsClicked()
{
    const QList<QListWidgetItem *> selected = ui->listProjects->selectedItems();
    if (selected.isEmpty())
        return;

    for (QListWidgetItem *item : selected) {
        const QString name = item->text();
        // Tickets bleiben erhalten, verlieren aber die Zuordnung zum geloeschten Projekt.
        tickets.clearProject(name);
        projects.remove(name);
    }

    populateProjectList();
}

void StammdatenVerwaltung::onAddAssigneeClicked()
{
    QString name = ui->lineEditAssigneeName->text().trimmed();

    if (name.isEmpty()) {
        QMessageBox::warning(this, "Fehler", "Bitte einen Namen für den Assignee eingeben.");
        return;
    }
    if (!assignees.add(name)) {
        QMessageBox::warning(this, "Fehler", "Dieser Assignee existiert bereits.");
        return;
    }

    populateAssigneeList();
    ui->lineEditAssigneeName->clear();
}

void StammdatenVerwaltung::onDeleteAssigneesClicked()
{
    const QList<QListWidgetItem *> selected = ui->listAssignees->selectedItems();
    if (selected.isEmpty())
        return;

    for (QListWidgetItem *item : selected) {
        const QString name = item->text();
        // Tickets bleiben erhalten, verlieren aber die Zuordnung zum geloeschten Assignee.
        tickets.clearAssignee(name);
        assignees.remove(name);
    }

    populateAssigneeList();
}

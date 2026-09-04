#include "projektverwaltung.h"
#include "ui_projektverwaltung.h"
#include <QAbstractItemView>
#include <QListWidgetItem>
#include <QMessageBox>

ProjektVerwaltung::ProjektVerwaltung(ProjectList &projectList, TicketList &ticketList, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ProjektVerwaltung)
    , projects(projectList)
    , tickets(ticketList)
{
    ui->setupUi(this);
    ui->listProjects->setSelectionMode(QAbstractItemView::ExtendedSelection);

    populateProjectList();

    connect(ui->pushButtonCreate, &QPushButton::clicked, this, &ProjektVerwaltung::onAddProjectClicked);
    connect(ui->pushButtonDeleteSelected, &QPushButton::clicked, this, &ProjektVerwaltung::onDeleteSelectedClicked);
    connect(ui->pushButtonClose, &QPushButton::clicked, this, &ProjektVerwaltung::accept);
}

ProjektVerwaltung::~ProjektVerwaltung()
{
    delete ui;
}

void ProjektVerwaltung::populateProjectList()
{
    ui->listProjects->clear();
    ui->listProjects->addItems(projects.all());
}

void ProjektVerwaltung::onAddProjectClicked()
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

void ProjektVerwaltung::onDeleteSelectedClicked()
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

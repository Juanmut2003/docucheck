#include "stammdatenverwaltung.h"
#include "ui_stammdatenverwaltung.h"
#include <QAbstractItemView>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QStyle>

StammdatenVerwaltung::StammdatenVerwaltung(ProjectList &projectList, AssigneeList &assigneeList,
                                             TicketList &ticketList, UserList &userList,
                                             const QString &currentUser, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StammdatenVerwaltung)
    , projects(projectList)
    , assignees(assigneeList)
    , tickets(ticketList)
    , users(userList)
    , currentUsername(currentUser)
{
    ui->setupUi(this);
    ui->listProjects->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->listAssignees->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->listUsers->setSelectionMode(QAbstractItemView::ExtendedSelection);

    // Widgets auf einer QTabWidget-Seite, die bei setupUi() bereits als "aktueller Tab"
    // gilt, werden manchmal poliert, bevor uic die dynamischen Qt-Designer-Properties
    // (hier: role="destructive") setzt - das QSS-Attributselektor-Matching greift dann
    // fuer diese Seite nicht. Betroffene Widgets nach setupUi() explizit neu polieren.
    for (QWidget *w : {static_cast<QWidget *>(ui->pushButtonDeleteProjects),
                        static_cast<QWidget *>(ui->pushButtonDeleteAssignees),
                        static_cast<QWidget *>(ui->pushButtonDeleteUsers)}) {
        w->style()->unpolish(w);
        w->style()->polish(w);
    }

    populateProjectList();
    populateAssigneeList();
    populateUserList();

    connect(ui->pushButtonAddProject, &QPushButton::clicked, this, &StammdatenVerwaltung::onAddProjectClicked);
    connect(ui->pushButtonDeleteProjects, &QPushButton::clicked, this, &StammdatenVerwaltung::onDeleteProjectsClicked);
    connect(ui->pushButtonAddAssignee, &QPushButton::clicked, this, &StammdatenVerwaltung::onAddAssigneeClicked);
    connect(ui->pushButtonDeleteAssignees, &QPushButton::clicked, this, &StammdatenVerwaltung::onDeleteAssigneesClicked);
    connect(ui->pushButtonAddUser, &QPushButton::clicked, this, &StammdatenVerwaltung::onAddUserClicked);
    connect(ui->pushButtonDeleteUsers, &QPushButton::clicked, this, &StammdatenVerwaltung::onDeleteUsersClicked);
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

void StammdatenVerwaltung::populateUserList()
{
    ui->listUsers->clear();
    for (const User &user : users.all()) {
        auto *item = new QListWidgetItem(
            QStringLiteral("%1  —  %2").arg(user.username, roleToString(user.role)));
        item->setData(Qt::UserRole, user.username); // echten Namen fuer Loeschen hinterlegen
        ui->listUsers->addItem(item);
    }
}

void StammdatenVerwaltung::onAddUserClicked()
{
    const QString name = ui->lineEditUserName->text().trimmed();
    const QString password = ui->lineEditUserPassword->text();
    const UserRole role = roleFromString(ui->comboUserRole->currentText());

    if (name.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Fehler", "Bitte Benutzername und Passwort eingeben.");
        return;
    }
    if (!users.add(name, password, role)) {
        QMessageBox::warning(this, "Fehler", "Dieser Benutzername existiert bereits.");
        return;
    }

    populateUserList();
    ui->lineEditUserName->clear();
    ui->lineEditUserPassword->clear();
}

void StammdatenVerwaltung::onDeleteUsersClicked()
{
    const QList<QListWidgetItem *> selected = ui->listUsers->selectedItems();
    if (selected.isEmpty())
        return;

    for (QListWidgetItem *item : selected) {
        const QString name = item->data(Qt::UserRole).toString();

        if (name.compare(currentUsername, Qt::CaseInsensitive) == 0) {
            QMessageBox::warning(this, "Fehler",
                                 "Der aktuell angemeldete Benutzer kann nicht gelöscht werden.");
            continue;
        }

        const User *user = users.find(name);
        if (user && user->role == UserRole::Admin && users.adminCount() <= 1) {
            QMessageBox::warning(this, "Fehler",
                                 "Der letzte Administrator kann nicht gelöscht werden.");
            continue;
        }

        users.remove(name);
    }

    populateUserList();
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

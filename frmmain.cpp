#include "frmmain.h"
#include "ui_frmmain.h"
#include "tiketwahl.h"
#include "ticketerstellen.h"
#include "stammdatenverwaltung.h"

#include <QComboBox>
#include <QRegularExpression>

namespace {

void setComboValue(QComboBox *combo, const QString &value)
{
    int index = combo->findText(value);
    if (index < 0) {
        combo->addItem(value);
        index = combo->count() - 1;
    }
    combo->setCurrentIndex(index);
}

Priority priorityFromString(const QString &text)
{
    if (text == QStringLiteral("Low"))  return Priority::Low;
    if (text == QStringLiteral("High")) return Priority::High;
    return Priority::Medium;
}

Status statusFromString(const QString &text)
{
    if (text == QStringLiteral("In Progress")) return Status::InProgress;
    if (text == QStringLiteral("Testing"))     return Status::Testing;
    if (text == QStringLiteral("Production"))   return Status::Production;
    return Status::Planning;
}

TicketType ticketTypeFromString(const QString &text)
{
    if (text == QStringLiteral("Bug")) return TicketType::Bug;
    return TicketType::Feature;
}

} // namespace

frmMain::frmMain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::frmMain)
{
    ui->setupUi(this);

    ui->centralwidget->setFocusPolicy(Qt::ClickFocus);

    ui->plainTextEditDescription->setTabChangesFocus(true);

    projects.addDefaults();
    assignees.addDefaults();
    tickets.addDummyTickets();

    refreshProjectCombo();
    refreshAssigneeCombo();

    if (!tickets.isEmpty()) {
        currentTicketIndex = 0;
        showTicket(tickets.at(0));
    }
}

frmMain::~frmMain()
{
    delete ui;
}

void frmMain::refreshProjectCombo()
{
    ui->comboProject->clear();
    ui->comboProject->addItem(QString()); // Platzhalter fuer "kein Projekt"
    ui->comboProject->addItems(projects.all());
}

void frmMain::refreshAssigneeCombo()
{
    ui->comboAssignee->clear();
    ui->comboAssignee->addItem(QString()); // Platzhalter fuer "kein Assignee"
    ui->comboAssignee->addItems(assignees.all());
}

void frmMain::showTicket(const Ticket &t)
{
    ui->lineEditName->setText(t.displayName());
    ui->plainTextEditDescription->setPlainText(t.description);

    setComboValue(ui->comboProject, t.project);
    setComboValue(ui->comboPriority, priorityToString(t.priority));
    setComboValue(ui->comboType, ticketTypeToString(t.type));
    setComboValue(ui->comboState, statusToString(t.status));
    setComboValue(ui->comboAssignee, t.assignee);
    ui->spinStoryPoints->setValue(t.storyPoints);
}

void frmMain::on_pushButtonSelectTicket_clicked()
{
    TiketWahl dialog(tickets, projects, this);
    if (dialog.exec() == QDialog::Accepted) {
        currentTicketIndex = dialog.getSelectedIndex();
        showTicket(dialog.getSelectedTicket());
    }
}

void frmMain::on_pushButtonCreateTicket_clicked()
{
    TicketErstellen dialog(tickets, this);
    if (dialog.exec() == QDialog::Accepted) {
        currentTicketIndex = dialog.getCreatedIndex();
        if (currentTicketIndex >= 0)
            showTicket(tickets.at(currentTicketIndex));
    }
}

void frmMain::on_pushButtonManageProjects_clicked()
{
    StammdatenVerwaltung dialog(projects, assignees, tickets, this);
    dialog.exec();

    refreshProjectCombo();
    refreshAssigneeCombo();

    // Falls Projekt oder Assignee des aktuell angezeigten Tickets geloescht wurden, hier
    // nachziehen, ohne die restlichen (evtl. ungespeicherten) Formularfelder anzutasten.
    if (currentTicketIndex >= 0 && currentTicketIndex < tickets.size()) {
        const Ticket &t = tickets.at(currentTicketIndex);
        setComboValue(ui->comboProject, t.project);
        setComboValue(ui->comboAssignee, t.assignee);
    }
}

void frmMain::on_pushButtonSave_clicked()
{
    if (currentTicketIndex < 0)
        return;

    Ticket t = tickets.at(currentTicketIndex);
    // Fuehrende laufende Nummer ("#1 - ") wieder entfernen, nur den Titel speichern
    QString name = ui->lineEditName->text();
    name.remove(QRegularExpression(QStringLiteral("^#\\d+ - ")));
    t.title = name;
    t.description = ui->plainTextEditDescription->toPlainText();
    t.project = ui->comboProject->currentText();
    t.priority = priorityFromString(ui->comboPriority->currentText());
    t.type = ticketTypeFromString(ui->comboType->currentText());
    t.status = statusFromString(ui->comboState->currentText());
    t.assignee = ui->comboAssignee->currentText();
    t.storyPoints = ui->spinStoryPoints->value();

    tickets.update(currentTicketIndex, t);
}

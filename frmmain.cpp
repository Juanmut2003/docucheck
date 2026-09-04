#include "frmmain.h"
#include "ui_frmmain.h"
#include "tiketwahl.h"
#include "ticketerstellen.h"
#include "stammdatenverwaltung.h"

#include <QComboBox>
#include <QFont>
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

// Wie setComboValue, aber ueber die Item-Daten statt den angezeigten Text,
// da der leere Wert dort als "None" angezeigt wird.
void setComboValueOrNone(QComboBox *combo, const QString &value)
{
    int index = combo->findData(value);
    if (index < 0) {
        combo->addItem(value, value);
        index = combo->count() - 1;
    }
    combo->setCurrentIndex(index);
}

// Item an Index 0 ("None") kursiv anzeigen, damit der Platzhalter im
// Dropdown von echten Werten unterscheidbar ist.
void markFirstItemAsNone(QComboBox *combo)
{
    QFont noneFont = combo->font();
    noneFont.setItalic(true);
    combo->setItemData(0, noneFont, Qt::FontRole);
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

    ui->formUpdate->setAlignment(ui->spinStoryPoints, Qt::AlignRight);

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
    ui->comboProject->addItem(tr("None"), QString()); // Platzhalter fuer "kein Projekt"
    for (const QString &project : projects.all())
        ui->comboProject->addItem(project, project);
    markFirstItemAsNone(ui->comboProject);
}

void frmMain::refreshAssigneeCombo()
{
    ui->comboAssignee->clear();
    ui->comboAssignee->addItem(tr("None"), QString()); // Platzhalter fuer "kein Assignee"
    for (const QString &assignee : assignees.all())
        ui->comboAssignee->addItem(assignee, assignee);
    markFirstItemAsNone(ui->comboAssignee);
}

void frmMain::showTicket(const Ticket &t)
{
    ui->lineEditName->setText(t.displayName());
    ui->plainTextEditDescription->setPlainText(t.description);

    setComboValueOrNone(ui->comboProject, t.project);
    setComboValue(ui->comboPriority, priorityToString(t.priority));
    setComboValue(ui->comboType, ticketTypeToString(t.type));
    setComboValue(ui->comboState, statusToString(t.status));
    setComboValueOrNone(ui->comboAssignee, t.assignee);
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
        setComboValueOrNone(ui->comboProject, t.project);
        setComboValueOrNone(ui->comboAssignee, t.assignee);
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
    t.project = ui->comboProject->currentData().toString();
    t.priority = priorityFromString(ui->comboPriority->currentText());
    t.type = ticketTypeFromString(ui->comboType->currentText());
    t.status = statusFromString(ui->comboState->currentText());
    t.assignee = ui->comboAssignee->currentData().toString();
    t.storyPoints = ui->spinStoryPoints->value();

    tickets.update(currentTicketIndex, t);
}

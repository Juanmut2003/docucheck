#include "frmmain.h"
#include "ui_frmmain.h"
#include "tiketwahl.h"

#include <QComboBox>

namespace {

// Selects the item with the given text, adding it first if the combo box does
// not contain it yet. Keeps the detail panel usable for values that are not
// part of the predefined list.
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

    // Let a click on the empty panel background pull focus out of the
    // description / name editors again.
    ui->centralwidget->setFocusPolicy(Qt::ClickFocus);
    // Tab moves to the next field instead of inserting a tab character.
    ui->plainTextEditBeschreibung->setTabChangesFocus(true);

    // Add a few dummy tickets right when the app opens (issue #7).
    tickets.addDummyTickets();

    // Show the first ticket right away instead of an empty panel.
    if (!tickets.isEmpty()) {
        currentTicketIndex = 0;
        showTicket(tickets.at(0));
    }
}

frmMain::~frmMain()
{
    delete ui;
}

void frmMain::showTicket(const Ticket &t)
{
    ui->lineEditName->setText(t.title);
    ui->plainTextEditBeschreibung->setPlainText(t.description);

    setComboValue(ui->comboBox_6, t.project);
    setComboValue(ui->comboBox_5, priorityToString(t.priority));
    setComboValue(ui->comboBox_4, ticketTypeToString(t.type));
    setComboValue(ui->comboBox_3, statusToString(t.status));
    setComboValue(ui->comboBox_2, t.assignee);
    ui->spinBox->setValue(t.storyPoints);
}

void frmMain::on_pushButton_2_clicked()
{
    TiketWahl dialog(tickets, this);
    if (dialog.exec() == QDialog::Accepted) {
        currentTicketIndex = dialog.getSelectedIndex();
        showTicket(dialog.getSelectedTicket());
    }
}

// "Save" button of the detail panel: persist the edited fields back into the
// shared ticket list. Nothing is written before this is clicked (issue #8).
void frmMain::on_pushButton_clicked()
{
    if (currentTicketIndex < 0)
        return;

    Ticket t = tickets.at(currentTicketIndex);
    t.title = ui->lineEditName->text();
    t.description = ui->plainTextEditBeschreibung->toPlainText();
    t.project = ui->comboBox_6->currentText();
    t.priority = priorityFromString(ui->comboBox_5->currentText());
    t.type = ticketTypeFromString(ui->comboBox_4->currentText());
    t.status = statusFromString(ui->comboBox_3->currentText());
    t.assignee = ui->comboBox_2->currentText();
    t.storyPoints = ui->spinBox->value();

    tickets.update(currentTicketIndex, t);
}

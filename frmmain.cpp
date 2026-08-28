#include "frmmain.h"
#include "ui_frmmain.h"
#include "tiketwahl.h"

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

    ui->plainTextEditBeschreibung->setTabChangesFocus(true);

    tickets.addDummyTickets();

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
    ui->lineEditName->setText(t.displayName());
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

void frmMain::on_pushButton_clicked()
{
    if (currentTicketIndex < 0)
        return;

    Ticket t = tickets.at(currentTicketIndex);
    // Fuehrende laufende Nummer ("#1 - ") wieder entfernen, nur den Titel speichern
    QString name = ui->lineEditName->text();
    name.remove(QRegularExpression(QStringLiteral("^#\\d+ - ")));
    t.title = name;
    t.description = ui->plainTextEditBeschreibung->toPlainText();
    t.project = ui->comboBox_6->currentText();
    t.priority = priorityFromString(ui->comboBox_5->currentText());
    t.type = ticketTypeFromString(ui->comboBox_4->currentText());
    t.status = statusFromString(ui->comboBox_3->currentText());
    t.assignee = ui->comboBox_2->currentText();
    t.storyPoints = ui->spinBox->value();

    tickets.update(currentTicketIndex, t);
}

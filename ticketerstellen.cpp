#include "ticketerstellen.h"
#include "ui_ticketerstellen.h"
#include <QMessageBox>

TicketErstellen::TicketErstellen(TicketList &ticketList, ProjectList &projectList, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TicketErstellen)
    , tickets(ticketList)
    , projects(projectList)
{
    ui->setupUi(this);

    ui->comboProject->addItem(tr("None"), QString()); // Platzhalter fuer "kein Projekt"
    for (const QString &project : projects.all())
        ui->comboProject->addItem(project, project);
    ui->comboProject->insertSeparator(1);

    connect(ui->pushButtonCancel, &QPushButton::clicked, this, &TicketErstellen::reject);
    connect(ui->pushButtonCreate, &QPushButton::clicked, this, &TicketErstellen::onCreateTicketClicked);
}

TicketErstellen::~TicketErstellen()
{
    delete ui;
}

int TicketErstellen::getCreatedIndex() const
{
    return createdIndex;
}

void TicketErstellen::onCreateTicketClicked()
{
    QString name = ui->lineEditName->text().trimmed();
    QString beschreibung = ui->textEditDescription->toPlainText().trimmed();

    if (name.isEmpty()) {
        QMessageBox::warning(this, "Fehler", "Bitte einen Namen für das Ticket eingeben.");
        return;
    }

    Ticket neuesTicket;
    neuesTicket.title = name;
    neuesTicket.description = beschreibung;
    neuesTicket.project = ui->comboProject->currentData().toString();

    tickets.add(neuesTicket);
    createdIndex = tickets.size() - 1;

    // Neu erstelltes Ticket direkt in der Detailansicht öffnen
    accept();
}

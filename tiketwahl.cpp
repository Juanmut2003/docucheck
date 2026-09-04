#include "tiketwahl.h"
#include "ui_tiketwahl.h"
#include <QMessageBox>
#include <QComboBox>

void TiketWahl::addTicketItem(const QString &title, int ticketIndex)
{
    QComboBox *combo = ui->comboExistingTickets;
    combo->addItem(title, ticketIndex);
    // Vollstaendigen Titel als Tooltip hinterlegen, falls die Anzeige gekuerzt wird.
    combo->setItemData(combo->count() - 1, title, Qt::ToolTipRole);
}

void TiketWahl::populateProjectCombo()
{
    QComboBox *combo = ui->comboProjectFilter;
    QStringList projects;
    for (const Ticket &t : tickets.all()) {
        if (!t.project.isEmpty() && !projects.contains(t.project))
            projects.append(t.project);
    }
    projects.sort(Qt::CaseInsensitive);

    combo->addItems(projects);
    combo->setCurrentIndex(-1); // Beim Oeffnen soll kein Projekt vorausgewaehlt sein.
}

void TiketWahl::populateTicketCombo(const QString &projectFilter)
{
    ui->comboExistingTickets->clear();

    const QList<Ticket> &all = tickets.all();
    for (int i = 0; i < all.size(); ++i) {
        if (!projectFilter.isEmpty() && all.at(i).project != projectFilter)
            continue;
        addTicketItem(all.at(i).displayName(), i);
    }
}

TiketWahl::TiketWahl(TicketList &ticketList, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TiketWahl)
    , tickets(ticketList)
{
    ui->setupUi(this);

    populateProjectCombo();
    populateTicketCombo();

    connect(ui->pushButtonOpen, &QPushButton::clicked, this, &TiketWahl::accept);
    connect(ui->pushButtonCancel, &QPushButton::clicked, this, &TiketWahl::reject);
    connect(ui->pushButtonCreate, &QPushButton::clicked, this, &TiketWahl::onCreateTicketClicked);
    connect(ui->comboProjectFilter, &QComboBox::currentIndexChanged, this, &TiketWahl::onProjectFilterChanged);
}



TiketWahl::~TiketWahl()
{
    delete ui;
}

Ticket TiketWahl::getSelectedTicket() const
{
    int index = getSelectedIndex();
    if (index >= 0)
        return tickets.at(index);
    return Ticket{};
}

int TiketWahl::getSelectedIndex() const
{
    int comboIndex = ui->comboExistingTickets->currentIndex();
    if (comboIndex < 0)
        return -1;

    bool ok = false;
    int index = ui->comboExistingTickets->currentData().toInt(&ok);
    if (!ok || index < 0 || index >= tickets.size())
        return -1;
    return index;
}

void TiketWahl::onProjectFilterChanged()
{
    int index = ui->comboProjectFilter->currentIndex();
    QString project = index >= 0 ? ui->comboProjectFilter->itemText(index) : QString();
    populateTicketCombo(project);
}

void TiketWahl::onCreateTicketClicked()
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
    if (ui->comboProjectFilter->currentIndex() >= 0)
        neuesTicket.project = ui->comboProjectFilter->currentText();

    tickets.add(neuesTicket);
    addTicketItem(tickets.at(tickets.size() - 1).displayName(), tickets.size() - 1);
    ui->comboExistingTickets->setCurrentIndex(ui->comboExistingTickets->count() - 1);

    ui->lineEditName->clear();
    ui->textEditDescription->clear();

    // Neu erstelltes Ticket direkt in der Detailansicht öffnen
    accept();
}

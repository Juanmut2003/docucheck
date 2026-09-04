#include "tiketwahl.h"
#include "ui_tiketwahl.h"
#include <QComboBox>
#include <QFont>

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
    combo->addItem(tr("All Projects"), QString()); // Platzhalter fuer "kein Filter"
    for (const QString &project : projects.all())
        combo->addItem(project, project);

    QFont allProjectsFont = combo->font();
    allProjectsFont.setBold(true);
    combo->setItemData(0, allProjectsFont, Qt::FontRole);
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

TiketWahl::TiketWahl(TicketList &ticketList, ProjectList &projectList, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TiketWahl)
    , tickets(ticketList)
    , projects(projectList)
{
    ui->setupUi(this);

    populateProjectCombo();
    populateTicketCombo();

    connect(ui->pushButtonOpen, &QPushButton::clicked, this, &TiketWahl::accept);
    connect(ui->pushButtonCancel, &QPushButton::clicked, this, &TiketWahl::reject);
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
    QString project = index >= 0 ? ui->comboProjectFilter->itemData(index).toString() : QString();
    populateTicketCombo(project);
}

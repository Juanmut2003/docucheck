#include "tiketwahl.h"
#include "ui_tiketwahl.h"
#include <QMessageBox>
#include <QComboBox>
#include <QFontMetrics>
#include <QStyle>
#include <QStyleOptionComboBox>

void TiketWahl::addTicketItem(const QString &title)
{
    QComboBox *combo = ui->comboBoxBestehendeTickets;

    // Exakte Breite des Textbereichs vom aktuellen Style erfragen
    QStyleOptionComboBox opt;
    opt.initFrom(combo);
    const QRect editRect = combo->style()->subControlRect(
        QStyle::CC_ComboBox, &opt, QStyle::SC_ComboBoxEditField, combo);
    // Der native macOS-Style zeichnet den Text mit zusaetzlichem Innenabstand,
    // daher eine groesszuegige Sicherheitsmarge abziehen.
    const int maxTextWidth = editRect.width() - 18;

    const QString shown = combo->fontMetrics().elidedText(title, Qt::ElideRight, maxTextWidth);
    combo->addItem(shown);
    combo->setItemData(combo->count() - 1, title, Qt::ToolTipRole);
}

TiketWahl::TiketWahl(TicketList &ticketList, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TiketWahl)
    , tickets(ticketList)
{
    ui->setupUi(this);

    for (const Ticket &t : tickets.all()) {
        addTicketItem(t.title);
    }

    connect(ui->pushButtonOK, &QPushButton::clicked, this, &TiketWahl::accept);
    connect(ui->pushButtonAbbrechen, &QPushButton::clicked, this, &TiketWahl::reject);
    connect(ui->pushButton, &QPushButton::clicked, this, &TiketWahl::onTicketErstellenClicked);
}



TiketWahl::~TiketWahl()
{
    delete ui;
}

Ticket TiketWahl::getSelectedTicket() const
{
    int index = ui->comboBoxBestehendeTickets->currentIndex();
    if (index >= 0 && index < tickets.size())
        return tickets.at(index);
    return Ticket{};
}
void TiketWahl::onTicketErstellenClicked()
{
    QString name = ui->lineEdit->text().trimmed();
    QString beschreibung = ui->textEdit->toPlainText().trimmed();

    if (name.isEmpty()) {
        QMessageBox::warning(this, "Fehler", "Bitte einen Namen für das Ticket eingeben.");
        return;
    }

    Ticket neuesTicket;
    neuesTicket.title = name;
    neuesTicket.description = beschreibung;

    tickets.add(neuesTicket);
    addTicketItem(neuesTicket.title);
    ui->comboBoxBestehendeTickets->setCurrentIndex(ui->comboBoxBestehendeTickets->count() - 1);

    ui->lineEdit->clear();
    ui->textEdit->clear();
}

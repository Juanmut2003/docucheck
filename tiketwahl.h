#ifndef TIKETWAHL_H
#define TIKETWAHL_H

#include <QDialog>
#include <QString>
#include <QList>

namespace Ui {
class TiketWahl;
}

struct Ticket {
    QString name;
    QString beschreibung;
};

class TiketWahl : public QDialog
{
    Q_OBJECT

public:
    explicit TiketWahl(QWidget *parent = nullptr);
    ~TiketWahl();

    Ticket getSelectedTicket() const;

private:
    void onTicketErstellenClicked();
    Ui::TiketWahl *ui;
    QList<Ticket> tickets;
};




#endif // TIKETWAHL_H

#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QMainWindow>

#include "ticketlist.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class frmMain;
}
QT_END_NAMESPACE

class frmMain : public QMainWindow
{
    Q_OBJECT

public:
    frmMain(QWidget *parent = nullptr);
    ~frmMain();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

private:
    // Fills the detail panel on the right with the given ticket's values.
    void showTicket(const Ticket &ticket);

    Ui::frmMain *ui;
    // All existing tickets, seeded with dummy tickets on start (issue #7).
    TicketList tickets;
    // Index of the ticket currently shown in the detail panel, or -1.
    int currentTicketIndex = -1;
};
#endif // FRMMAIN_H

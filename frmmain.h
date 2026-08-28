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
    void showTicket(const Ticket &ticket);

    Ui::frmMain *ui;
    TicketList tickets;
    int currentTicketIndex = -1;
};
#endif // FRMMAIN_H

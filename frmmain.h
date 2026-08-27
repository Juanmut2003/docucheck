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

private:
    Ui::frmMain *ui;
    // All existing tickets, seeded with dummy tickets on start (issue #7).
    TicketList tickets;
};
#endif // FRMMAIN_H

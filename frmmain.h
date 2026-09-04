#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QMainWindow>

#include "projectlist.h"
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
    void on_pushButtonSelectTicket_clicked();
    void on_pushButtonCreateTicket_clicked();
    void on_pushButtonManageProjects_clicked();
    void on_pushButtonSave_clicked();

private:
    void showTicket(const Ticket &ticket);
    void refreshProjectCombo();

    Ui::frmMain *ui;
    TicketList tickets;
    ProjectList projects;
    int currentTicketIndex = -1;
};
#endif // FRMMAIN_H

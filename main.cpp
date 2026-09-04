#include "frmmain.h"
#include "appstyle.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    applyModernStyle(a);

    frmMain w;
    w.show();
    return a.exec();
}

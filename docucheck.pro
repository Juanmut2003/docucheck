QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    assigneelist.cpp \
    fibonaccispinbox.cpp \
    frmmain.cpp \
    logindialog.cpp \
    projectlist.cpp \
    stammdatenverwaltung.cpp \
    ticket.cpp \
    ticketerstellen.cpp \
    ticketlist.cpp \
    tiketwahl.cpp \
    user.cpp \
    userlist.cpp

HEADERS += \
    appstyle.h \
    assigneelist.h \
    fibonaccispinbox.h \
    frmmain.h \
    logindialog.h \
    projectlist.h \
    stammdatenverwaltung.h \
    ticket.h \
    ticketerstellen.h \
    ticketlist.h \
    tiketwahl.h \
    user.h \
    userlist.h

FORMS += \
    frmmain.ui \
    logindialog.ui \
    stammdatenverwaltung.ui \
    ticketerstellen.ui \
    tiketwahl.ui

RESOURCES += \
    resources.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

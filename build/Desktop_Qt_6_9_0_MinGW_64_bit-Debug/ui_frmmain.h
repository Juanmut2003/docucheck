/********************************************************************************
** Form generated from reading UI file 'frmmain.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMMAIN_H
#define UI_FRMMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmMain
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;
    QComboBox *comboBox_5;
    QComboBox *comboBox_6;
    QFrame *line;
    QFrame *line_2;
    QLabel *label_7;
    QFrame *line_3;
    QPushButton *pushButton;
    QSpinBox *spinBox;
    QPushButton *pushButton_2;
    QLabel *labelName;
    QLabel *labelBeschreibung;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *frmMain)
    {
        if (frmMain->objectName().isEmpty())
            frmMain->setObjectName("frmMain");
        frmMain->resize(800, 600);
        centralwidget = new QWidget(frmMain);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(530, 120, 63, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(530, 160, 63, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(530, 200, 63, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(530, 250, 63, 20));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(530, 290, 63, 20));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(530, 340, 81, 20));
        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(650, 290, 111, 20));
        comboBox_3 = new QComboBox(centralwidget);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName("comboBox_3");
        comboBox_3->setGeometry(QRect(650, 250, 111, 20));
        comboBox_4 = new QComboBox(centralwidget);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName("comboBox_4");
        comboBox_4->setGeometry(QRect(650, 200, 111, 20));
        comboBox_5 = new QComboBox(centralwidget);
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->setObjectName("comboBox_5");
        comboBox_5->setGeometry(QRect(650, 160, 111, 20));
        comboBox_6 = new QComboBox(centralwidget);
        comboBox_6->addItem(QString());
        comboBox_6->addItem(QString());
        comboBox_6->addItem(QString());
        comboBox_6->addItem(QString());
        comboBox_6->setObjectName("comboBox_6");
        comboBox_6->setGeometry(QRect(650, 120, 111, 20));
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(510, 10, 20, 531));
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(520, 400, 281, 16));
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(530, 10, 141, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Tahoma")});
        font.setPointSize(12);
        font.setBold(true);
        label_7->setFont(font);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(0, 60, 801, 20));
        line_3->setFrameShape(QFrame::Shape::HLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(590, 440, 151, 71));
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(650, 340, 81, 26));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(0, 0, 131, 41));
        labelName = new QLabel(centralwidget);
        labelName->setObjectName("labelName");
        labelName->setGeometry(QRect(10, 80, 141, 61));
        labelBeschreibung = new QLabel(centralwidget);
        labelBeschreibung->setObjectName("labelBeschreibung");
        labelBeschreibung->setGeometry(QRect(190, 230, 151, 121));
        frmMain->setCentralWidget(centralwidget);
        menubar = new QMenuBar(frmMain);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        frmMain->setMenuBar(menubar);
        statusbar = new QStatusBar(frmMain);
        statusbar->setObjectName("statusbar");
        frmMain->setStatusBar(statusbar);

        retranslateUi(frmMain);

        QMetaObject::connectSlotsByName(frmMain);
    } // setupUi

    void retranslateUi(QMainWindow *frmMain)
    {
        frmMain->setWindowTitle(QCoreApplication::translate("frmMain", "frmMain", nullptr));
        label->setText(QCoreApplication::translate("frmMain", "Project", nullptr));
        label_2->setText(QCoreApplication::translate("frmMain", "Priority", nullptr));
        label_3->setText(QCoreApplication::translate("frmMain", "Type", nullptr));
        label_4->setText(QCoreApplication::translate("frmMain", "State", nullptr));
        label_5->setText(QCoreApplication::translate("frmMain", "Assignee", nullptr));
        label_6->setText(QCoreApplication::translate("frmMain", "Story Points", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("frmMain", "CR7 Juan Siuuuu", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("frmMain", "Flooor", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("frmMain", "Lionel Arian Pepsi", nullptr));

        comboBox_3->setItemText(0, QCoreApplication::translate("frmMain", "Planing", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("frmMain", "in Progress", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("frmMain", "Testing", nullptr));
        comboBox_3->setItemText(3, QCoreApplication::translate("frmMain", "Produktion", nullptr));

        comboBox_4->setItemText(0, QCoreApplication::translate("frmMain", "Feature", nullptr));
        comboBox_4->setItemText(1, QCoreApplication::translate("frmMain", "Bug", nullptr));

        comboBox_5->setItemText(0, QCoreApplication::translate("frmMain", "High", nullptr));
        comboBox_5->setItemText(1, QCoreApplication::translate("frmMain", "Medium", nullptr));
        comboBox_5->setItemText(2, QCoreApplication::translate("frmMain", "Low", nullptr));

        comboBox_6->setItemText(0, QCoreApplication::translate("frmMain", "Star Wars 10", nullptr));
        comboBox_6->setItemText(1, QCoreApplication::translate("frmMain", "Bermuda Dreieck", nullptr));
        comboBox_6->setItemText(2, QCoreApplication::translate("frmMain", "Atlantis", nullptr));
        comboBox_6->setItemText(3, QCoreApplication::translate("frmMain", "Area 51", nullptr));

        label_7->setText(QCoreApplication::translate("frmMain", "Create Tasks", nullptr));
        pushButton->setText(QCoreApplication::translate("frmMain", "Create", nullptr));
        pushButton_2->setText(QCoreApplication::translate("frmMain", "Ticket W\303\244hlen", nullptr));
        labelName->setText(QCoreApplication::translate("frmMain", "TextLabel", nullptr));
        labelBeschreibung->setText(QCoreApplication::translate("frmMain", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmMain: public Ui_frmMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMMAIN_H

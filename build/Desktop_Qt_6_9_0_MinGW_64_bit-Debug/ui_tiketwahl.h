/********************************************************************************
** Form generated from reading UI file 'tiketwahl.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIKETWAHL_H
#define UI_TIKETWAHL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_TiketWahl
{
public:
    QLabel *label;
    QComboBox *comboBoxBestehendeTickets;
    QFrame *line;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QLabel *label_5;
    QPushButton *pushButtonOK;
    QPushButton *pushButtonAbbrechen;

    void setupUi(QDialog *TiketWahl)
    {
        if (TiketWahl->objectName().isEmpty())
            TiketWahl->setObjectName("TiketWahl");
        TiketWahl->resize(402, 306);
        label = new QLabel(TiketWahl);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 60, 131, 20));
        comboBoxBestehendeTickets = new QComboBox(TiketWahl);
        comboBoxBestehendeTickets->setObjectName("comboBoxBestehendeTickets");
        comboBoxBestehendeTickets->setGeometry(QRect(150, 60, 101, 26));
        line = new QFrame(TiketWahl);
        line->setObjectName("line");
        line->setGeometry(QRect(0, 115, 401, 41));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        label_2 = new QLabel(TiketWahl);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 140, 101, 20));
        label_3 = new QLabel(TiketWahl);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 180, 63, 20));
        label_4 = new QLabel(TiketWahl);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 220, 91, 20));
        lineEdit = new QLineEdit(TiketWahl);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(200, 170, 113, 26));
        textEdit = new QTextEdit(TiketWahl);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(200, 210, 181, 87));
        pushButton = new QPushButton(TiketWahl);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 260, 111, 29));
        label_5 = new QLabel(TiketWahl);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 0, 121, 20));
        pushButtonOK = new QPushButton(TiketWahl);
        pushButtonOK->setObjectName("pushButtonOK");
        pushButtonOK->setGeometry(QRect(322, 30, 61, 29));
        pushButtonAbbrechen = new QPushButton(TiketWahl);
        pushButtonAbbrechen->setObjectName("pushButtonAbbrechen");
        pushButtonAbbrechen->setGeometry(QRect(290, 70, 93, 29));

        retranslateUi(TiketWahl);

        QMetaObject::connectSlotsByName(TiketWahl);
    } // setupUi

    void retranslateUi(QDialog *TiketWahl)
    {
        TiketWahl->setWindowTitle(QCoreApplication::translate("TiketWahl", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("TiketWahl", "Bestehende Tickets", nullptr));
        label_2->setText(QCoreApplication::translate("TiketWahl", "Ticket Erstellen", nullptr));
        label_3->setText(QCoreApplication::translate("TiketWahl", "Name", nullptr));
        label_4->setText(QCoreApplication::translate("TiketWahl", "Beschreibung", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("TiketWahl", "Name...", nullptr));
        textEdit->setPlaceholderText(QCoreApplication::translate("TiketWahl", "Beschreibung...", nullptr));
        pushButton->setText(QCoreApplication::translate("TiketWahl", "Ticket erstellen", nullptr));
        label_5->setText(QCoreApplication::translate("TiketWahl", "Ticket bearbeiten", nullptr));
        pushButtonOK->setText(QCoreApplication::translate("TiketWahl", "OK", nullptr));
        pushButtonAbbrechen->setText(QCoreApplication::translate("TiketWahl", "Abbrechen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TiketWahl: public Ui_TiketWahl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIKETWAHL_H

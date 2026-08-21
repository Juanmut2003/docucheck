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
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_TiketWahl
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QComboBox *comboBox;
    QFrame *line;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;

    void setupUi(QDialog *TiketWahl)
    {
        if (TiketWahl->objectName().isEmpty())
            TiketWahl->setObjectName("TiketWahl");
        TiketWahl->resize(400, 300);
        buttonBox = new QDialogButtonBox(TiketWahl);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(310, 50, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(TiketWahl);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 40, 131, 20));
        comboBox = new QComboBox(TiketWahl);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(150, 40, 101, 26));
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

        retranslateUi(TiketWahl);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, TiketWahl, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, TiketWahl, qOverload<>(&QDialog::reject));

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
    } // retranslateUi

};

namespace Ui {
    class TiketWahl: public Ui_TiketWahl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIKETWAHL_H

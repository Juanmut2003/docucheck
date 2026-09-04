#ifndef APPSTYLE_H
#define APPSTYLE_H

#include <QApplication>
#include <QStyleFactory>

// Zentrale Stelle fuer das Erscheinungsbild der Anwendung.
// "Fusion" als Basis-Style sorgt fuer ein einheitliches Rendering auf allen
// Plattformen, das Stylesheet legt ein modernes, helles Design darueber.
inline void applyModernStyle(QApplication &app)
{
    app.setStyle(QStyleFactory::create(QStringLiteral("Fusion")));

    static const char *kStyleSheet = R"(
    /* ---------- Grundlagen ---------- */
    QWidget {
        background-color: #FFFFFF;
        color: #1A1D26;
        font-size: 13px;
    }
    QMainWindow, QDialog { background-color: #FFFFFF; }

    /* ---------- Kopfleiste ---------- */
    #toolBar {
        background-color: #FFFFFF;
        border-bottom: 1px solid #E6E8EC;
    }

    /* ---------- Rechtes Bearbeitungs-Panel ---------- */
    #panelUpdate {
        background-color: #F8F9FB;
    }

    /* ---------- Ueberschriften / Beschriftungen ---------- */
    QLabel { background: transparent; }
    QLabel[role="section"] {
        font-size: 15px;
        font-weight: 700;
        color: #111827;
    }
    QLabel[role="field"] {
        color: #4B5563;
        font-weight: 600;
    }
    QLabel[role="hint"] { color: #6B7280; }

    /* ---------- Eingabefelder ---------- */
    QLineEdit, QPlainTextEdit, QTextEdit, QSpinBox, QComboBox {
        background-color: #FFFFFF;
        border: 1px solid #D5D8DE;
        border-radius: 8px;
        padding: 6px 10px;
        min-height: 20px;
        selection-background-color: #4F46E5;
        selection-color: #FFFFFF;
    }
    QPlainTextEdit, QTextEdit { padding: 8px 10px; }
    QLineEdit:hover, QPlainTextEdit:hover, QTextEdit:hover,
    QSpinBox:hover, QComboBox:hover { border-color: #B9BEC8; }
    QLineEdit:focus, QPlainTextEdit:focus, QTextEdit:focus,
    QSpinBox:focus, QComboBox:focus, QComboBox:on { border-color: #4F46E5; }
    QLineEdit:disabled, QPlainTextEdit:disabled, QTextEdit:disabled,
    QComboBox:disabled, QSpinBox:disabled {
        background-color: #F1F2F4;
        color: #9AA0AB;
    }

    /* ---------- ComboBox: Aufklapp-Pfeil zeichnet der Fusion-Style selbst ---------- */
    QComboBox QAbstractItemView {
        border: 1px solid #D5D8DE;
        border-radius: 8px;
        background-color: #FFFFFF;
        outline: none;
        padding: 4px;
        selection-background-color: #4F46E5;
        selection-color: #FFFFFF;
    }

    /* ---------- Buttons ---------- */
    QPushButton {
        background-color: #FFFFFF;
        border: 1px solid #D5D8DE;
        border-radius: 8px;
        padding: 7px 16px;
        color: #374151;
        font-weight: 600;
        min-height: 18px;
    }
    QPushButton:hover { background-color: #F3F4F6; }
    QPushButton:pressed { background-color: #E5E7EB; }
    QPushButton:focus { border-color: #4F46E5; }

    QPushButton#pushButtonSave,
    QPushButton#pushButtonCreate,
    QPushButton#pushButtonOpen {
        background-color: #4F46E5;
        border-color: #4F46E5;
        color: #FFFFFF;
    }
    QPushButton#pushButtonSave:hover,
    QPushButton#pushButtonCreate:hover,
    QPushButton#pushButtonOpen:hover {
        background-color: #4338CA;
        border-color: #4338CA;
    }
    QPushButton#pushButtonSave:pressed,
    QPushButton#pushButtonCreate:pressed,
    QPushButton#pushButtonOpen:pressed {
        background-color: #3730A3;
        border-color: #3730A3;
    }

    /* ---------- Trennlinien ---------- */
    QFrame[frameShape="4"], QFrame[frameShape="5"] {
        color: #E6E8EC;
        background-color: #E6E8EC;
        border: none;
    }
    QFrame[frameShape="4"] { max-height: 1px; }
    QFrame[frameShape="5"] { max-width: 1px; }

    /* ---------- Scrollbalken ---------- */
    QScrollBar:vertical { background: transparent; width: 10px; margin: 2px; }
    QScrollBar::handle:vertical {
        background: #C7CBD3; border-radius: 5px; min-height: 28px;
    }
    QScrollBar::handle:vertical:hover { background: #AEB4BF; }
    QScrollBar:horizontal { background: transparent; height: 10px; margin: 2px; }
    QScrollBar::handle:horizontal {
        background: #C7CBD3; border-radius: 5px; min-width: 28px;
    }
    QScrollBar::add-line, QScrollBar::sub-line { height: 0; width: 0; }
    QScrollBar::add-page, QScrollBar::sub-page { background: transparent; }
    )";

    app.setStyleSheet(QString::fromUtf8(kStyleSheet));
}

#endif // APPSTYLE_H

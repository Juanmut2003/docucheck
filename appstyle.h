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
    /* Seite bekommt einen sanften Grauton, damit sich die weissen Eingabefelder
       klar davon abheben (statt "weiss auf weiss"). */
    QWidget {
        background-color: #F2F3F6;
        color: #1A1D26;
        font-size: 13px;
    }
    QMainWindow, QDialog { background-color: #F2F3F6; }

    /* ---------- Kopfleiste ---------- */
    #toolBar {
        background-color: #F2F3F6;
        border-bottom: 1px solid #DDE1E7;
    }

    /* ---------- Rechtes Bearbeitungs-Panel: eine Spur dunkler als die Seite ---------- */
    #panelUpdate {
        background-color: #EAECF1;
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
        border: 1px solid #C7CCD4;
        border-radius: 8px;
        padding: 6px 10px;
        min-height: 20px;
        selection-background-color: #4F46E5;
        selection-color: #FFFFFF;
    }
    QPlainTextEdit, QTextEdit { padding: 8px 10px; }
    QComboBox { padding-right: 34px; }
    QSpinBox { padding-right: 28px; }
    QLineEdit:hover, QPlainTextEdit:hover, QTextEdit:hover,
    QSpinBox:hover, QComboBox:hover { border-color: #A6ACB8; }
    QLineEdit:focus, QPlainTextEdit:focus, QTextEdit:focus,
    QSpinBox:focus, QComboBox:focus, QComboBox:on { border-color: #4F46E5; }
    QLineEdit:disabled, QPlainTextEdit:disabled, QTextEdit:disabled,
    QComboBox:disabled, QSpinBox:disabled {
        background-color: #E9EAED;
        color: #9AA0AB;
    }

    /* ---------- ComboBox: eigenes Chevron-Icon statt des nativen Pfeils, damit
       der Aufklapp-Knopf sauber mit den runden Ecken des Feldes verschmilzt ---------- */
    QComboBox::drop-down {
        subcontrol-origin: padding;
        subcontrol-position: center right;
        width: 32px;
        border: none;
        border-left: 1px solid #E1E4E9;
        border-top-right-radius: 8px;
        border-bottom-right-radius: 8px;
        background-color: transparent;
    }
    QComboBox::drop-down:hover { background-color: #F3F4F7; }
    QComboBox::down-arrow {
        image: url(:/icons/chevron-down.png);
        width: 11px;
        height: 11px;
    }
    QComboBox::down-arrow:on { image: url(:/icons/chevron-down-active.png); }

    QComboBox QAbstractItemView {
        border: 1px solid #C7CCD4;
        border-radius: 10px;
        background-color: #FFFFFF;
        outline: none;
        padding: 6px;
    }
    QComboBox QAbstractItemView::item {
        padding: 7px 10px;
        margin: 1px 0px;
        border-radius: 6px;
        min-height: 20px;
        color: #1A1D26;
    }
    QComboBox QAbstractItemView::item:hover {
        background-color: #EEF0FF;
    }
    QComboBox QAbstractItemView::item:selected {
        background-color: #4F46E5;
        color: #FFFFFF;
    }

    /* ---------- SpinBox: gleiche Optik wie die ComboBox ---------- */
    QSpinBox::up-button {
        subcontrol-origin: border;
        subcontrol-position: top right;
        width: 24px;
        border: none;
        border-left: 1px solid #E1E4E9;
        border-top-right-radius: 8px;
        background-color: transparent;
    }
    QSpinBox::down-button {
        subcontrol-origin: border;
        subcontrol-position: bottom right;
        width: 24px;
        border: none;
        border-left: 1px solid #E1E4E9;
        border-top: 1px solid #E1E4E9;
        border-bottom-right-radius: 8px;
        background-color: transparent;
    }
    QSpinBox::up-button:hover, QSpinBox::down-button:hover { background-color: #F3F4F7; }
    QSpinBox::up-button:pressed, QSpinBox::down-button:pressed { background-color: #E7E9ED; }
    QSpinBox::up-arrow {
        image: url(:/icons/chevron-up.png);
        width: 9px;
        height: 9px;
    }
    QSpinBox::down-arrow {
        image: url(:/icons/chevron-down.png);
        width: 9px;
        height: 9px;
    }

    /* ---------- Buttons ---------- */
    QPushButton {
        background-color: #FFFFFF;
        border: 1px solid #C7CCD4;
        border-radius: 8px;
        padding: 7px 16px;
        color: #374151;
        font-weight: 600;
        min-height: 18px;
    }
    QPushButton:hover { background-color: #E7E9ED; }
    QPushButton:pressed { background-color: #DADDE3; }
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
        color: #DDE1E7;
        background-color: #DDE1E7;
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

/********************************************************************************
** Form generated from reading UI file 'counterDlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COUNTERDLG_H
#define UI_COUNTERDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ContadordeCristian
{
public:
    QPushButton *buttonPause;
    QLCDNumber *lcdNumber;
    QPushButton *buttonStart;
    QPushButton *buttonSetPeriod;
    QLineEdit *linePeriod;
    QFrame *line;
    QLineEdit *lineEdit;
    QLineEdit *lineError;
    QLineEdit *lineOk;
    QPushButton *buttonRestart;

    void setupUi(QWidget *ContadordeCristian)
    {
        if (ContadordeCristian->objectName().isEmpty())
            ContadordeCristian->setObjectName(QString::fromUtf8("ContadordeCristian"));
        ContadordeCristian->resize(532, 314);
        buttonPause = new QPushButton(ContadordeCristian);
        buttonPause->setObjectName(QString::fromUtf8("buttonPause"));
        buttonPause->setGeometry(QRect(320, 210, 181, 81));
        QFont font;
        font.setPointSize(16);
        buttonPause->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8("pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonPause->setIcon(icon);
        buttonPause->setIconSize(QSize(40, 40));
        lcdNumber = new QLCDNumber(ContadordeCristian);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(30, 50, 471, 91));
        QFont font1;
        font1.setPointSize(12);
        lcdNumber->setFont(font1);
        lcdNumber->setFrameShape(QFrame::Box);
        lcdNumber->setFrameShadow(QFrame::Plain);
        lcdNumber->setLineWidth(2);
        lcdNumber->setSmallDecimalPoint(false);
        lcdNumber->setNumDigits(6);
        lcdNumber->setDigitCount(6);
        lcdNumber->setSegmentStyle(QLCDNumber::Filled);
        buttonStart = new QPushButton(ContadordeCristian);
        buttonStart->setObjectName(QString::fromUtf8("buttonStart"));
        buttonStart->setGeometry(QRect(30, 210, 181, 81));
        buttonStart->setFont(font);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("start.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonStart->setIcon(icon1);
        buttonStart->setIconSize(QSize(40, 40));
        buttonSetPeriod = new QPushButton(ContadordeCristian);
        buttonSetPeriod->setObjectName(QString::fromUtf8("buttonSetPeriod"));
        buttonSetPeriod->setGeometry(QRect(30, 150, 131, 27));
        linePeriod = new QLineEdit(ContadordeCristian);
        linePeriod->setObjectName(QString::fromUtf8("linePeriod"));
        linePeriod->setGeometry(QRect(170, 150, 113, 27));
        linePeriod->setAlignment(Qt::AlignCenter);
        linePeriod->setDragEnabled(true);
        line = new QFrame(ContadordeCristian);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(30, 180, 471, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        lineEdit = new QLineEdit(ContadordeCristian);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(30, 10, 471, 27));
        lineEdit->setAutoFillBackground(false);
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0,0,0);"));
        lineEdit->setFrame(false);
        lineEdit->setAlignment(Qt::AlignCenter);
        lineError = new QLineEdit(ContadordeCristian);
        lineError->setObjectName(QString::fromUtf8("lineError"));
        lineError->setGeometry(QRect(330, 150, 191, 27));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        lineError->setFont(font2);
        lineError->setAutoFillBackground(false);
        lineError->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0,0,0);color: red;"));
        lineError->setFrame(false);
        lineError->setAlignment(Qt::AlignCenter);
        lineOk = new QLineEdit(ContadordeCristian);
        lineOk->setObjectName(QString::fromUtf8("lineOk"));
        lineOk->setGeometry(QRect(330, 150, 191, 27));
        lineOk->setFont(font2);
        lineOk->setAutoFillBackground(false);
        lineOk->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0,0,0);color: green;"));
        lineOk->setFrame(false);
        lineOk->setAlignment(Qt::AlignCenter);
        buttonRestart = new QPushButton(ContadordeCristian);
        buttonRestart->setObjectName(QString::fromUtf8("buttonRestart"));
        buttonRestart->setGeometry(QRect(250, 230, 41, 41));
        buttonRestart->setFont(font);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("restart.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonRestart->setIcon(icon2);
        buttonRestart->setIconSize(QSize(25, 25));

        retranslateUi(ContadordeCristian);

        QMetaObject::connectSlotsByName(ContadordeCristian);
    } // setupUi

    void retranslateUi(QWidget *ContadordeCristian)
    {
        ContadordeCristian->setWindowTitle(QApplication::translate("ContadordeCristian", "Cristian's Counter", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        buttonPause->setToolTip(QApplication::translate("ContadordeCristian", "Pause counter", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        buttonPause->setText(QApplication::translate("ContadordeCristian", " Pause", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        buttonStart->setToolTip(QApplication::translate("ContadordeCristian", "Start counting", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        buttonStart->setText(QApplication::translate("ContadordeCristian", " Start", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        buttonSetPeriod->setToolTip(QApplication::translate("ContadordeCristian", "Set period (millis)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        buttonSetPeriod->setText(QApplication::translate("ContadordeCristian", "Set period (ms)", 0, QApplication::UnicodeUTF8));
        linePeriod->setText(QApplication::translate("ContadordeCristian", "1000", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("ContadordeCristian", "Author: Cristian V\303\241zquez Cordero - Subject: Robotics.", 0, QApplication::UnicodeUTF8));
        lineError->setText(QString());
        lineOk->setText(QString());
#ifndef QT_NO_TOOLTIP
        buttonRestart->setToolTip(QApplication::translate("ContadordeCristian", "Restart counter", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        buttonRestart->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ContadordeCristian: public Ui_ContadordeCristian {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COUNTERDLG_H

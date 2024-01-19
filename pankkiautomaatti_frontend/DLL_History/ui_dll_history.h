/********************************************************************************
** Form generated from reading UI file 'dll_history.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLL_HISTORY_H
#define UI_DLL_HISTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_DLL_History
{
public:
    QPushButton *Previous;
    QPushButton *Next;
    QLineEdit *Balance;
    QPushButton *Goback;
    QLabel *label;
    QLabel *label_2;
    QTextEdit *history1;
    QLabel *label_3;
    QLineEdit *Balance2;

    void setupUi(QDialog *DLL_History)
    {
        if (DLL_History->objectName().isEmpty())
            DLL_History->setObjectName(QString::fromUtf8("DLL_History"));
        DLL_History->resize(585, 506);
        Previous = new QPushButton(DLL_History);
        Previous->setObjectName(QString::fromUtf8("Previous"));
        Previous->setGeometry(QRect(20, 360, 131, 31));
        Next = new QPushButton(DLL_History);
        Next->setObjectName(QString::fromUtf8("Next"));
        Next->setGeometry(QRect(390, 360, 141, 31));
        Balance = new QLineEdit(DLL_History);
        Balance->setObjectName(QString::fromUtf8("Balance"));
        Balance->setGeometry(QRect(50, 30, 181, 31));
        Goback = new QPushButton(DLL_History);
        Goback->setObjectName(QString::fromUtf8("Goback"));
        Goback->setGeometry(QRect(200, 360, 141, 31));
        label = new QLabel(DLL_History);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 0, 191, 31));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label_2 = new QLabel(DLL_History);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 70, 221, 31));
        QFont font1;
        font1.setPointSize(12);
        label_2->setFont(font1);
        history1 = new QTextEdit(DLL_History);
        history1->setObjectName(QString::fromUtf8("history1"));
        history1->setGeometry(QRect(20, 110, 531, 221));
        label_3 = new QLabel(DLL_History);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(290, 0, 191, 31));
        label_3->setFont(font);
        Balance2 = new QLineEdit(DLL_History);
        Balance2->setObjectName(QString::fromUtf8("Balance2"));
        Balance2->setGeometry(QRect(280, 30, 201, 31));

        retranslateUi(DLL_History);

        QMetaObject::connectSlotsByName(DLL_History);
    } // setupUi

    void retranslateUi(QDialog *DLL_History)
    {
        DLL_History->setWindowTitle(QCoreApplication::translate("DLL_History", "Dialog", nullptr));
        Previous->setText(QCoreApplication::translate("DLL_History", "PREVIOUS", nullptr));
        Next->setText(QCoreApplication::translate("DLL_History", "NEXT", nullptr));
        Goback->setText(QCoreApplication::translate("DLL_History", "GO BACK", nullptr));
        label->setText(QCoreApplication::translate("DLL_History", "Debit Balance", nullptr));
        label_2->setText(QCoreApplication::translate("DLL_History", "Account History", nullptr));
        label_3->setText(QCoreApplication::translate("DLL_History", "Credit Balance", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DLL_History: public Ui_DLL_History {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLL_HISTORY_H

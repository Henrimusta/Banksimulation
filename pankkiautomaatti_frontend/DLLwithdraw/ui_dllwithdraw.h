/********************************************************************************
** Form generated from reading UI file 'dllwithdraw.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLLWITHDRAW_H
#define UI_DLLWITHDRAW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DLLwithdraw
{
public:
    QLabel *label;
    QGroupBox *groupBox;
    QLabel *withdrawAmountLabel;
    QComboBox *comboBoxChooseAccount;
    QPushButton *button6;
    QPushButton *button9;
    QPushButton *button0;
    QPushButton *button3;
    QPushButton *button7;
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button8;
    QPushButton *button5;
    QPushButton *button4;
    QPushButton *draw20;
    QPushButton *draw40;
    QPushButton *draw100;
    QPushButton *draw200;
    QPushButton *clearButton;
    QLabel *withdrawalLineEdit;
    QFrame *line_6;
    QLabel *labelKuva;
    QFrame *line;
    QFrame *line_2;
    QLabel *labelCredit;
    QLabel *labelDebit;
    QLabel *accountBalanceLabel;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *withdrawButton;
    QPushButton *exitButton;
    QLabel *label_3;
    QLabel *errorLabel;
    QLabel *clockLabel;
    QLabel *idAccountLabel;
    QLabel *label_4;
    QLabel *debitNumberLine;
    QLabel *creditBalanceLine;
    QLabel *debitBalanceLine;
    QFrame *line_4;
    QFrame *line_5;
    QFrame *line_7;
    QFrame *line_8;

    void setupUi(QDialog *DLLwithdraw)
    {
        if (DLLwithdraw->objectName().isEmpty())
            DLLwithdraw->setObjectName(QString::fromUtf8("DLLwithdraw"));
        DLLwithdraw->resize(1275, 712);
        label = new QLabel(DLLwithdraw);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(270, 120, 121, 31));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        groupBox = new QGroupBox(DLLwithdraw);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(270, 180, 411, 461));
        QFont font1;
        font1.setPointSize(12);
        groupBox->setFont(font1);
        withdrawAmountLabel = new QLabel(groupBox);
        withdrawAmountLabel->setObjectName(QString::fromUtf8("withdrawAmountLabel"));
        withdrawAmountLabel->setGeometry(QRect(20, 80, 211, 41));
        withdrawAmountLabel->setFont(font1);
        comboBoxChooseAccount = new QComboBox(groupBox);
        comboBoxChooseAccount->addItem(QString());
        comboBoxChooseAccount->addItem(QString());
        comboBoxChooseAccount->addItem(QString());
        comboBoxChooseAccount->addItem(QString());
        comboBoxChooseAccount->addItem(QString());
        comboBoxChooseAccount->setObjectName(QString::fromUtf8("comboBoxChooseAccount"));
        comboBoxChooseAccount->setGeometry(QRect(30, 40, 361, 28));
        button6 = new QPushButton(groupBox);
        button6->setObjectName(QString::fromUtf8("button6"));
        button6->setGeometry(QRect(160, 250, 61, 61));
        button9 = new QPushButton(groupBox);
        button9->setObjectName(QString::fromUtf8("button9"));
        button9->setGeometry(QRect(160, 320, 61, 61));
        button0 = new QPushButton(groupBox);
        button0->setObjectName(QString::fromUtf8("button0"));
        button0->setGeometry(QRect(90, 390, 61, 61));
        button3 = new QPushButton(groupBox);
        button3->setObjectName(QString::fromUtf8("button3"));
        button3->setGeometry(QRect(160, 180, 61, 61));
        button7 = new QPushButton(groupBox);
        button7->setObjectName(QString::fromUtf8("button7"));
        button7->setGeometry(QRect(20, 320, 61, 61));
        button1 = new QPushButton(groupBox);
        button1->setObjectName(QString::fromUtf8("button1"));
        button1->setGeometry(QRect(20, 180, 61, 61));
        button2 = new QPushButton(groupBox);
        button2->setObjectName(QString::fromUtf8("button2"));
        button2->setGeometry(QRect(90, 180, 61, 61));
        button8 = new QPushButton(groupBox);
        button8->setObjectName(QString::fromUtf8("button8"));
        button8->setGeometry(QRect(90, 320, 61, 61));
        button5 = new QPushButton(groupBox);
        button5->setObjectName(QString::fromUtf8("button5"));
        button5->setGeometry(QRect(90, 250, 61, 61));
        button4 = new QPushButton(groupBox);
        button4->setObjectName(QString::fromUtf8("button4"));
        button4->setGeometry(QRect(20, 250, 61, 61));
        draw20 = new QPushButton(groupBox);
        draw20->setObjectName(QString::fromUtf8("draw20"));
        draw20->setGeometry(QRect(270, 210, 121, 51));
        draw40 = new QPushButton(groupBox);
        draw40->setObjectName(QString::fromUtf8("draw40"));
        draw40->setGeometry(QRect(270, 270, 121, 51));
        draw100 = new QPushButton(groupBox);
        draw100->setObjectName(QString::fromUtf8("draw100"));
        draw100->setGeometry(QRect(270, 330, 121, 51));
        draw200 = new QPushButton(groupBox);
        draw200->setObjectName(QString::fromUtf8("draw200"));
        draw200->setGeometry(QRect(270, 390, 121, 51));
        clearButton = new QPushButton(groupBox);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setGeometry(QRect(270, 110, 121, 51));
        withdrawalLineEdit = new QLabel(groupBox);
        withdrawalLineEdit->setObjectName(QString::fromUtf8("withdrawalLineEdit"));
        withdrawalLineEdit->setGeometry(QRect(30, 130, 191, 20));
        line_6 = new QFrame(groupBox);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(20, 140, 181, 20));
        line_6->setFont(font1);
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        labelKuva = new QLabel(DLLwithdraw);
        labelKuva->setObjectName(QString::fromUtf8("labelKuva"));
        labelKuva->setGeometry(QRect(270, 0, 571, 141));
        labelKuva->setScaledContents(true);
        line = new QFrame(DLLwithdraw);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(270, 160, 791, 20));
        line->setFont(font1);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(DLLwithdraw);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(700, 190, 20, 421));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        labelCredit = new QLabel(DLLwithdraw);
        labelCredit->setObjectName(QString::fromUtf8("labelCredit"));
        labelCredit->setGeometry(QRect(880, 210, 61, 21));
        labelCredit->setFont(font1);
        labelDebit = new QLabel(DLLwithdraw);
        labelDebit->setObjectName(QString::fromUtf8("labelDebit"));
        labelDebit->setGeometry(QRect(880, 250, 61, 20));
        labelDebit->setFont(font1);
        accountBalanceLabel = new QLabel(DLLwithdraw);
        accountBalanceLabel->setObjectName(QString::fromUtf8("accountBalanceLabel"));
        accountBalanceLabel->setGeometry(QRect(880, 180, 161, 20));
        accountBalanceLabel->setFont(font1);
        label_6 = new QLabel(DLLwithdraw);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(1050, 220, 21, 20));
        label_6->setFont(font1);
        label_7 = new QLabel(DLLwithdraw);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(1050, 250, 21, 20));
        label_7->setFont(font1);
        withdrawButton = new QPushButton(DLLwithdraw);
        withdrawButton->setObjectName(QString::fromUtf8("withdrawButton"));
        withdrawButton->setGeometry(QRect(760, 550, 231, 51));
        withdrawButton->setFont(font1);
        exitButton = new QPushButton(DLLwithdraw);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(760, 480, 231, 51));
        exitButton->setFont(font1);
        label_3 = new QLabel(DLLwithdraw);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(720, 180, 161, 21));
        label_3->setFont(font1);
        errorLabel = new QLabel(DLLwithdraw);
        errorLabel->setObjectName(QString::fromUtf8("errorLabel"));
        errorLabel->setGeometry(QRect(720, 310, 461, 41));
        clockLabel = new QLabel(DLLwithdraw);
        clockLabel->setObjectName(QString::fromUtf8("clockLabel"));
        clockLabel->setGeometry(QRect(720, 130, 641, 31));
        clockLabel->setFont(font);
        idAccountLabel = new QLabel(DLLwithdraw);
        idAccountLabel->setObjectName(QString::fromUtf8("idAccountLabel"));
        idAccountLabel->setGeometry(QRect(730, 280, 111, 31));
        idAccountLabel->setFont(font1);
        label_4 = new QLabel(DLLwithdraw);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(720, 250, 121, 21));
        label_4->setFont(font1);
        debitNumberLine = new QLabel(DLLwithdraw);
        debitNumberLine->setObjectName(QString::fromUtf8("debitNumberLine"));
        debitNumberLine->setGeometry(QRect(730, 210, 141, 20));
        debitNumberLine->setFont(font1);
        creditBalanceLine = new QLabel(DLLwithdraw);
        creditBalanceLine->setObjectName(QString::fromUtf8("creditBalanceLine"));
        creditBalanceLine->setGeometry(QRect(950, 210, 91, 20));
        creditBalanceLine->setFont(font1);
        debitBalanceLine = new QLabel(DLLwithdraw);
        debitBalanceLine->setObjectName(QString::fromUtf8("debitBalanceLine"));
        debitBalanceLine->setGeometry(QRect(950, 250, 91, 20));
        debitBalanceLine->setFont(font1);
        line_4 = new QFrame(DLLwithdraw);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(940, 220, 101, 20));
        line_4->setFont(font1);
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(DLLwithdraw);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(940, 260, 101, 20));
        line_5->setFont(font1);
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        line_7 = new QFrame(DLLwithdraw);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setGeometry(QRect(720, 220, 141, 20));
        line_7->setFont(font1);
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);
        line_8 = new QFrame(DLLwithdraw);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setGeometry(QRect(720, 300, 91, 20));
        line_8->setFont(font1);
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        retranslateUi(DLLwithdraw);

        QMetaObject::connectSlotsByName(DLLwithdraw);
    } // setupUi

    void retranslateUi(QDialog *DLLwithdraw)
    {
        DLLwithdraw->setWindowTitle(QCoreApplication::translate("DLLwithdraw", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DLLwithdraw", "Withdraw", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DLLwithdraw", "Choose account :", nullptr));
        withdrawAmountLabel->setText(QCoreApplication::translate("DLLwithdraw", "Withdrawal amount", nullptr));
        comboBoxChooseAccount->setItemText(0, QCoreApplication::translate("DLLwithdraw", "Choose account", nullptr));
        comboBoxChooseAccount->setItemText(1, QCoreApplication::translate("DLLwithdraw", "Withdraw Credit", nullptr));
        comboBoxChooseAccount->setItemText(2, QCoreApplication::translate("DLLwithdraw", "Withdraw Debit", nullptr));
        comboBoxChooseAccount->setItemText(3, QCoreApplication::translate("DLLwithdraw", "Transfer from Debit", nullptr));
        comboBoxChooseAccount->setItemText(4, QCoreApplication::translate("DLLwithdraw", "Transfer from Credit", nullptr));

        button6->setText(QCoreApplication::translate("DLLwithdraw", "6", nullptr));
        button9->setText(QCoreApplication::translate("DLLwithdraw", "9", nullptr));
        button0->setText(QCoreApplication::translate("DLLwithdraw", "0", nullptr));
        button3->setText(QCoreApplication::translate("DLLwithdraw", "3", nullptr));
        button7->setText(QCoreApplication::translate("DLLwithdraw", "7", nullptr));
        button1->setText(QCoreApplication::translate("DLLwithdraw", "1", nullptr));
        button2->setText(QCoreApplication::translate("DLLwithdraw", "2", nullptr));
        button8->setText(QCoreApplication::translate("DLLwithdraw", "8", nullptr));
        button5->setText(QCoreApplication::translate("DLLwithdraw", "5", nullptr));
        button4->setText(QCoreApplication::translate("DLLwithdraw", "4", nullptr));
        draw20->setText(QCoreApplication::translate("DLLwithdraw", "20 \342\202\254", nullptr));
        draw40->setText(QCoreApplication::translate("DLLwithdraw", "40 \342\202\254", nullptr));
        draw100->setText(QCoreApplication::translate("DLLwithdraw", "100 \342\202\254", nullptr));
        draw200->setText(QCoreApplication::translate("DLLwithdraw", "200 \342\202\254", nullptr));
        clearButton->setText(QCoreApplication::translate("DLLwithdraw", "Clear", nullptr));
        withdrawalLineEdit->setText(QString());
        labelKuva->setText(QString());
        labelCredit->setText(QCoreApplication::translate("DLLwithdraw", "Credit", nullptr));
        labelDebit->setText(QCoreApplication::translate("DLLwithdraw", "Debit", nullptr));
        accountBalanceLabel->setText(QCoreApplication::translate("DLLwithdraw", "Account balance", nullptr));
        label_6->setText(QCoreApplication::translate("DLLwithdraw", "\342\202\254", nullptr));
        label_7->setText(QCoreApplication::translate("DLLwithdraw", "\342\202\254", nullptr));
        withdrawButton->setText(QCoreApplication::translate("DLLwithdraw", "Proceed", nullptr));
        exitButton->setText(QCoreApplication::translate("DLLwithdraw", "Close", nullptr));
        label_3->setText(QCoreApplication::translate("DLLwithdraw", "Account number", nullptr));
        errorLabel->setText(QString());
        clockLabel->setText(QCoreApplication::translate("DLLwithdraw", "Clock:", nullptr));
        idAccountLabel->setText(QCoreApplication::translate("DLLwithdraw", "ID:", nullptr));
        label_4->setText(QCoreApplication::translate("DLLwithdraw", "Account ID", nullptr));
        debitNumberLine->setText(QString());
        creditBalanceLine->setText(QString());
        debitBalanceLine->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DLLwithdraw: public Ui_DLLwithdraw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLLWITHDRAW_H

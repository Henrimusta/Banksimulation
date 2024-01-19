/********************************************************************************
** Form generated from reading UI file 'creditwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDITWINDOW_H
#define UI_CREDITWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_creditwindow
{
public:
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *Cwithdraw;
    QPushButton *Chistory;
    QPushButton *CPoistu;

    void setupUi(QDialog *creditwindow)
    {
        if (creditwindow->objectName().isEmpty())
            creditwindow->setObjectName(QString::fromUtf8("creditwindow"));
        creditwindow->resize(1100, 746);
        label = new QLabel(creditwindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(550, 320, 161, 31));
        verticalLayoutWidget = new QWidget(creditwindow);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(550, 350, 166, 100));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Cwithdraw = new QPushButton(verticalLayoutWidget);
        Cwithdraw->setObjectName(QString::fromUtf8("Cwithdraw"));

        verticalLayout->addWidget(Cwithdraw);

        Chistory = new QPushButton(verticalLayoutWidget);
        Chistory->setObjectName(QString::fromUtf8("Chistory"));

        verticalLayout->addWidget(Chistory);

        CPoistu = new QPushButton(verticalLayoutWidget);
        CPoistu->setObjectName(QString::fromUtf8("CPoistu"));

        verticalLayout->addWidget(CPoistu);


        retranslateUi(creditwindow);

        QMetaObject::connectSlotsByName(creditwindow);
    } // setupUi

    void retranslateUi(QDialog *creditwindow)
    {
        creditwindow->setWindowTitle(QCoreApplication::translate("creditwindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("creditwindow", "Choose action", nullptr));
        Cwithdraw->setText(QCoreApplication::translate("creditwindow", "Withdraw", nullptr));
        Chistory->setText(QCoreApplication::translate("creditwindow", "History and balance", nullptr));
        CPoistu->setText(QCoreApplication::translate("creditwindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class creditwindow: public Ui_creditwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREDITWINDOW_H

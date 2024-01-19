/********************************************************************************
** Form generated from reading UI file 'debitwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEBITWINDOW_H
#define UI_DEBITWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_debitwindow
{
public:
    QLabel *label_2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *Dwithdraw;
    QPushButton *Dhistory;
    QPushButton *DPoistu;

    void setupUi(QDialog *debitwindow)
    {
        if (debitwindow->objectName().isEmpty())
            debitwindow->setObjectName(QString::fromUtf8("debitwindow"));
        debitwindow->resize(1100, 771);
        label_2 = new QLabel(debitwindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(560, 330, 161, 31));
        verticalLayoutWidget_2 = new QWidget(debitwindow);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(560, 360, 160, 100));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        Dwithdraw = new QPushButton(verticalLayoutWidget_2);
        Dwithdraw->setObjectName(QString::fromUtf8("Dwithdraw"));

        verticalLayout_2->addWidget(Dwithdraw);

        Dhistory = new QPushButton(verticalLayoutWidget_2);
        Dhistory->setObjectName(QString::fromUtf8("Dhistory"));

        verticalLayout_2->addWidget(Dhistory);

        DPoistu = new QPushButton(verticalLayoutWidget_2);
        DPoistu->setObjectName(QString::fromUtf8("DPoistu"));

        verticalLayout_2->addWidget(DPoistu);


        retranslateUi(debitwindow);

        QMetaObject::connectSlotsByName(debitwindow);
    } // setupUi

    void retranslateUi(QDialog *debitwindow)
    {
        debitwindow->setWindowTitle(QCoreApplication::translate("debitwindow", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("debitwindow", "Choose action", nullptr));
        Dwithdraw->setText(QCoreApplication::translate("debitwindow", "Withdraw", nullptr));
        Dhistory->setText(QCoreApplication::translate("debitwindow", "History and balance", nullptr));
        DPoistu->setText(QCoreApplication::translate("debitwindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class debitwindow: public Ui_debitwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBITWINDOW_H

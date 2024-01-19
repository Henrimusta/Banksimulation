/********************************************************************************
** Form generated from reading UI file 'debitorcredit.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEBITORCREDIT_H
#define UI_DEBITORCREDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_debitorcredit
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *poistu;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *debit;

    void setupUi(QDialog *debitorcredit)
    {
        if (debitorcredit->objectName().isEmpty())
            debitorcredit->setObjectName(QString::fromUtf8("debitorcredit"));
        debitorcredit->resize(1100, 772);
        verticalLayoutWidget = new QWidget(debitorcredit);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(550, 340, 161, 41));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        verticalLayoutWidget_2 = new QWidget(debitorcredit);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(550, 431, 160, 32));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        poistu = new QPushButton(verticalLayoutWidget_2);
        poistu->setObjectName(QString::fromUtf8("poistu"));

        verticalLayout_3->addWidget(poistu);

        horizontalLayoutWidget = new QWidget(debitorcredit);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(550, 381, 161, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        debit = new QPushButton(horizontalLayoutWidget);
        debit->setObjectName(QString::fromUtf8("debit"));

        horizontalLayout->addWidget(debit);


        retranslateUi(debitorcredit);

        QMetaObject::connectSlotsByName(debitorcredit);
    } // setupUi

    void retranslateUi(QDialog *debitorcredit)
    {
        debitorcredit->setWindowTitle(QCoreApplication::translate("debitorcredit", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("debitorcredit", "Do you want to proceed", nullptr));
        poistu->setText(QCoreApplication::translate("debitorcredit", "Back", nullptr));
        debit->setText(QCoreApplication::translate("debitorcredit", "Account actions", nullptr));
    } // retranslateUi

};

namespace Ui {
    class debitorcredit: public Ui_debitorcredit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBITORCREDIT_H

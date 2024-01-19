/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *txtcardNumber;
    QLineEdit *txtPin;
    QLabel *label;
    QLabel *label_2;
    QPushButton *kirjaudu;
    QLabel *info;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        txtcardNumber = new QLineEdit(centralwidget);
        txtcardNumber->setObjectName(QString::fromUtf8("txtcardNumber"));
        txtcardNumber->setGeometry(QRect(370, 100, 113, 22));
        txtPin = new QLineEdit(centralwidget);
        txtPin->setObjectName(QString::fromUtf8("txtPin"));
        txtPin->setGeometry(QRect(370, 150, 113, 22));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 100, 111, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(200, 140, 111, 21));
        kirjaudu = new QPushButton(centralwidget);
        kirjaudu->setObjectName(QString::fromUtf8("kirjaudu"));
        kirjaudu->setGeometry(QRect(370, 190, 111, 41));
        info = new QLabel(centralwidget);
        info->setObjectName(QString::fromUtf8("info"));
        info->setGeometry(QRect(210, 280, 391, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Kortti", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Pin", nullptr));
        kirjaudu->setText(QCoreApplication::translate("MainWindow", "Kirjaudu", nullptr));
        info->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

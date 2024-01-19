#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dllwithdraw.h" //Withdraw toimintoa varten

#include <QApplication>
#include <QMessageBox>
#include <QPushButton>
#include <QTableView>
#include <QLineEdit>
#include <QComboBox>
#include <QDialog>
#include <QString>
#include <QDebug>
#include <QLabel>

#include <string.h>
#include <iostream>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QObject>

#include <QNetworkRequest>  //
#include <QNetworkReply>   //

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_kirjaudu_clicked();

private:
    Ui::MainWindow *ui;
    QString cardNumber;
    DLLwithdraw * pDLLwithdraw; //Withdraw toimintoa varten
};
#endif // MAINWINDOW_H

#ifndef DLLWITHDRAW_H
#define DLLWITHDRAW_H

#include "DLLwithdraw_global.h"

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
#include <QNetworkReply>    //

#include <QDateTime>
#include <unistd.h>

namespace Ui {
class DLLWITHDRAW_EXPORT DLLwithdraw;
}

class DLLwithdraw : public QDialog
{
    Q_OBJECT

public:
    explicit DLLwithdraw(QWidget *parent = nullptr);
    ~DLLwithdraw();
    void getRestApiData(QByteArray);
    void accountNumberF();
    void creditBalanceF();
    void debitBalanceF();

    QByteArray token;
    QString debitSaldo;
    QString creditSaldo;
    QString accountNumber;
    QString idAccount;

    void SendBalance();
    void SendHistory();
    void transfer();
    void withdraw();


  signals:
     /*  void withdrawResultToEXE(QString);
       void returnWithdrawResult(QString);

       void HistoryResultToEXE(QString);
       void returnHistoryResult(QString);

       void returnTransferResult(QString);
       void transferResultToEXE(QString);*/

public slots:
     void CurrentBalance(QNetworkReply *reply);
     void withdrawSlot(QNetworkReply *reply);
    void PushHistorySlot(QNetworkReply *reply);



private slots:
    void numberClicked();
    void clearClicked();
    void close();
    //
    void updateBalanceLineEdit(int index);
    void withdraw20();
    void withdraw40();
    void withdraw100();
    void withdraw200();

    /*void sendWithdrawResult(QString result);
    void sendHistoryResult(QString result);
    void sendTransferResult(QString result);*/

     void transferSlot(QNetworkReply *reply);

private:
    Ui::DLLwithdraw *ui;
    int  withdrawAmount=0;
    short index=1;

    QDateTime datetime;

    QNetworkAccessManager *dll_withdrawManager;
    QNetworkReply *dll_withdrawReply;
    QNetworkAccessManager *dll_SaldoManager;
    QNetworkReply *dll_SaldoReply;
    QByteArray response_data;
    QByteArray response_SendData;
   // QByteArray response_HistoryData;

    QNetworkAccessManager *PushHistoryManager;
    QNetworkReply *PushHistoryReply;

    QNetworkAccessManager *withdrawManager;
    QNetworkReply *withdrawReply;

    QNetworkAccessManager *transferManager;
    QNetworkReply *transferReply;



   // void sendTransferResult(QString result);

};

#endif //  DLLWITHDRAW_H

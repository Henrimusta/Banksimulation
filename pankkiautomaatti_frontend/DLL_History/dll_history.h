#ifndef DLL_HISTORY_H
#define DLL_HISTORY_H

#include <QDialog>
#include "DLL_History_global.h"
#include <QDebug>
#include <string.h>
#include <iostream>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QObject>


using namespace std;

namespace Ui {
class DLL_HISTORY_EXPORT DLL_History;
}

class DLL_History : public QDialog
{
    Q_OBJECT

public:
    explicit DLL_History(QWidget *parent = nullptr);
    ~DLL_History();
    void getRestApiData(QByteArray);


public slots:
   void NextClickHandler();
   void PreClickHandler();

   void CurrentBalance(QNetworkReply *reply);
   void historySlot(QNetworkReply *reply);
   //void receiveUser(QByteArray);

private slots:
   void GoBackClickHandler();


private:
    Ui::DLL_History *ui;
    QNetworkAccessManager *dll_HistoryManager;
    QNetworkReply *dll_HistoryReply;
    QNetworkAccessManager *dll_SaldoManager;
    QNetworkReply *dll_SaldoReply;
    QByteArray response_data;
    QByteArray response_dataSaldo;
    QString lastDate;
    QString firstDate;
    QByteArray token;




};

#endif // DLL_HISTORY_H

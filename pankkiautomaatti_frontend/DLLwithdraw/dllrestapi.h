#ifndef DLLRESTAPI_H
#define DLLRESTAPI_H

#include "dllengine.h"

DLLRestAPI : public QObject
{
    Q_OBJECT
public:
    DLLRestAPI();
    ~DLLRestAPI();
    void login(QString cardID, QString PINCode);    //Kirjautuminen
    void lockCard(QString cardID);              //Kortin lukitseminen
    void getCustomerData(QString cardID);       //Käyttäjän tietojen hakeminen
    void getTransactions(QString cardID, QString startingPoint); //Tilitietojen hakeminen
    void withdraw(int cardID, double amount);   //Nosta rahaa

signals:
    void loginResultToEXE(QString);             //EXE:lle lähetettävät signaalit
    void customerDataToEXE(QString,QString,QString,QString);
    void transactionsToEXE(QString,QString,QString);
    void withdrawResultToEXE(QString);

private:
    dllengine *ptrEngine;

private slots:
    void sendLoginResult(QString result);   //Engineltä tulevat signaalit yhdistetään näihin slotteihin
    void sendCustomerDataResult(QString nameID, QString name, QString accNum, QString balance);    //joiden avulla lähetetään signaalit EXE:lle
    void sendTransactionResult(QString event, QString amount, QString date);
    void sendWithdrawResult(QString result);
};

#endif // DLLRESTAPI_H

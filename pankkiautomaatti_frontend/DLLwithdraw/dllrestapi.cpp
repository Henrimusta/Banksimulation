#include "dllrestapi.h"

DLLRestAPI::DLLRestAPI()
{
    ptrEngine = new dllengine;

    connect(ptrEngine, SIGNAL(returnCustomerData(QString,QString,QString,QString)),
            this, SLOT(sendCustomerDataResult(QString,QString,QString,QString)));

    connect(ptrEngine, SIGNAL(returnTransactions(QString,QString,QString)),
            this, SLOT(sendTransactionResult(QString,QString,QString)));

    connect(ptrEngine, SIGNAL(returnWithdrawResult(QString)),
            this, SLOT(sendWithdrawResult(QString)));

}

DLLRestAPI::~DLLRestAPI()
{
    delete ptrEngine;
    ptrEngine = nullptr;
}




void DLLRestAPI::getCustomerData(QString cardID)
{
    ptrEngine->getCustomerData(cardID);
}

void DLLRestAPI::getTransactions(QString cardID, QString startingPoint)
{
    ptrEngine->getTransactions(cardID,startingPoint);
}

void DLLRestAPI::withdraw(int cardID, double amount)
{
    ptrEngine->withdraw(cardID, amount);
}




/***************Signaalit EXE:lle***************/



void DLLRESTAPI::sendCustomerDataResult(QString nameID, QString name, QString accNum, QString balance)
{
    emit customerDataToEXE(nameID,name,accNum,balance);
}

void DLLRestAPI::sendTransactionResult(QString event, QString amount, QString date)
{
    emit transactionsToEXE(event,amount,date);
}

void DLLRestAPI::sendWithdrawResult(QString result)
{
    emit withdrawResultToEXE(result);
}


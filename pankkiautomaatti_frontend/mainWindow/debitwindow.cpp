#include "debitwindow.h"
#include "ui_debitwindow.h"


debitwindow::debitwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::debitwindow)
{
    ui->setupUi(this);
    connect(ui->DPoistu,SIGNAL(clicked(bool)),
            this,SLOT(debitPoistu()));
    connect(ui->Dhistory,SIGNAL(clicked(bool)),
            this,SLOT(debitHistory()));
    connect(ui->Dwithdraw,SIGNAL(clicked(bool)),
            this,SLOT(debitWithdraw()));
}

debitwindow::~debitwindow()
{
    delete ui;
}

void debitwindow::debitWithdraw()
{
    pDLLwithdraw.open();
    receiveToken4(docToken4);
}

void debitwindow::debitHistory()
{

    pDLL_History.open();
    receiveToken3(docToken2);
}

void debitwindow::debitPoistu()
{
    done(0);
}

void debitwindow::receiveToken3(QByteArray docToken)
{
    docToken2 = docToken;
    pDLL_History.getRestApiData(docToken2);
}

void debitwindow::receiveToken4(QByteArray docToken)
{
    docToken4=docToken;
    pDLLwithdraw.getRestApiData(docToken4);
    //pDLLwithdraw.getToken(docToken4);
}

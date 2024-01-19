#include "dlldebitorcredit.h"
#include "ui_dlldebitorcredit.h"
#include <QObject>
#include "debitwindow.h"
#include "creditwindow.h"

DLLDebitOrCredit::DLLDebitOrCredit(QWidget *parent) : QDialog(parent),
    ui(new Ui::DLLDebitOrCredit)
{


    ui->setupUi(this);
    pCWindow = new creditwindow(this);
    connect(ui->credit,SIGNAL(clicked(bool)),
            this,SLOT(creditOpen()));

    pDWindow = new debitwindow(this);
    connect(ui->debit,SIGNAL(clicked(bool)),
            this,SLOT(debitOpen()));


    connect(ui->poistu,SIGNAL(clicked(bool)),
            this,SLOT(exitFunc()));
}

DLLDebitOrCredit::~DLLDebitOrCredit()
{
    delete ui;
}

void DLLDebitOrCredit::creditOpen()
{
    pCWindow->open();
}

void DLLDebitOrCredit::debitOpen()
{
    pDWindow->open();
}

void DLLDebitOrCredit::exitFunc()
{
    done(0);
}

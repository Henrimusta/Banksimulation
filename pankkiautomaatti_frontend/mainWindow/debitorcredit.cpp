#include "debitorcredit.h"
#include "ui_debitorcredit.h"
#include <QObject>
#include "debitwindow.h"
//#include "creditwindow.h"

debitorcredit::debitorcredit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::debitorcredit)
{
    ui->setupUi(this);
    //pCWindow = new creditwindow(this);
    //connect(ui->credit,SIGNAL(clicked(bool)),
            //this,SLOT(creditOpen()));

    //pDWindow = debitwindow(this);
    connect(ui->debit,SIGNAL(clicked(bool)),
            this,SLOT(debitOpen()));

    connect(ui->poistu,SIGNAL(clicked(bool)),
            this,SLOT(exitFunc()));

}

debitorcredit::~debitorcredit()
{
    delete ui;
}

/*void debitorcredit::creditOpen()
{

}*/

void debitorcredit::debitOpen()
{
    pDWindow.open();
    receiveToken2(docToken);
}

void debitorcredit::exitFunc()
{
    done(0);
}

void debitorcredit::receiveToken2(QByteArray token)
{
    docToken = token;
    pDWindow.receiveToken3(docToken);
    pDWindow.receiveToken4(docToken);
}

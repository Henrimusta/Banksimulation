#include "creditwindow.h"
#include "ui_creditwindow.h"

creditwindow::creditwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::creditwindow)
{
    ui->setupUi(this);
    connect(ui->CPoistu,SIGNAL(clicked(bool)),
            this,SLOT(creditPoistu()));
    connect(ui->Chistory,SIGNAL(clicked(bool)),
            this,SLOT(creditHistory()));
}

creditwindow::~creditwindow()
{
    delete ui;
}

void creditwindow::creditWithdraw()
{

}

void creditwindow::creditHistory()
{
    pDLL_History = new DLL_History;
    pDLL_History -> open();
}

void creditwindow::creditPoistu()
{
    done(0);
}

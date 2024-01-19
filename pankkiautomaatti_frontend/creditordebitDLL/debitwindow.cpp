#include "debitwindow.h"
#include "ui_debitwindow.h"

debitwindow::debitwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::debitwindow)
{
    ui->setupUi(this);
    connect(ui->DPoistu,SIGNAL(clicked(bool)),
            this,SLOT(debitPoistu()));
}

debitwindow::~debitwindow()
{
    delete ui;
}

void debitwindow::debitWithdraw()
{

}

void debitwindow::debitHistory()
{

}

void debitwindow::debitPoistu()
{
    done(0);
}

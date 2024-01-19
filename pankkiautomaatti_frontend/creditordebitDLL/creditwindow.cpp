#include "creditwindow.h"
#include "ui_creditwindow.h"

creditwindow::creditwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::creditwindow)
{
    ui->setupUi(this);
    connect(ui->CPoistu,SIGNAL(clicked(bool)),
            this,SLOT(creditPoistu()));
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

}

void creditwindow::creditPoistu()
{
    done(0);
}

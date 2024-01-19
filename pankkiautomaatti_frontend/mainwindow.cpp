#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dllwithdraw.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     qDebug()<<"luon withdraw ikkunan";
    //Withdraw toimintoa varten
      pDLLwithdraw = new DLLwithdraw(this);
      pDLLwithdraw->show();
      qDebug()<<"näytin withdraw ikkunan";
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_kirjaudu_clicked()
{
    cardNumber=ui->txtcardNumber->text();
    QString Pin=ui->txtPin->text();
    if(QString::compare(cardNumber,"2020")==0){
        ui->info->setText("Login ok");
    }
}


#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
 pdllui =new dllui(this);
    connect (ui->login,SIGNAL(clicked(bool)),
             this,SLOT(loginF()));

    connect (ui->COD,SIGNAL(clicked(bool)),
             this,SLOT(openDOC()));

    connect (ui->quit,SIGNAL(clicked(bool)),
             this,SLOT(quitF()));

    connect (pdllui,SIGNAL(sessionAPISignal(QByteArray)),
             this,SLOT(receiveToken(QByteArray)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loginF()
{

    pdllui->show();

}

void MainWindow::quitF()
{
    close();
}

void MainWindow::openDOC()
{
    qDebug()<<"suljetaan pointteri pdllui";
    delete pdllui;
    pdllui = nullptr;
    qDebug()<<"suljettu";
    qDebug()<<"vielä ei crashaa";
    pCOD.open();
    qDebug()<<"enpäs crashannyt";

}

void MainWindow::receiveToken(QByteArray sessionToken)
{
    QByteArray token = sessionToken;

    qDebug()<<"abuser token"<<token;

    //QByteArray sessionUser= sessionToken;
     //qDebug()<<"käännetään qstringiksi"<<sessionUser;
    //pDH = new DLL_History(this);
    //pDH->getRestApiData(token);
    //emit userSignal(token);
    pCOD.receiveToken2(token);


}



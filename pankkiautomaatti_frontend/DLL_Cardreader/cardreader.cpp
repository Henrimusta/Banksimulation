#include "cardreader.h"
#include "ui_cardreader.h"
#include <QDebug>

cardReader::cardReader(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cardReader)
{
    //Connect buttons to correct signals
    ui->setupUi(this);
    connect (ui->buttonCard,SIGNAL(clicked(bool)),
             this,SLOT(handleClick()));
    connect (ui->buttonCloseCard,SIGNAL(clicked(bool)),
             this,SLOT(closeCard()));
    ptrEngine = new engine;

    connect(ptrEngine, SIGNAL(sendSignalToInterface(QString)),
            this, SLOT(receiveSignalFromEngine(QString)));
    startEngine();
}

cardReader::~cardReader()
{
    delete ptrEngine;
    ptrEngine = nullptr;
    delete ui;
}

void cardReader::startEngine()
{
    //run engine to get data from RFID reader
    ptrEngine->open();
}

void cardReader::receiveSignalFromEngine(QString n)
{
    //receive RFID data as signal
    ui->lineCardSignal->setText(n);
    qDebug()<<"signal from engine"<<n;
}

void cardReader::handleClick()
{
    //send data from rfid reader to dllUI
    QString num = ui->lineCardSignal->text();
    qDebug()<<"HandleClick num = " << num;
    emit sendCardNumber(num);

    //qDebug()<<"num after 'numtoShort'"<<num;


}

void cardReader::closeCard()
{
    //close button for cardreader.ui
    close();
}

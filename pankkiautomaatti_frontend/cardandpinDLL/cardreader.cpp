#include "cardreader.h"
#include "ui_cardreader.h"

cardReader::cardReader(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cardReader)
{
    ui->setupUi(this);
    connect (ui->buttonCard,SIGNAL(clicked(bool)),
             this,SLOT(handleClick()));
    connect (ui->buttonCloseCard,SIGNAL(clicked(bool)),
             this,SLOT(closeCard()));
    ptrEngine = new engine;

    connect(ptrEngine, SIGNAL(sendSignalToInterface(QString)),
            this, SLOT(receiveNumFromEngine(QString)));
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
    ptrEngine->open();
}

void cardReader::receiveNumFromEngine(QString cardNumber)
{
 emit sendNumToExe(cardNumber);

}

void cardReader::handleClick()
{
    QString num = ui->lineCardSignal->text();
    emit sendCardNumber(num.toShort());

}

void cardReader::closeCard()
{
    close();
}

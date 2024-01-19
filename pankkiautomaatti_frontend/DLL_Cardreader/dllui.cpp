#include "dllui.h"
#include "pin.h"
#include "ui_dllui.h"
#include "databaseconnection.h"


dllui::dllui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dllui)
{
    // connect buttons and set limit for attempts

    attempts = 3;

    ui->setupUi(this);

    ui->setupUi(this);
    connect (ui->buttonID,SIGNAL(clicked(bool)),
             this, SLOT(clickHandler()));
    updateUI();

    connect (ui->buttonCloseDLL,SIGNAL(clicked(bool)),
             this,SLOT(closeDLL()));

    connect (ui->buttonLogin,SIGNAL(clicked(bool)),
             this,SLOT(buttonLogin_clicked()));

    ui->buttonID->setText("Syötä kortti");
}

dllui::~dllui()
{
    delete ui;
}

void dllui::clickHandler()
{
    // pointer to cardReader to open cardReader for and set up for recieving data from RFID reader
    pcardReader = new cardReader(this);
    connect (pcardReader,SIGNAL(sendCardNumber(QString)),
             this, SLOT(recieveCardNumber(QString)));

    pcardReader->open();

}

void dllui::recieveCardNumber(QString num1)
{
    //recieve cardNumber, run cehckCardNumber and open pin
    cardNumber = num1;
    updateUI();
    delete pcardReader;
    pcardReader = nullptr;
    qDebug()<<"num in dllui"<<cardNumber;
    checkCardNumber();
    ppin = new pin (this);
    connect (ppin,SIGNAL(sendPinNumber(QString)),
             this,SLOT(recievePinNumber(QString)));
    ppin->open();


}

void dllui::recievePinNumber(QString num)
{
    //recieve pin number and run checkNumber
    pinNumber = num;
    updateUI();
    delete ppin;
    ppin = nullptr;
    checkNumber();
    qDebug()<<"pin code is "<<num;

}

void dllui::checkNumber()
{
    //check if pin and card match and follow ups
    updateUI();

        ui->buttonID->setText(" ");
        ui->buttonID->setText("Kortti ja pin luettu");


}

void dllui::checkCardNumber()
{
    //read card
    updateUI();

        ui->buttonID->setText(" ");
        ui->buttonID->setText("kortti tunnistettu");
        qDebug()<<cardNumber;


}

void dllui::buttonLogin_clicked()
{
    //database login
    qDebug()<<"connect to database for login";
    QString loginCardNumber=ui->lineCard->text();
    QString loginPinNumber=ui->linePIN->text();
    QJsonObject jsonObject;
    jsonObject.insert("cardNumber",loginCardNumber);
    jsonObject.insert("Pin",loginPinNumber);

    QString site_url = databaseConnection::getBaseUrl()+"/login";
    qDebug()<<site_url;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader(QByteArray("Authorization"),(token));

    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL (finished(QNetworkReply*)),
            this, SLOT(loginSlot(QNetworkReply*)));

    reply = loginManager->post(request, QJsonDocument(jsonObject).toJson());
}


void dllui::loginSlot(QNetworkReply *reply)
{
    response_data = reply->readAll();
    qDebug()<<response_data;

    if(QString::compare(response_data,"-4078")==0)
    {
            ui->yhteysInfo->setText("Virhe tietokantayhteydessä");
    }

    else
    {
        if(QString::compare(response_data,"false")!=0 && response_data.length())
        {
            ui->yhteysInfo->setText("Login Ok");
            token=response_data;
            qDebug()<<token;
            emit sessionAPISignal(token);

            qDebug()<<"erottuu"<<token;

            close();

            //pDLLDebitOrCredit = new DLLDebitOrCredit;
            //pDLLDebitOrCredit -> open();


        }

        else
        {
            ui->yhteysInfo->setText("Kortti ja Pin ei täsmää");
            //ui->lineCard->clear();
            //ui->linePIN->clear();
            attempts --;
            if (attempts>0)
            {
                updateUI();
                ui->lineCard->clear();
                ui->linePIN->clear();
            }
            else
            {
                close();
            }
        }
     }

     //qDebug()<<response_data;
     //reply->deleteLater();
     //loginManager->deleteLater();
}

void dllui::closeDLL()
{
    //close button for login DLL
    close();
}

void dllui::updateUI()
{
    //update ui bot
    ui->lineCard->setText(QString(cardNumber));
    ui->linePIN->setText(QString(pinNumber));
    ui->lineAttempts->setText(QString::number(attempts));
}






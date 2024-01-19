#include "dllui.h"
#include "pin.h"
#include "ui_dllui.h"

dllui::dllui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dllui)
{
    correctCard1 = 00626;
    correctCard2= 00620;
    correctPin1 = 4321;
    correctPin2 = 5432;
    //cardNumber = 0;
    pinNumber = 0;
    attempts = 3;

    ui->setupUi(this);

    ui->setupUi(this);
    connect (ui->buttonID,SIGNAL(clicked(bool)),
             this, SLOT(clickHandler()));
    updateUI();

    connect (ui->buttonCloseDLL,SIGNAL(clicked(bool)),
             this,SLOT(closeDLL()));
    ui->buttonID->setText("Syötä kortti");
}

dllui::~dllui()
{
    delete ui;
}

void dllui::clickHandler()
{
    pcardReader = new cardReader(this);
    connect (pcardReader,SIGNAL(sendCardNumber(short)),
             this, SLOT(recieveCardNumber(short)));
    pcardReader->open();
}

void dllui::recieveCardNumber(short num)
{
    cardNumber = num;
    updateUI();
    delete pcardReader;
    pcardReader = nullptr;
    qDebug()<<cardNumber;
    checkCardNumber(cardNumber);
    ppin = new pin (this);
    connect (ppin,SIGNAL(sendPinNumber(short)),
             this,SLOT(recievePinNumber(short)));
    ppin->open();


}

void dllui::recievePinNumber(short num)
{
    pinNumber = num;
    updateUI();
    delete ppin;
    ppin = nullptr;

    checkNumber();


}

void dllui::checkNumber()
{
    updateUI();
    if (correctPin1 == pinNumber)
    {
        ui->buttonID->setText(" ");
        ui->buttonID->setText("oikein");

    }
    else
    {
        attempts --;
        // ui->nappi->setText("pin väärin");
        if (attempts == 0)
        {
            ui->buttonID->setText(" ");
            ui->buttonID->setText("kortti lukittu");
        }
        else
        {
            ppin = new pin(this);
            connect (ppin,SIGNAL(sendPinNumber(short)),
                     this,SLOT(recievePinNumber(short)));
        }
    }
}

bool dllui::authenticate(short cardNumber){
    //TODO kopio historystä implementaatio
    QString get_card="http://localhost:3000/card/getAll"; //+SessionUser;    // Hae Osoite+SessionUser;
    QString credentials="netuser:netpass";                       //Basic authorization
    QNetworkRequest request_getAll((get_card));                            //Pyydä vastaus urlista
    request_getAll.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");  //Joku tarvittava asetus kai vielä tähän samaan.
    QByteArray data = credentials.toLocal8Bit().toBase64();         //Tarvittava muutos tuohon credentialsiin biteissä kun tuodaan se QT:n puolelle
    QString headerData = "Basic " + data;
    request_getAll.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    dll_CardManager = new QNetworkAccessManager(this);            //Luodaan olio luokasta
    connect(dll_CardManager, SIGNAL(finished (QNetworkReply*)),   //Connectataan signaali slottiin niin tulee slotin rungon ajo
    this, SLOT(historySlot(QNetworkReply*)));
    dll_CardReply = dll_CardManager->get(request_getAll);

}

void dllui::checkCardNumber(short cardNumber)
{
    updateUI();
        bool success = authenticate(cardNumber);
        if(success) {
            //TODO
            ui->buttonID->setText(" ");
            ui->buttonID->setText("kortti tunnistettu");
        }
        else {
            //TODO
            ui->buttonID->setText(" ");
            ui->buttonID->setText("korttia ei tunnistettu, syötä kortti lukijaan uudelleen");
            qDebug()<<cardNumber;
        }

        //checkNumber();
        qDebug()<<cardNumber;

}



void dllui::closeDLL()
{
    close();
}

void dllui::updateUI()
{
    ui->lineCard->setText(QString::number(cardNumber));
    ui->linePIN->setText(QString::number(pinNumber));
    ui->lineAttempts->setText(QString::number(attempts));
}

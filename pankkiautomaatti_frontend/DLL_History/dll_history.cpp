#include "dll_history.h"
#include "ui_dll_history.h"

QByteArray nwa;

DLL_History::DLL_History(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DLL_History)
{
    ui->setupUi(this);

    connect(ui->Next,SIGNAL(clicked(bool)),
            this,SLOT(NextClickHandler()));
    connect(ui->Previous,SIGNAL(clicked(bool)),
            this,SLOT(PreClickHandler()));
    connect(ui->Goback,SIGNAL(clicked(bool)),
            this,SLOT(GoBackClickHandler()));
    getRestApiData(token);
}

DLL_History::~DLL_History()
{
    delete ui;
}
void DLL_History::getRestApiData(QByteArray token)
{
    nwa = token;
    //qDebug()<<"historyn user"<<token;
    QByteArray saldoToken = token;

    QString site_url="http://localhost:3000/history/getAll";
   // qDebug() << "history/getAll= " + site_url;


    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray webToken="Bearer " + saldoToken;
    request.setRawHeader(QByteArray("Authorization"),(webToken));

    dll_HistoryManager = new QNetworkAccessManager(this);
    connect(dll_HistoryManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(historySlot(QNetworkReply*)));
    dll_HistoryReply = dll_HistoryManager->get(request);

    //Now balance data
    //qDebug()<<"saldoToken 1"<<saldoToken;
    QString site_url2="http://localhost:3000/account/1";
    //qDebug() << "account= "<<site_url2;
    //qDebug()<<"saldo token 2"<<saldoToken;
    QNetworkRequest request2((site_url2));
    request2.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray webToken2="Bearer " + saldoToken;
    //qDebug()<<"meneekö bearer tokeniin"<<webToken2;
    request2.setRawHeader(QByteArray("Authorization"),(webToken2));
    dll_SaldoManager  = new QNetworkAccessManager(this);
    connect(dll_SaldoManager , SIGNAL(finished(QNetworkReply*)),
            this, SLOT(CurrentBalance(QNetworkReply*)));
    dll_SaldoReply = dll_SaldoManager ->get(request2);

}

void DLL_History::NextClickHandler()
{

    QString get_next="http://localhost:3000/history/getNext/" + lastDate;               //Get url+SessionUser;
    QNetworkRequest request_getNext((get_next));                                        //get response from url
    request_getNext.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");  //some needed setting
    /*QString credentials="root:";                                              //Basic authorization
    QByteArray data = credentials.toLocal8Bit().toBase64();                             //Need to change credentials to bits for QT
    QString headerData = "Basic " + data;*/
    QByteArray webToken="Bearer " + nwa;
    request_getNext.setRawHeader(QByteArray("Authorization"),(webToken));
    QPushButton * button1 =qobject_cast<QPushButton*>(sender());
    //QString Next = button1->objectName();
    //qDebug() <<"Button name:" << Next;

    dll_HistoryManager = new QNetworkAccessManager(this);                               //Create object from class
    connect(dll_HistoryManager, SIGNAL(finished (QNetworkReply*)),                      //Connect signal to slot
    this, SLOT(historySlot(QNetworkReply*)));
    dll_HistoryReply = dll_HistoryManager->get(request_getNext);
}

void DLL_History::PreClickHandler()
{

    QString get_previous="http://localhost:3000/history/getPrevious/" + firstDate;          //Get url+SessionUser;
    QNetworkRequest request_getPrevious((get_previous));                                    //Get response from url
    request_getPrevious.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");  //Some needed setting
    //QString credentials="root:";                                                  //Basic authorization
    //QByteArray data = credentials.toLocal8Bit().toBase64();                                 //Need to change credentials to bits for QT
    //QString headerData = "Basic " + data;
    QByteArray webToken2="Bearer " + nwa;
    request_getPrevious.setRawHeader(QByteArray("Authorization"),(webToken2));
    QPushButton * button2 =qobject_cast<QPushButton*>(sender());
    //QString Previous = button2->objectName();
    //qDebug() <<"Button name:" << Previous;

    dll_HistoryManager = new QNetworkAccessManager(this);                                   //Create object from class
    connect(dll_HistoryManager, SIGNAL(finished (QNetworkReply*)),                          //Connect signal to slot
    this, SLOT(historySlot(QNetworkReply*)));
    dll_HistoryReply = dll_HistoryManager->get(request_getPrevious);
}

void DLL_History::GoBackClickHandler()
{
    QPushButton * button3 =qobject_cast<QPushButton*>(sender());
    //QString Goback = button3->objectName();
    //qDebug() <<"Button name:" << Goback;
    close();
}

void DLL_History::CurrentBalance(QNetworkReply *reply)
{
     response_dataSaldo=reply->readAll();                                                    //luetaan mitä osoite vastaa
            //qDebug()<<"naytasaldon responsedata" + response_dataSaldo;                       //Tulee konsoliin samoja tietoja mitä postmanissa getallpersons samoilla merkeillä
            if(response_dataSaldo.compare("-4078")==0 || response_dataSaldo.compare("")==0){      //Virhevertailu kun postman antaa virheen ja jos se data matchaa tässä konsolissa eli sama virhe niin print virhesignal
                ui->Balance->setText("Virhe tietokanta yhteydessä");
            }
            else{   //Eli jos datan tuonti onnistui...
                QJsonDocument json_doc=QJsonDocument::fromJson(response_dataSaldo);          //Muutetaan data JsonDocumentiksi
                QJsonObject json_object=json_doc.object();                              //Ja vielä kerran muutetaan Json Arrayksi tuo aiempi koska tulee monta objektia eikä vain yksi
                QString saldo;
                QString credit;                                                         //Luodaan QString muuttuja.
                saldo=QString::number(json_object["DebitBalance"].toDouble());
                credit=QString::number(json_object["CreditBalance"].toDouble());
                ui->Balance->setText(saldo + "€");                                       //Laitetaan ui widgettiin se persons muuttujan rivi tietoja.
                   //qDebug()<<"saahaanko saldoa"<<saldo;
                ui->Balance2->setText(credit + "€");                                     //Laitetaan ui widgettiin se persons muuttujan rivi tietoja.
                   //qDebug()<<"saahaanko creditsaldoa"<<credit;

}
}

void DLL_History::historySlot(QNetworkReply * reply)
{
   QByteArray response_data=reply->readAll();          //luetaan mitä osoite vastaa
           //qDebug()<<response_data;                            //Tulee konsoliin samoja tietoja mitä postmanissa getallHistory samoilla merkeillä
           if(response_data.compare("-4078")==0 || response_data.compare("")==0){  //Virhevertailu kun postman antaa virheen ja jos se data matchaa tässä konsolissa eli sama virhe niin print virhesignal
               ui->history1->setText("Virhe tietokanta yhteydessä");
           }
           else{   //Eli jos datan tuonti onnistui...
               QJsonDocument json_doc=QJsonDocument::fromJson(response_data);  //Muutetaan data JsonDocumentiksi
               QJsonArray json_array=json_doc.array();          //Ja vielä kerran muutetaan Json Arrayksi tuo aiempi koska tulee monta objektia eikä vain yksi
               QString tilitapahtumat;            //Luodaan QString muuttuja.

               QJsonValue firstObject = json_array.first(); // First data from the list
               QJsonValue lastObject = json_array.last(); // Last data from the list

               if(!lastObject.isUndefined() && !lastObject.isUndefined()){
                    lastDate=lastObject["Date"].toString(); // Last date from the last object
                    firstDate=firstObject["Date"].toString(); // first date from the first object
               } else {
                   firstDate = lastDate;
                   //qDebug()<< "Change first to previous last";
               }

               //qDebug()<< "FIRST: "<< firstObject["Date"];
               //qDebug()<< "LAST: "<< lastObject["Date"];



               foreach(const QJsonValue &value, json_array){       //Käydään läpi jokainen value sieltä ja muutetaan ne uusiin tietomuotoihin jotka liitetään sitten persons muuttujaan että persons tulostaa nämä haluamat tiedot.
                   QJsonObject json_obj=value.toObject();
                  tilitapahtumat+=json_obj["Date"].toString()+
                   "\t"+QString::number((json_obj["Amount"].toDouble()))+"€"+"\r";
               }
               ui->history1->setText(tilitapahtumat);  //Laitetaan ui widgettiin se persons muuttujan rivi tietoja.
           }

           dll_HistoryReply->deleteLater();
           reply->deleteLater();                           //Deletelater toiminto tässä jostain syystä? Poistaa sitten kai kun on tämä toiminto suoritettu kokonaan
           dll_HistoryManager->deleteLater();
}

/*void DLL_History::receiveUser(QByteArray u)
{
    token = u;
    qDebug()<<"historyn user"<<token;

    QString site_url="http://localhost:3000/history/getAll";
        qDebug() << "RESTAPIDLL::getAsiakas = " + site_url;



        QNetworkRequest request((site_url));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        QByteArray webToken="Bearer " + token;
        request.setRawHeader(QByteArray("Authorization"),(webToken));



        dll_HistoryManager = new QNetworkAccessManager(this);
        connect(dll_HistoryManager, SIGNAL(finished(QNetworkReply*)),
                this, SLOT(historySlot(QNetworkReply*)));
        dll_HistoryReply = dll_HistoryManager->get(request);*/




#ifndef DLLUI_H
#define DLLUI_H

#include <QDialog>
#include "DLLui_global.h"
#include "cardreader.h"
#include "pin.h"
#include "engine.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QObject>
#include <iostream>
namespace Ui {
class DLLUI_EXPORT dllui;
}

class dllui : public QDialog
{
    Q_OBJECT

public:
    explicit dllui(QWidget *parent = nullptr);
    ~dllui();

private slots:
    void clickHandler();
    void recieveCardNumber(short);
    void recievePinNumber(short);
    void checkNumber();
    void checkCardNumber(short cardNumber);
    void closeDLL();
    bool authenticate(short cardNumber);


private:
    Ui::dllui *ui;
    cardReader *pcardReader;
    pin *ppin;
    void updateUI();
    short pinNumber, attempts, correctPin1, correctPin2;
    short correctCard1, correctCard2, cardNumber;
    QNetworkAccessManager *dll_CardManager;
    QNetworkReply *dll_CardReply;


};

#endif // DLLUI_H

#ifndef DLLUI_H
#define DLLUI_H

#include <QDialog>
#include "DLLui_global.h"
#include "cardreader.h"
#include "pin.h"

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QtNetwork>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonObject>


namespace Ui {
class DLLUI_EXPORT dllui;
}

class dllui : public QDialog
{
    Q_OBJECT

public:
    dllui(QWidget *parent = nullptr);
    ~dllui();
    QByteArray token;

private slots:
    void clickHandler();
    void recieveCardNumber(QString);
    void recievePinNumber(QString);
    void checkNumber();
    void checkCardNumber();
    void loginSlot(QNetworkReply *reply);
    void closeDLL();
    void buttonLogin_clicked();

signals:
    void sessionAPISignal(QByteArray);

private:
    Ui::dllui *ui;
    cardReader *pcardReader;
    pin *ppin;
    void updateUI();
    short attempts;
    QString cardNumber;
    QString pinNumber;
    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QByteArray response_data;

};

#endif // DLLUI_H

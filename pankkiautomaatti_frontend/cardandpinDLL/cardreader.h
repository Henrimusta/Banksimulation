#ifndef CARDREADER_H
#define CARDREADER_H

#include <QDialog>
#include <QDebug>
#include "engine.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QString>
#include <QList>

namespace Ui {
class cardReader;
}

class cardReader : public QDialog
{
    Q_OBJECT

public:
    explicit cardReader(QWidget *parent = nullptr);
    ~cardReader();
    void startEngine();
    QString cardNumber;
public slots:
    void receiveNumFromEngine(QString);
signals:
    void sendCardNumber(short);
    void sendInfoToExe(QString);
    void sendNumToExe(QString);
private slots:
    void handleClick();
    void closeCard();

private:
    Ui::cardReader *ui;
    engine * ptrEngine;
};

#endif // CARDREADER_H

#include "engine.h"

engine::engine(QObject *parent):QObject(parent)
{
    //set up serialport for RFID reader
    pQSerialPort = new QSerialPort;
    connect(pQSerialPort, SIGNAL(readyRead()),
            this, SLOT(readPort()));

}

engine::~engine()
{
    delete pQSerialPort;
    pQSerialPort = nullptr;

}

void engine::open()
{
    //open RFID reader
    pQSerialPort->setPortName("/dev/tty.usbmodem1401");
    qDebug() << pQSerialPort->portName();
    pQSerialPort->setBaudRate(QSerialPort::Baud9600);
    pQSerialPort->setDataBits(QSerialPort::Data8);
    pQSerialPort->setParity(QSerialPort::NoParity);
    pQSerialPort->setStopBits(QSerialPort::OneStop);
    pQSerialPort->setFlowControl(QSerialPort::HardwareControl);

    if (!pQSerialPort->open(QIODevice::ReadWrite))
    {
        qDebug() << "ei aukea" << Qt::endl;
    }
    else
    {
        qDebug() << "portti aukesi" << Qt::endl;

    }
       //qDebug()<<"suljetaan lopuksi";
       //pQSerialPort->close();
}

void engine::readPort()
{
    //read data from serialport and simplify data recieved, send data
    number = pQSerialPort->readAll();
    number.remove(0,8);
    number.chop(5);
    qDebug()<<"engine reads"<<number;
    emit sendSignalToInterface(number);
}

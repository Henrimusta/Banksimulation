#ifndef PIN_H
#define PIN_H

#include <QDialog>
#include <QSerialPort>
#include <QSerialPortInfo>

namespace Ui {
class pin;
}

class pin : public QDialog
{
    Q_OBJECT

public:
    explicit pin(QWidget *parent = nullptr);
    ~pin();
signals:
        void sendPinNumber(QString);
private slots:
        void handleClickPIN();
        void closePIN();
        void buttonHandle();
        void buttonBack();
        void buttonClear();


private:
    Ui::pin *ui;
};

#endif // PIN_H

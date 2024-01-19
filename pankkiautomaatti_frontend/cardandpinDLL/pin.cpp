#include "pin.h"
#include "ui_pin.h"

pin::pin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pin)
{
    ui->setupUi(this);
    connect (ui->buttonPin,SIGNAL(clicked(bool)),
             this,SLOT(handleClickPIN()));
    connect (ui->buttonClosePin,SIGNAL(clicked(bool)),
             this,SLOT(closePIN()));
    // numpad control keys
    connect (ui->buttonBackspace,SIGNAL(clicked(bool)),
             this,SLOT(buttonBack()));
    connect (ui->buttonClear,SIGNAL(clicked(bool)),
             this,SLOT(buttonClear()));
    //numpad connection
    // connect all the number buttons to the same slot
    for (int i = 0; i <= 9; i++) {
        // create the object name for the button dynamically
        QString pushButton = "buttonNum" + QString::number(i);
        // connect the button to the slot
        connect(findChild<QPushButton*>(pushButton), &QPushButton::clicked, this, &pin::buttonHandle);
    }
}

pin::~pin()
{
    delete ui;
}

void pin::handleClickPIN()
{
    QString num = ui->linePinSignal->text();
    emit sendPinNumber(num.toShort());

}

void pin::closePIN()
{
    close();
}

void pin::buttonHandle()
{
    QPushButton* buttonNum = qobject_cast<QPushButton*>(sender());
    if (buttonNum) {
        QString digit = buttonNum->text();
        ui->linePinSignal->setText(ui->linePinSignal->text() + digit);
    }
}

void pin::buttonBack()
{
    QString text = ui->linePinSignal->text();
    text.chop(1);
    ui->linePinSignal->setText(text);
}

void pin::buttonClear()
{

    ui->linePinSignal->setText("");
}

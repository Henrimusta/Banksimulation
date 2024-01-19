#include "numpad.h"
#include "ui_numpad.h"

numPad::numPad(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::numPad)
{
    ui->setupUi(this);


    // Connect numpad buttons to numpadClicked slot
       for (int i = 0; i <= 9; ++i) {
           QString buttonName = "button" + QString::number(i);
           QPushButton* button = findChild<QPushButton*>(buttonName);
           connect(button, &QPushButton::clicked, this, &numPad::numberClicked);
    }


    //connect(ui->cancelButton, &QPushButton::clicked, this, &numPad::cancel);
    connect (ui->cancelButton,SIGNAL(clicked(bool)),
            this,SLOT(cancel()));

    //connect(ui->enterButton, &QPushButton::clicked, this, &numPad::enter);
    connect (ui->enterButton,SIGNAL(clicked(bool)),
            this,SLOT(enter()));

    connect (ui->cancelButton,SIGNAL(clicked(bool)),
            this,SLOT(cancel()));

    connect (ui->clearButton,SIGNAL(clicked(bool)),
            this,SLOT(clear2()));

}



numPad::~numPad()
{
    delete ui;
}

void numPad::enter()
{

}

void numPad::cancel()
{

}

void numPad::clear2()
{
        ui->difAmountLineEdit->clear();
}

void numPad::numberClicked()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
        if (button) {
            QString digit = button->text();
            ui->difAmountLineEdit->setText(ui->difAmountLineEdit->text() + digit);
        }
}

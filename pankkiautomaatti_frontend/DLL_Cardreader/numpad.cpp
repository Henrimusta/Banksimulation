#include "numpad.h"
#include "ui_numpad.h"

numPad::numPad(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::numPad)
{
    ui->setupUi(this);
}

numPad::~numPad()
{
    delete ui;
}

#ifndef NUMPAD_H
#define NUMPAD_H

#include <QDialog>

namespace Ui {
class numPad;
}

class numPad : public QDialog
{
    Q_OBJECT

public:
    explicit numPad(QWidget *parent = nullptr);
    ~numPad();

private:
    Ui::numPad *ui;
};

#endif // NUMPAD_H

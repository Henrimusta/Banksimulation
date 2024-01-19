#ifndef DEBITWINDOW_H
#define DEBITWINDOW_H

#include "dll_history.h"
#include "dllwithdraw.h"
#include <QDialog>

namespace Ui {
class debitwindow;
}

class debitwindow : public QDialog
{
    Q_OBJECT

public:
    explicit debitwindow(QWidget *parent = nullptr);
    ~debitwindow();

public slots:
    void debitWithdraw();
    void debitHistory();
    void debitPoistu();
    void receiveToken3(QByteArray);
    void receiveToken4(QByteArray);


signals:

private:
    Ui::debitwindow *ui;
    DLL_History pDLL_History;
    QByteArray docToken2;
    QByteArray docToken4;
    DLLwithdraw pDLLwithdraw;
};

#endif // DEBITWINDOW_H

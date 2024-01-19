#ifndef DEBITORCREDIT_H
#define DEBITORCREDIT_H

#include "debitwindow.h"
#include "creditwindow.h"
#include <QDialog>

namespace Ui {
class debitorcredit;
}

class debitorcredit : public QDialog
{
    Q_OBJECT

public:
    explicit debitorcredit(QWidget *parent = nullptr);
    ~debitorcredit();

public slots:
    //void creditOpen();
    void debitOpen();
    void exitFunc();
    void receiveToken2(QByteArray);

private:
    Ui::debitorcredit *ui;
    debitwindow pDWindow;
   // creditwindow pCWindow;
    QByteArray docToken;
    //debitorcredit *pDOC;
};

#endif // DEBITORCREDIT_H

#ifndef DLLDEBITORCREDIT_H
#define DLLDEBITORCREDIT_H
#include "debitwindow.h"
#include "creditwindow.h"
#include <QDialog>

namespace Ui {
class DLLDebitOrCredit;
}

class DLLDebitOrCredit : public QDialog
{
    Q_OBJECT

public:
    explicit DLLDebitOrCredit(QWidget *parent = nullptr);
    ~DLLDebitOrCredit();



public slots:
    void creditOpen();
    void debitOpen();
    void exitFunc();


signals:

private:
    Ui::DLLDebitOrCredit *ui;

    debitwindow * pDWindow;
    creditwindow * pCWindow;
};

#endif // DLLDEBITORCREDIT_H

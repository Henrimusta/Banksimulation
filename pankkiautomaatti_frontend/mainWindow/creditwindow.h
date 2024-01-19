#ifndef CREDITWINDOW_H
#define CREDITWINDOW_H

#include "dll_history.h"
#include <QDialog>

namespace Ui {
class creditwindow;
}

class creditwindow : public QDialog
{
    Q_OBJECT

public:
    explicit creditwindow(QWidget *parent = nullptr);
    ~creditwindow();
public slots:
    void creditWithdraw();
    void creditHistory();
    void creditPoistu();

private:
    Ui::creditwindow *ui;
    DLL_History *pDLL_History;
};

#endif // CREDITWINDOW_H

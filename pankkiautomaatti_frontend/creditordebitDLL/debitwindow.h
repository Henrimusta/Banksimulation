#ifndef DEBITWINDOW_H
#define DEBITWINDOW_H

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

signals:

private:
    Ui::debitwindow *ui;


};

#endif // DEBITWINDOW_H

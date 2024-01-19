#ifndef CREDITWINDOW_H
#define CREDITWINDOW_H

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

signals:

private:
    Ui::creditwindow *ui;

};

#endif // CREDITWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "dllui.h"
#include "dll_history.h"
#include "debitorcredit.h"
//#include "dlldebitorcredit.h"



#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QByteArray token;

private slots:
    void loginF();
    void quitF();
    void openDOC();
    void receiveToken(QByteArray);

signals:
    void userSignal(QByteArray);

private:
    Ui::MainWindow *ui;
    dllui *pdllui;
    QByteArray sessionToken;
    QString sessionUser;
    DLL_History *pDH;
    debitorcredit pCOD;

    //DLLDebitOrCredit *pDOC;



};
#endif // MAINWINDOW_H

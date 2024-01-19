#include "dllwithdraw.h"
#include "ui_dllwithdraw.h"


DLLwithdraw::DLLwithdraw(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DLLwithdraw)
{
    ui->setupUi(this);

    this->setWindowTitle("Withdraw");

    //connect all the number buttons to the same slot with findChild
    for (int i = 0; i <= 9; i++) {
       //  create the object name for the button dynamically
        QString pushButton = "button" + QString::number(i);
      //   connect the button to the slot
        connect(findChild<QPushButton*>(pushButton), &QPushButton::clicked, this, &DLLwithdraw::numberClicked);
    }
     //UI with separate hotkeys 20€-200€
     connect(ui->draw20, &QPushButton::clicked, this, &DLLwithdraw::withdraw20);
     connect(ui->draw40, &QPushButton::clicked, this, &DLLwithdraw::withdraw40);
     connect(ui->draw100, &QPushButton::clicked, this, &DLLwithdraw::withdraw100);
     connect(ui->draw200, &QPushButton::clicked, this, &DLLwithdraw::withdraw200);

    // connect withdraw button to withdraw slot
    connect(ui->withdrawButton, &QPushButton::clicked, this, &DLLwithdraw::withdraw);
    connect(ui->exitButton, &QPushButton::clicked, this, &DLLwithdraw::close);
    connect(ui->clearButton, &QPushButton::clicked, this, &DLLwithdraw::clearClicked);
    //connect(ui->transferButton, &QPushButton::clicked, this, &DLLwithdraw::transferButtonClicked);

    //Show updated balance
    connect(ui->comboBoxChooseAccount, SIGNAL(currentIndexChanged(int)), this, SLOT(updateBalanceLineEdit(int)));

    getRestApiData();
}

DLLwithdraw::~DLLwithdraw()
{
    delete ui;
    delete dll_withdrawReply;
    delete dll_withdrawManager;
    delete dll_SaldoManager;
    delete dll_SaldoReply;
    delete PushHistoryReply;
    delete PushHistoryManager;
    delete withdrawManager;
    delete withdrawReply;
    delete transferManager;
    delete transferReply;
}


void DLLwithdraw::getRestApiData()
{
    //Connect
    QString get_all="http://localhost:3000/account/1"; //+SessionUser;    // Get address+SessionUser;
    QString credentials="netuser:netpass";                       //Basic authorization
    QNetworkRequest request_getAll((get_all));                            //Ask answer from URL
    request_getAll.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();         //The necessary change to that credentials in the bits when bringing it to the QT side
    QString headerData = "Basic " + data;
    request_getAll.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    dll_withdrawManager = new QNetworkAccessManager(this);            //Creating object from class
    connect(dll_withdrawManager, SIGNAL(finished (QNetworkReply*)),   //Connecting signal to slot so it will run body
    this, SLOT(CurrentBalance(QNetworkReply*)));
    dll_withdrawReply = dll_withdrawManager->get(request_getAll);


    //Balance
    qDebug()<<"Balance start";
    QString site_url2="http://localhost:3000/account/1"; // +SessionUser;    //get address
    QString credentials2="netuser:netpass";                       //Basic authorization
    QNetworkRequest request2((site_url2));                            //Ask ans from url
    request2.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data2 = credentials2.toLocal8Bit().toBase64();          //The necessary change to that credentials in the bits when bringing it to the QT side
    QString headerData2 = "Basic " + data2;
    request2.setRawHeader( "Authorization", headerData2.toLocal8Bit() );
    dll_SaldoManager = new QNetworkAccessManager(this);            //Creating object from class
    connect(dll_SaldoManager, SIGNAL(finished (QNetworkReply*)),   //Connecting signal to slot so it will run body
    this, SLOT(CurrentBalance(QNetworkReply*)));
    dll_SaldoReply = dll_SaldoManager->get(request2);
    qDebug()<<"Balance end";

}


//Balance
void DLLwithdraw::CurrentBalance(QNetworkReply *reply)
{
     response_data=reply->readAll();          //reads what address says
            qDebug()<<"show balance responsedata" + response_data;                            //This will print all what postman will print
            if(response_data.compare("-4078")==0 || response_data.compare("")==0){  //Error comparison when postman gives an error and if that data matches in this console if same error then print error signal
                ui->errorLabel->setText("Virhe tietokanta yhteydessä");
            }
            else{   //If data pull succeed, then...
                QJsonDocument json_doc=QJsonDocument::fromJson(response_data);  //Changing data JsonDocumentiksi
                QJsonObject json_object=json_doc.object();          //And once again change the previous one to Json Array because there will be many objects and not just one
                debitSaldo=QString::number(json_object["DebitBalance"].toInt());
                creditSaldo=QString::number(json_object["CreditBalance"].toInt());
                accountNumber=QString::number(json_object["AccountNumber"].toInt());
                idAccount=QString::number(json_object["idAccount"].toInt());

                ui->debitNumberLine->setText(accountNumber);
                ui->creditBalanceLine->setText(creditSaldo + "€");
                ui->debitBalanceLine->setText(debitSaldo + "€");
                ui->idAccountLabel->setText(idAccount);
              //Let's put in the ui widget it persons variable row data.
                qDebug()<< "currentbalancen lopussa"<<debitSaldo;
                qDebug()<<"currentbalancen lopussa"<<creditSaldo;
            }
}


//At these points, the debit and credit account will be displayed, from which the withdrawal will then be made in comboBox
void DLLwithdraw::updateBalanceLineEdit(int index)
{
   if(index == 1) // Credit Balance
   {
       ui->creditBalanceLine->setEnabled(true);
       ui->debitBalanceLine->setEnabled(false);

       accountNumberF();
       creditBalanceF();
       debitBalanceF();
   }
   else if(index == 2) //debit balance
   {
       ui->creditBalanceLine->setEnabled(false);
       ui->debitBalanceLine->setEnabled(true);

       accountNumberF();
       debitBalanceF();
       creditBalanceF();
   }
   else if(index == 3) //Transfer debit to credit
   {
       ui->creditBalanceLine->setEnabled(true);
       ui->debitBalanceLine->setEnabled(true);

       accountNumberF();
       debitBalanceF();
       creditBalanceF();
   }
   else if(index == 4)
{
       ui->creditBalanceLine->setEnabled(true);
       ui->debitBalanceLine->setEnabled(true);

       accountNumberF();
       debitBalanceF();
       creditBalanceF();
   }
}

void DLLwithdraw::withdraw()
{
    // Get the withdrawal amount from the withdrawalLineEdit
    QString withdrawalStr = ui->withdrawalLineEdit->text();
    bool ok;
    int withdrawal = withdrawalStr.toInt(&ok);

    if(ui->comboBoxChooseAccount->currentIndex() == 0)
       {
           QMessageBox::warning(this, "No account selected", "Please select an account.");
           return;
       }

    // Validate the withdrawal amount
    if (!ok || withdrawal <= 0)
    {
        // Error if the input is not a valid withdrawal amount
        QMessageBox::warning(this, "Invalid withdrawal amount", "Please enter a valid withdrawal amount.");
        return;
    }

    if (withdrawal % 20 != 0 && withdrawal % 50 != 0 && withdrawal % 100 != 0 && withdrawal % 200 != 0 && withdrawal % 500 != 0)
    {
        // Error if the withdrawal amount is not divisible by 20, 50, 100, 200 or 500
        QMessageBox::warning(this, "Invalid withdrawal amount", "Please enter a withdrawal amount that is divisible by 20, 50, 100, 200 or 500.");
        return;
    }

    if (ui->comboBoxChooseAccount->currentIndex() == 1) // Credit Balance
    {
        int creditBalance = ui->creditBalanceLine->text().toInt();
        int debitBalance = ui->debitBalanceLine->text().toInt();
        int accountNumber = ui->debitNumberLine->text().toInt();
        if (withdrawal > creditBalance)
        {
            // Error if the withdrawal amount is greater than the credit balance
            QMessageBox::warning(this, "Insufficient funds", "You do not have enough funds to withdraw that amount.");
            return;
        }
        creditBalance -= withdrawal;

        ui->debitBalanceLine->setText(QString::number(debitBalance));
        ui->creditBalanceLine->setText(QString::number(creditBalance));
        ui->debitNumberLine->setText(QString::number(accountNumber));
        qDebug()<<"withdraw lopussa"<<creditBalance;

        QMessageBox::warning(this, "Withdrawal successful", QString("You have withdrawn %1 from your Credit account.").arg(withdrawal));

        SendBalance();
        SendHistory();

    }
    else if (ui->comboBoxChooseAccount->currentIndex() == 2) // Debit Balance
    {
        int debitBalance = ui->debitBalanceLine->text().toInt();
         int creditBalance = ui->creditBalanceLine->text().toInt();
        int accountNumber = ui->debitNumberLine->text().toInt();

        if (withdrawal > debitBalance)
        {
            // Error if the withdrawal amount is greater than the debit balance
            QMessageBox::warning(this, "Insufficient funds", "You do not have enough funds to withdraw that amount.");
            return;
        }
        debitBalance -= withdrawal;
        ui->debitBalanceLine->setText(QString::number(debitBalance));
        ui->creditBalanceLine->setText(QString::number(creditBalance));
        ui->debitNumberLine->setText(QString::number(accountNumber));

        qDebug()<<"Withdraw lopussa"<<debitBalance;
        qDebug()<<"Withdraw lopussa"<<creditBalance;
        qDebug()<<"Withdraw lopussa"<<accountNumber;

        QMessageBox::warning(this, "Withdrawal successful", QString("You have withdrawn %1 from your Debit account.").arg(withdrawal));

        SendBalance();
        SendHistory();

    }


    else if (ui->comboBoxChooseAccount->currentIndex() == 3) // Transfer from debit
    {
        int transferAccount = ui->debitBalanceLine->text().toInt();
        int receiveAccount = ui->creditBalanceLine->text().toInt();
        int transferAccountNumber = ui->debitNumberLine->text().toInt();

        if (withdrawal > transferAccount)
        {
            // Error if the withdrawal amount is greater than the debit balance
            QMessageBox::warning(this, "Insufficient funds", "You do not have enough funds to withdraw that amount.");
            return;
        }
            QMessageBox confirmation;
            confirmation.setText(tr("Do you want to proceed?"));
            QAbstractButton *pButtonYes = confirmation.addButton(tr("Kyllä"), QMessageBox::YesRole);
            confirmation.addButton(tr("Peruuta"), QMessageBox::NoRole);
            confirmation.exec();
            if(confirmation.clickedButton() == pButtonYes)
            {
                // Lets add the calculations here
                int transferDebitBalance = transferAccount - withdrawal;
                int transferCreditBalance = receiveAccount + withdrawal;
                ui->debitBalanceLine->setText(QString::number(transferDebitBalance));
                ui->creditBalanceLine->setText(QString::number(transferCreditBalance));
                ui->debitNumberLine->setText(QString::number(transferAccountNumber));

                QMessageBox::warning(this, "Money Transfer successful", QString("You have transfered %1 from your Credit account to Debit account.").arg(withdrawal));
                emit transfer();
            }
            else
            {
             this->close();
            }

    }

    else if (ui->comboBoxChooseAccount->currentIndex() == 4) // Transfer from Credit
    {
        int transferAccount = ui->creditBalanceLine->text().toInt();
        int receiveAccount = ui->debitBalanceLine->text().toInt();
        int transferAccountNumber = ui->debitNumberLine->text().toInt();

        if (withdrawal > transferAccount)
        {
            // Error if the withdrawal amount is greater than the debit balance
            QMessageBox::warning(this, "Insufficient funds", "You do not have enough funds to withdraw that amount.");
            return;
        }

        QMessageBox confirmation;
        confirmation.setText(tr("Do you want to proceed?"));
        QAbstractButton *pButtonYes = confirmation.addButton(tr("Kyllä"), QMessageBox::YesRole);
        confirmation.addButton(tr("Peruuta"), QMessageBox::NoRole);
        confirmation.exec();
        if(confirmation.clickedButton() == pButtonYes)
        {
            //lets add the calculations here
            int transferCreditBalance = transferAccount - withdrawal;
            int transferDebitBalance = receiveAccount + withdrawal;
            ui->debitBalanceLine->setText(QString::number(transferDebitBalance));
            ui->creditBalanceLine->setText(QString::number(transferCreditBalance));
            ui->debitNumberLine->setText(QString::number(transferAccountNumber));

            QMessageBox::warning(this, "Money Transfer successful", QString("You have transfered %1 from your debit account to credit account.").arg(withdrawal));
            emit transfer();
        }
        else
        {
         this->close();
        }
    }
}

void DLLwithdraw::sendWithdrawResult(QString result)
{
    emit withdrawResultToEXE(result);
}


//pushing new balance balancen RestAPIIN
void DLLwithdraw::SendBalance()
{
    int DebitBalance = ui->debitBalanceLine->text().toInt();
    int CreditBalance = ui->creditBalanceLine->text().toInt();
    int AccountNumber = ui->debitNumberLine->text().toInt();

    qDebug()<<"sendBalancen alussa"<<DebitBalance;
    qDebug()<<"sendBalancen alussa"<<AccountNumber;
    qDebug()<<"sendBalancen alussa"<<CreditBalance;
    qDebug() << "Response data:" << response_data;

    //Create a JSON object containing the account number and debitBalance value.
    QJsonObject json_obj;
    json_obj.insert("AccountNumber", AccountNumber);
    json_obj.insert("DebitBalance", DebitBalance);
    json_obj.insert("CreditBalance", CreditBalance);

    //Set the URL to which the HTTP request will be sent.
    QString site_url="http://localhost:3000/account/1";
    QString credentials="netuser:netpass";
    QNetworkRequest request((site_url));
    // Set HTTP-headlines
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader("Authorization", headerData.toLocal8Bit());
    //Create a QNetworkAccessManager and connect it to withdrawSlot().
    withdrawManager = new QNetworkAccessManager(this);
    connect(withdrawManager, SIGNAL(finished(QNetworkReply*)),
    this, SLOT(withdrawSlot(QNetworkReply*)));
    // Create a QNetworkReply and send it with the information in the corresponding section.
    withdrawReply = withdrawManager->put(request, QJsonDocument(json_obj).toJson());

    qDebug()<<"sendBalancen lopussa"<<DebitBalance;
    qDebug()<<"sendBalancen lopussa"<<CreditBalance;
    qDebug()<<"sendBalancen lopussa"<<AccountNumber;
}


    // QNetworkReply-safety process-funktio.
void DLLwithdraw::withdrawSlot(QNetworkReply *reply)
{
    //Read the content of the response and place it in the responseData variable.
    QByteArray response_SendData=reply->readAll();
    if(response_SendData.compare("0") == 0)
    {   // If the answer is "0", set an error message.
        if(response_SendData.compare("-4078")==0 || response_SendData.compare("")==0){  //Error comparison when postman gives an error and if that data matches in this console if same error then print error signal
            ui->errorLabel->setText("Virhe tietokanta yhteydessä");
        emit returnWithdrawResult("false");
    }}
    else
    {   //If the answer is something other than "0", send a "true" signal.
        emit returnWithdrawResult("true");
         qDebug() << "Response data:" << response_SendData;
    }
     // Unblock the reply and remove the sender and reply processing functions.
    withdrawReply->deleteLater();
    reply->deleteLater();
    withdrawManager->deleteLater();
}


void DLLwithdraw::accountNumberF()
{
     ui->debitNumberLine->setText(QString(" %1").arg(accountNumber));
}

void DLLwithdraw::creditBalanceF()
{
    ui->creditBalanceLine->setText(QString(" %1").arg(creditSaldo));

}

void DLLwithdraw::debitBalanceF()
{
    ui->debitBalanceLine->setText(QString(" %1").arg(debitSaldo));
}



void DLLwithdraw::withdraw20()
{
       // Set the withdrawal amount to 20
    QString withdrawalAmount = "20";
       // Set the text of the withdrawal line edit to the withdrawal amount
    ui->withdrawalLineEdit->setText(withdrawalAmount);
}

void DLLwithdraw::withdraw40()
{
    QString withdrawalAmount = "40";
    ui->withdrawalLineEdit->setText(withdrawalAmount);
}

void DLLwithdraw::withdraw100()
{
        QString withdrawalAmount = "100";
        ui->withdrawalLineEdit->setText(withdrawalAmount);
}

void DLLwithdraw::withdraw200()
{
        QString withdrawalAmount = "200";
        ui->withdrawalLineEdit->setText(withdrawalAmount);
}

void DLLwithdraw::numberClicked()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button) {
        QString digit = button->text();
        ui->withdrawalLineEdit->setText(ui->withdrawalLineEdit->text() + digit);
    }
}


void DLLwithdraw::clearClicked()
{
    QString text = ui->withdrawalLineEdit->text();
    text.chop(1);
    ui->withdrawalLineEdit->setText(text);
}


void DLLwithdraw::sendTransferResult(QString result)
{
    emit transferResultToEXE(result);
}


void DLLwithdraw::transfer()
{
    //Capture the account number and amount entered by the user.
    int sendDebit = ui->debitBalanceLine->text().toInt();
    int receiveCredit = ui->creditBalanceLine->text().toInt();
    int transferAccount = ui->debitNumberLine->text().toInt();

    //Create a JSON object containing the amount to be transferred and the accounts.
    QJsonObject json_obj;
    json_obj.insert("AccountNumber", transferAccount);
    json_obj.insert("DebitBalance", sendDebit);
    json_obj.insert("CreditBalance", receiveCredit);

    // Let's define an HTTP request to http://localhost:3000/account/1.
    QString site_url = "http://localhost:3000/account/1";
    QString credentials = "netuser:netpass";

    //Add login credentials to the HTTP request.
    QNetworkRequest request(site_url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader("Authorization", headerData.toLocal8Bit());

    // Create a QNetworkAccessManager and connect the finished signal to the transferSlot handler.
    transferManager = new QNetworkAccessManager(this);

    connect(transferManager, SIGNAL(finished(QNetworkReply*)),
    this, SLOT(transferSlot(QNetworkReply*)));

    // A PUT request is sent to complete the transfer.
    transferReply = transferManager->put(request, QJsonDocument(json_obj).toJson());

    close();
}


void DLLwithdraw::transferSlot(QNetworkReply *reply)
{   // Read the reply message.
    QByteArray response_TransferData=reply->readAll();
    if(response_TransferData.compare("0") == 0)
    {    // Check the content of the reply and set an error or transfer failure message.
        if(response_TransferData.compare("-4078")==0 || response_TransferData.compare("")==0){
            //Error comparison when postman gives an error and if that data matches in this console if same error then print error signal
            ui->errorLabel->setText("Virhe tietokanta yhteydessä");
        emit returnTransferResult("false");
    }}
    else
    {
        emit returnTransferResult("true");
    }

    transferReply->deleteLater();
    reply->deleteLater();
    transferManager->deleteLater();
}


void DLLwithdraw::sendHistoryResult(QString result)
{
    emit withdrawResultToEXE(result);
}

void DLLwithdraw::SendHistory()
{
    int Amount = ui->withdrawalLineEdit->text().toInt();
    int historyAccount = ui->idAccountLabel->text().toInt();

    QDateTime datetime = QDateTime::currentDateTime();
    ui->clockLabel->setText(datetime.toString("yyyy-MM-dd"));
    qDebug()<<"Show datetime"<<datetime;
    //QString time = ui->clockLabel->text();
    qDebug()<<datetime.toString("yyyy-MM-dd");


    qDebug()<<"Send history start amount"<<Amount;
   // qDebug()<<"SendHistory Start id"<<idNumber;
  //  qDebug()<<"sendHistory start credit"<<creditBalance;
    qDebug() << "Response data:" << response_data;

    // creates a JSON object containing the account number and debitBalance value.
    QJsonObject json_obj;

    json_obj.insert("Date", datetime.toString("yyyy-MM-dd"));
    json_obj.insert("Amount", Amount);
    json_obj.insert("Account_idAccount", historyAccount);

    //Set the URL to which the HTTP request will be sent.
    QString site_url3="http://localhost:3000/history/add";
    QString credentials3="netuser:netpass";
    QNetworkRequest request3((site_url3));

    request3.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data3 = credentials3.toLocal8Bit().toBase64();
    QString headerData3 = "Basic " + data3;
    request3.setRawHeader("Authorization", headerData3.toLocal8Bit());
    // Create a QNetworkAccessManager and connect it to withdrawSlot().
    PushHistoryManager = new QNetworkAccessManager(this);
    connect(PushHistoryManager, SIGNAL(finished(QNetworkReply*)),
    this, SLOT(withdrawSlot(QNetworkReply*)));
    // Create a QNetworkReply and send it with the information in the corresponding section.
    PushHistoryReply = PushHistoryManager->post(request3, QJsonDocument(json_obj).toJson());

    qDebug()<<"Pushistorynlopussa"<<Amount;
    qDebug()<<"PushHistoryn lopussa"<<idAccount;


    close();
}


void DLLwithdraw::PushHistorySlot(QNetworkReply *reply)
{

    QByteArray response_HistoryData=reply->readAll();
    if(response_HistoryData.compare("0") == 0)
    {   // If answer is zero print error
        if(response_HistoryData.compare("-4078")==0 || response_HistoryData.compare("")==0){  //Virhevertailu kun postman antaa virheen ja jos se data matchaa tässä konsolissa eli sama virhe niin print virhesignal
            ui->errorLabel->setText("Virhe tietokanta yhteydessä");
        emit returnHistoryResult("false");
    }}
    else
    {   // If the answer is something other than "0", send a "true" signal.
        emit returnHistoryResult("true");
         qDebug() << "Response data historyssä:" << response_HistoryData;
    }
     // Unblock the reply and remove the sender and reply processing functions.
    PushHistoryReply->deleteLater();
    reply->deleteLater();
    PushHistoryManager->deleteLater();
}


void DLLwithdraw::close()
{
    //this->close(); //close the current window
     // qApp->exit(); //exit the program
    QWidget::close();

}

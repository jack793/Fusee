#ifndef LOGINVIEW_H
#define LOGINVIEW_H

#include <QDialog>
#include <QDesktopWidget>
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include<MODEL/MODEL_DATA/Database.h>
#include<VIEW/dialogmessage.h>

class LoginView: public QDialog
{
    Q_OBJECT
private:
    Database* dbModel;
    
    QLabel* messageLabel;
    QLabel* usernameLabel;
    QLabel* passwordLabel;
    
    QLineEdit* usernameEdit;
    QLineEdit* passwordEdit;
    
    QPushButton* confirmPButton;
    QPushButton* cancelPButton;
    
    DialogMessage* dialMessage;
    
    void setView();
    void centerWindow(int,int);
    
public:
    LoginView();
    ~LoginView();
    
private slots:
    void verifyLogin();
    void cancelLogin();
    
signals:
    void signalCorrectLogin(std::string);
    void signalCancel();
};

#endif // LOGINVIEW_H

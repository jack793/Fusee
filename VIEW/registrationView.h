#ifndef REGISTRATIONVIEW_H
#define REGISTRATIONVIEW_H

#include <QWidget>
#include <QApplication>
#include <QDesktopWidget>
#include <QScrollArea>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QSizePolicy>
#include <QPushButton>
#include <QFrame>
#include <QComboBox>
#include <QRadioButton>
#include <QPushButton>
#include <string>
#include <QDate>
#include <QButtonGroup>

#include<MODEL/MODEL_DATA/Database.h>

#include<VIEW/mainview.h>
#include<VIEW/datebox.h>
#include<VIEW/dialogmessage.h>

class RegistrationView : public QWidget{
    Q_OBJECT
private:
    Database* ptdb;
    
    // GRAFICA
    QScrollArea* scrollArea;
    QFrame* formScroll;
    
    // input registrazione
    QLineEdit* usernameEdit;
    QLabel* usernameLabel;
    
    QLineEdit* passwordEdit;
    QLabel* passwordLabel;
    
    QLineEdit* nomeEdit;
    QLabel* nomeLabel;
    
    QLineEdit* cognomeEdit;
    QLabel* cognomeLabel;
    
    QLabel* dataNascitaLabel;
    DateBox* dateBox;
    
    QButtonGroup* sessoButtonG;
    QLabel* sessoLabel;
    QRadioButton* sessoM;
    QRadioButton* sessoF;
    
    QLabel* residenzaLabel;
    QLineEdit* regioneEdit;
    QLabel* regioneLabel;
    QLineEdit* paeseEdit;    
    QLabel* paeseLabel;
    QLineEdit* indirizzoEdit;
    QLabel* indirizzoLabel;
    QLineEdit* nazioneEdit;
    QLabel* nazioneLabel;
    
    QLineEdit* professioneEdit;
    QLabel* professioneLabel;
    QLineEdit* numeroEdit;
    QLabel* numeroLabel;
    
    //pushbutton
    QPushButton* createPButton;
    QPushButton* cancelPButton;
    
    //messaggi
    DialogMessage* dialMessage;
 
public:
    RegistrationView(Database* db=0 );
    ~RegistrationView();
    void loadGraphic();
    void centerWindow(int,int);
private slots:
    void checkDati();
    void cancelRegistration();
signals:
    void createUser(const QString&, const QString&, const QString&, const QString&, bool , const QString&, const QString&, const QString& , const QString&, const QString& , const QString& );
                    // (username, password, nome, cognome, sesso, professione, numero, nazione, regione, paese, indirizzo)
    void UserNotCreate();
};

#endif // REGISTRATIONVIEW_H

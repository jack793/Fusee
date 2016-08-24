#include<VIEW/registrationView.h>


//COSTRUTTORI
RegistrationView::RegistrationView(Database* db): ptdb(db) {
    loadGraphic();
    connect(buttonRegistration,SIGNAL(clicked()),this,SLOT(checkDati()));
    connect(buttonCancel,SIGNAL(clicked()),this,SLOT(cancelRegistration()));
}

RegistrationView::~RegistrationView(){}


//METODI
void RegistrationView::loadGraphic(){
    setWindowTitle("Registrazione");
    
    scrollArea=new QScrollArea(this);
    formScroll=new QFrame(scrollArea);
    
    usernameLabel=new QLabel("Inserisci un nuovo username:",formScroll);
    usernameEdit=new QLineEdit(formScroll);
    usernameEdit->setFixedWidth(300);
    
    passwordLabel=new QLabel("Imposta una nuova password (almeno 4 caratteri):",formScroll);
    passwordEdit=new QLineEdit(formScroll);
    passwordEdit->setFixedWidth(300);
    
    nomeLabel=new QLabel("Inserisci il nome:",formScroll);
    nomeEdit=new QLineEdit(formScroll);
    nomeEdit->setFixedWidth(300);
    
    cognomeLabel=new QLabel("Inserisci il cognome:",formScroll);
    cognomeEdit=new QLineEdit(formScroll);
    cognomeEdit->setFixedWidth(300);
    
    dataNascitaLabel=new QLabel("Inserisci la data di nascita (giorno,mese,anno):");
    dateBox=new DateBox(formScroll,1900,2000);
    
    professioneLabel=new QLabel("Inserisci la professione atttuale:");
    professioneEdit=new QLineEdit(formScroll);
    professioneEdit->setFixedWidth(300);
    
    numeroLabel=new QLabel("Inserisci un contatto telefonico:");
    numeroEdit=new QLineEdit(formScroll);
    numeroEdit->setFixedWidth(300);
    
    sessoButtonG=new QButtonGroup(formScroll);
    sessoLabel=new QLabel("Selezione sesso",formScroll);
    sessoM=new QRadioButton("Maschio",formScroll);
    sessoM->setChecked(true);
    sessoF=new QRadioButton("Femmina",formScroll);
    sessoButtonG->addButton(sessoM);
    sessoButtonG->addButton(sessoF);
    QHBoxLayout* hSexLay=new QHBoxLayout;
    QVBoxLayout* vSexLay=new QVBoxLayout;
    hSexLay->addWidget(sessoM);
    hSexLay->addWidget(sessoF);
    vSexLay->addWidget(sessoLabel);
    vSexLay->addLayout(hSexLay);
    
    residenzaLabel=new QLabel("Inserisci la residenza attuale:",formScroll);
    nazioneLabel=new QLabel("Nazione:",formScroll);
    nazioneEdit=new QLineEdit(formScroll);
    nazioneEdit->setFixedWidth(300);
    
    regioneLabel=new QLabel("Regione:",formScroll);
    regioneEdit=new QLineEdit(formScroll);
    regioneEdit->setFixedWidth(300);
    
    paeseLabel=new QLabel("Paese:",formScroll);
    paeseEdit=new QLineEdit(formScroll);
    paeseEdit->setFixedWidth(300);
    
    indirizzoLabel=new QLabel("Indirizzo:",formScroll);
    indirizzoEdit=new QLineEdit(formScroll);
    indirizzoEdit->setFixedWidth(400);
    
    createPButton=new QPushButton("Crea nuovo utente");
    createPButton->setFixedWidth(200);
    cancelPButton=new QPushButton("Annulla");
    cancelPButton->setFixedWidth(200);
    //--------------------------------------- da finire..
    
    QFont font1( "Lucida Handwriting", 60);
    QFont font2( "Lucida Handwriting", 20);

}

void RegistrationView::centerWindow(int windowWidth, int windowHeight){
    QDesktopWidget* desktop= QApplication::desktop();
    int x,y;
    int screenWidth, screenHeight;
    screenWidth = desktop->width();
    screenHeight = desktop->height();
    x=(screenWidth-windowWidth)/2;
    y=(screenHeight-windowHeight)/2;
    this->move(x,y);
}

void RegistrationView::checkDati(){
    std::string username=usernameEdit->text().toStdString();
    std::string password=passwordEdit->text().toStdString();
    std::string nome=nomeEdit->text().toStdString();
    std::string cognome=cognomeEdit->text().toStdString();
    std::string professione=professioneEdit->text().toStdString();
    std::string numero=numeroEdit->text().toStdString();
    QDate dataNascita=dateBox->getDate();
    bool sesso=false;
    if(sessoM->isChecked())
        sesso=true;
    std::string nazione=nazioneEdit->text().toStdString();
    std::string regione=regioneEdit->text().toStdString();
    std::string paese=paeseEdit->text().toStdString();
    std::string indirizzo=indirizzoEdit->text().toStdString();
    
    if(username.size()==0){
        dialMessage=new DialogMessage("Controllo dati","Non hai compilato il campo USERNAME","Indietro");
        dialMessage->show();
    }
    else if(ptdb->matchUser(username)){
        dialMessage=new DialogMessage("Controllo dati","Username già utilizzato, inseriscine uno diverso","Indietro");
        dialMessage->show();
    }
    else if(password.size()==0){
        dialMessage=new DialogMessage("Controllo dati","Non hai compilato il campo PASSWORD","Indietro");
        dialMessage->show();
    }
    else if(password.size()<3){
        dialMessage=new DialogMessage("Controllo dati","La password deve avere almeno 4 caratteri","Indietro");
        dialMessage->show();
    }
    else if(nome.size()==0){
        dialMessage=new DialogMessage("Controllo dati","Non hai compilato il campo NOME","Indietro");
        dialMessage->show();
    }
    else if(cognome.size()==0){
        dialMessage=new DialogMessage("Controllo dati","Non hai compilato il campo COGNOME","Indietro");
        dialMessage->show();
    }
    else if(professione.size()==0){
        dialMessage=new DialogMessage("Controllo dati","Non hai compilato il campo PROFESSIONE","Indietro");
        dialMessage->show();
    }
    else if(numero.size()==0){
        dialMessage=new DialogMessage("Controllo dati","Non hai compilato il campo NUMERO","Indietro");
        dialMessage->show();
    }
    else if(nazione.size()==0){
        dialMessage=new DialogMessage("Controllo dati","Non hai compilato il campo NAZIONE","Indietro");
        dialMessage->show();
    }
    else if(regione.size()==0){
        dialMessage=new DialogMessage("Controllo dati","Non hai compilato il campo REGIONE","Indietro");
        dialMessage->show();
    }
    else if(paese.size()==0){
        dialMessage=new DialogMessage("Controllo dati","Non hai compilato il campo PAESE","Indietro");
        dialMessage->show();
    }
    else if(indirizzo.size()==0){
        dialMessage=new DialogMessage("Controllo dati","Non hai compilato il campo INDIRIZZO","Indietro");
        dialMessage->show();
    }
    else //form completo
        emit createUser(username,password,nome,cognome,sesso,professione,numero,nazione,regione,paese,indirizzo);      
}

void RegistrationView::cancelRegistration(){
    emit UserNotCreate();
}

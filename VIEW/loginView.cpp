#include<VIEW/loginView.h>

//COSTRUTTORI
LoginView::LoginView(){
    dbModel=new Database;
    dbModel->Load();
    setView();
    connect(confirmPButton,SIGNAL(clicked()),this,SLOT(verifyLogin()));
    connect(cancelPButton,SIGNAL(clicked()),this,SLOT(cancelLogin()));
}

LoginView::~LoginView() {delete dbModel;}

//METODI

void LoginView::setView()
{
    this->setWindowTitle("Login - Fusee");
    messageLabel=new QLabel("Effettua il login per accedere:",this);
    usernameLabel=new QLabel("Username:",this);
    passwordLabel=new QLabel("Password:",this);
    
    confirmPButton=new QPushButton("Effettua login",this);
    cancelPButton=new QPushButton("Annulla",this);
    
    usernameEdit=new QLineEdit(this);
    usernameEdit->setFixedWidth(300);
    
    passwordEdit=new QLineEdit(this);
    passwordEdit->setFixedWidth(300);
    passwordEdit->setEchoMode(QLineEdit::Password); //Display platform-dependent password mask characters instead of the characters actually entered
    
    QVBoxLayout* vLay=new QVBoxLayout(this);
    vLay->addWidget(messageLabel);
    vLay->addWidget(usernameLabel);
    vLay->addWidget(usernameEdit);
    vLay->addWidget(passwordLabel);
    vLay->addWidget(passwordEdit);
    
    QHBoxLayout* hLay=new QHBoxLayout;
    hLay->addWidget(cancelPButton);
    hLay->addWidget(confirmPButton);
    
    vLay->addLayout(hLay);
    vLay->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(vLay);
    centerWindow(450,250);
    this->show();
}

void LoginView::centerWindow(int windowWidth, int Height)
{
    QDesktopWidget *desktop = QApplication::desktop();
    int x, y;
    int screenWidth, screenHeight;
    screenWidth = desktop->width();
    screenHeight = desktop->height();
    x = (screenWidth-windowWidth) / 2;
    y = (screenHeight-windowHeight) / 2;
    this->move(x,y);
}

void LoginView::verifyLogin()
{
    if(!dbModel->matchUser(usernameEdit->text().toStdString()))
    {
        dialMessage=new DialogMessage("Controlli dati","Username o password inseriti non corretti","Riprova");
        dialMessage->show();
    }
    else //esiste username
    {
        User* u=dbModel->getUser(usernameEdit->text().toStdString(),passwordEdit->text().toStdString());
        if(!u){ //non esiste un utente con quella pwd
            dialMessage=new DialogMessage("Controllo dati","Username o password inseriti non corretti","Riprova");
            dialMessage->show();
        }
        else //match degli input richiesti
            emit signalCorrectLogin(usernameEdit->text().toStdString());
    }
}

void LoginView::cancelLogin() {emit signalCancel();}

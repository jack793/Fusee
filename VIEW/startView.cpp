#include<VIEW/startView.h>

//COSTRUTTORI
StartView::StartView()
{
    this->setFixedSize(350,150);
    welcomeTitle=new QLabel(this);
    welcomeTitle->setText(QString::fromStdString("Benvenuto in Fusee\nPuoi accedere tramite login o creando un nuovo utente"));
    
    loginPButton=new QPushButton(this);
    loginPButton->setText(QString::fromStdString("Login"));
    loginPButton->setFixedWidth(150);
    
    registerPButton=new QPushButton(this);
    registerPButton->setText(QString::fromStdString("Registrazione"));
    registerPButton->setFixedWidth(150);
    
    connect(loginPButton,SIGNAL(clicked()),this,SLOT(loadLogin()));
    connect(registerPButton,SIGNAL(clicked()),this,SLOT(loadRegistration()));
    
    QGridLayout* layout=new QGridLayout();
    layout()->addWidget(welcomeTitle);
    layout()->addWidget(loginPButton);
    layout()->addWidget(registerPButton);
    setLayout(layout);
    centerWindow(350,150);
    this->show();
}

StartView::~StartView(){}

//METODI

void StartView::centerWindow(int windowWidth, int windowHeight)
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

//SIGNALS

void StartView::loadLogin(){
    emit signalLogin();
}

void StartView::loadRegistration(){
    emit signalRegistration();
}

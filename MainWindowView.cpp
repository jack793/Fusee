#include "MainWindowView.h"

MainWindowView::MainWindowView(QWidget* parent)
    : QWidget ( parent )
{
    QLabel* initialMessage = new QLabel;
    initialMessage->setText( tr( "Selezionare metodo di autenticazione" ));

    QPushButton* admin = new QPushButton( tr( "Admin" ));
    QPushButton* user = new QPushButton( tr ( "User" ));

    QVBoxLayout* layoutButton = new QVBoxLayout;
    layoutButton->addWidget( initialMessage );
    layoutButton->addWidget( admin );
    layoutButton->addWidget( user );

    QGroupBox* gBox = new QGroupBox( tr( "Login") );
    gBox->setLayout( layoutButton );

    QVBoxLayout* layoutFinal = new QVBoxLayout;
    layoutFinal->addWidget( gBox );

    setLayout( layoutFinal );
    setFixedSize( sizeHint() );

    connect (admin,
             SIGNAL ( clicked () ),
             this,
             SIGNAL ( adminViewCall() ));

    connect (user,
             SIGNAL (clicked () ),
             this,
             SIGNAL ( memberLoginCall() ));

}




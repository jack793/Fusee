#include "MainWindowController.h"

MainWindowController::~MainWindowController()
{
    delete Model;
    delete View;

}

void MainWindowController::showUI(){

    View->show();
}

void MainWindowController::showAdmin()const{

    View->close();

    //ora carico il database lato amministrativo
    Model->getAdminController()->loadDb();

    Model->getAdminController()->showUI();

}

void MainWindowController::showLoginMember()const{

    View->close();

    //ora carico il database lato membro
    Model->getMemberLoginController()->loadDb();

    Model->getMemberLoginController()->showUI();
}

MainWindowController::MainWindowController(MainWindowModel* nModel,
                                           MainWindowView* nView)
    : Model (nModel), View (nView)
{


    connect(View,
            SIGNAL ( adminViewCall() ),
            this,
            SLOT ( showAdmin() ));

    connect(View,
            SIGNAL ( memberLoginCall() ),
            this,
            SLOT ( showLoginMember() ));

}

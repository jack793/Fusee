#include "MainWindowModel.h"

MainWindowModel::MainWindowModel()
    : admin (nullptr),
      memberLogin (nullptr)
{}

MainWindowModel::~MainWindowModel(){

    if (admin != nullptr)
        delete admin;

    if (memberLogin != nullptr)
        delete memberLogin;
}

AdminWindowController* MainWindowModel::getAdminController(){

    if (admin == nullptr)
        admin = new AdminWindowController;

    return admin;
}

MemberLoginWController* MainWindowModel::getMemberLoginController(){

    if (memberLogin == nullptr)
        memberLogin = new MemberLoginWController;

    return memberLogin;
}

#include<MODEL/USER_DATA/Login.h>

Login::Login(QString user, QString psw): username(user), password(psw) {}

const QString& Login::getUsername() const {return username;}

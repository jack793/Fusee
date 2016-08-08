#include<MODEL/USER_DATA/Login.h>


//COSTRUTTORE
Login::Login(QString user, QString psw): username(user), password(psw) {}

//GET
const QString& Login::getUsername() const {return username;}

//LETTURA IN DB
Login* Login::readLogin(QXmlStreamReader& xmlReader){
    QString username;
    QString password;
    
    while(!xmlReader.isEndElement() || !(xmlReader.name()=="login")){
        if(xmlReader.name()=="username"){username=xmlReader.readElementText();}
        else if(xmlReader.name()=="password"){password=xmlReader.readElementText();}
        xmlReader.readNext();
    }
    return new Login(username,password);
}

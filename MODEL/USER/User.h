#ifndef USER_H
#define USER_H

#include <QXmlStreamWriter>

#include "USERDATA/Profilo.h"
#include "USERDATA/Network.h"

class Database; //dich. incompleta

class User{
private:
    Profilo* profile;
    Network* net;
    Login* login;
public:
    User(Profilo* p=0,Network* r=0, Login* l=0);
    
    Profilo* getProfile() const;
    Network* getNetwork() const;
    Login* getLogin() const;
    
    void setProfile(const Qstring& name, const Qstring& surname,bool sex,const QDate& date,const Residenza& adress,const Qstring& country,const Qstring& language,const Qstring& mail);
    
    //GET INFO FROM UTENTE
    const QString &getUsername() const;
    const QString& getNome()const;
    const QString& getCognome()const;
    bool getSesso() const;
    QString getSessoString()const;
    const QDate &getData()const;
    QString getDataString()const;
    const QString& getPaese()const;
    const Residenza& getResidenza()const;
    const QString& getMail()const;
    
    
    virtual QString toString() const =0;
    virtual QString info() const =0;
    virtual void writeType(QXmlStreamWriter& xmlWriter) const =0;
    virtual bool search(const Utente* user,const QString& text,const QString& category) const =0;
    
    virtual ~Utente();
	
};
#endif //USER_H

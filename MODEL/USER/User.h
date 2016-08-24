#ifndef USER_H
#define USER_H

#include <QXmlStreamWriter>

#include "MODEL/USER_DATA/Profilo.h"
#include "MODEL/USER_DATA/Network.h"
#include "MODEL/USER_DATA/Login.h"

class Database; //dich. incompleta

class User{
private:
    Profilo* profile;
    Network* net;
    Login* login;
public:
    User(Profilo* p=0,Network* n=0, Login* l=0);
        
    Profilo* getProfile() const;
    Network* getNetwork() const;
    Login* getLogin() const;
    
    //void setProfile(const Qstring& name, const Qstring& surname,bool sex,const QDate& date,const Residenza& adress,const Qstring& country,const Qstring& mail);
    
    //GET INFO FROM PROFILO
    const QString& getUsername() const;
    const QString& getPassword() const;
    const QString& getNome()const;
    const QString& getCognome()const;
    bool getSesso() const;
    QString getSessoString()const;
    const QDate &getData()const;
    QString getDataString()const;
    const QString& getNazione() const;
    
    const Residenza& getResidenza() const;
    const QString& getProf() const;
    const QString& getNum() const;
    const QString& getMail()const;
    
    const Container<QString>& getDiary() const;
    
    const Container<QString>& getFollowers() const;
    const Container<QString>& getFollowing() const;
    const QString& getLevel() const;  
    

    virtual QString toString() const =0;
    virtual QString info() const =0;
    
    virtual void writeLevel(QXmlStreamWriter& xmlWriter) const =0;
    virtual bool search(User* user,const QString& text,const QString& category) const =0;
    
    virtual ~Utente();
	
};
#endif //USER_H

#ifndef LOGIN_H
#define LOGIN_H

#include<QXmlStreamReader>
#include<QString>

class Login{
private:
    QString username;
    QString password;
public:
    Login(QString user, QString psw);
    
    const QString& getUsername() const;
    const QString& getPsw() const;
    
    static Login* readLogin(QXmlStreamReader& );
    
};

#endif // LOGIN_H

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
    
};

#endif // LOGIN_H

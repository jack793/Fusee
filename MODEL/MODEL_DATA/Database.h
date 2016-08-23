#ifndef DATABASE_H
#define DATABASE_H

//#include<typeinfo>  //The inclusion of this header is required prior to any use of the typeid operator.

#include<iostream>  //The iostream library is an object-oriented library that provides input and output functionality using streams.
#include<QFile>  //The QFile class provides an interface for reading from and writing to files.
#include<QXmlStreamWriter>
#include<QXmlStreamReader>
#include<QString>

#include<MODEL/MODEL_DATA/Container.h>

#include<MODEL/USER/User.h>
#include<MODEL/USER/Newbie.h>
#include<MODEL/USER/Med.h>
#include<MODEL/USER/Pro.h>

class Database{
private:
    static QString filename;    //var name che acquisirà la path del db fisico .xml del progetto
    Container<User*> FuseeDb;
public:
    Database();
    ~Database();
    
    void Load();
    void Close();
    
    bool isEmpty() const;
    
    bool verifyUser(const QString& ,const QString& ) const; //true sse username e password coincidono nel db
    
    void dtorUser(User* ); //elimina un user dal db (non so se mi serve)
    
    void addUser(User* );    //aggiunge un user al db
    
    bool matchUser(const QString& u ) const; //true se l'username c'è nel db
    
    User* getUser(const QString& u, const QString& pw ) const;
    
    void updateLevelUser(User* );
    
    //test
    void printUser(const User* u) const;
};

#endif //DATABASE_H

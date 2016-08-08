#ifndef DATABASE_H
#define DATABASE_H

#include<map>
#include<iostream>  //The iostream library is an object-oriented library that provides input and output functionality using streams.
#include<typeinfo>  //The inclusion of this header is required prior to any use of the typeid operator.
#include<QFile>  //The QFile class provides an interface for reading from and writing to files.
#include<QXmlStreamWriter>
#include<QXmlStreamReader>
#include<QString>

#include<MODEL/USER/Newbie.h>
#include<MODEL/USER/Med.h>
#include<MODEL/USER/Pro.h>

class Database{
private:
    static QString filename;    //var name che acquisirà la path del db fisico .xml del progetto
    std::map<QString,User*> db; //stringa username e utente
private:
    Database();
    ~Database();
    
    typedef std::map<QString, User*>::iterator db_iterator;
    typedef std::map<QString, User*>::const_iterator db_const_iterator;
    
    db_iterator begin();
    db_iterator end();
    db_const_iterator begin() const;
    db_const_iterator end() const;
    
    void Load();
    void Close();
    bool dbEmpty() const;
    
    void dtorUser(const QString& user);
    void newUser(const QString& user, const QString &psw, int tipo, const QString& nome, const QString& cognome);
    bool matchUser(const QString& user) const;
    User* findUser(const QString& user) const;
    
    void changeLevelUser(const QString& user, const int tipo);
    
    //test
    void printUser(const User* u) const;
};

#endif //DATABASE_H

#ifndef NETWORK_H
#define NETWORK_H

#include<MODEL/MODEL_DATA/Container.h>
#include<Qstring>
#include<iostream>
#include<QXmlStreamReader>

using namespace std;

class Network{
private:
    QString level;
    Container<QString> followers;
    Container<QString> following;
public:
    Network(const QString& lev="", Container<QString>& flwe=Container::Container(), Container<QString>& flwi=Container::Container());
    
    //il livello di un utente si setta in base al numero di followers
    QString setLevel(const QString& flwe);
    
    void updateLevel(unsigned int);
    
    //get
    QString getLevel() const;
    Container<QString>& getFollowers() const;
    Container<QString>& getFollowing() const;
    
    //altri metodi
    
    bool isFlweEmpty() const;
    bool isFlwiEmpty() const;
    
    bool existFollower(const QString& user);
    bool existFollowing(const QString &user);
    
    void addFollower(const QString& user);
    void addFollowing(const QString& user);
    
    void rmFollower(QString user);
    void rmFollowing(const QString& user);
    
    
    //lettura in db
    static Network* readNetwork(QXmlStreamReader& );
    //non c'è controllo dell'esistenza dell'username, per quello si occupa chi aggiunge
    
};

#endif // NETWORK_H

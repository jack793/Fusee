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
    Network(const Container<QString>& flwe=Container::Container(), const Container<QString>& flwi=Container::Container());
    
    //il livello di un utente si setta in base al numero di followers
    QString setLevelString(const Container<QString>& );
    
    void updateLevel(unsigned int);
    
    //get
    const QString& getLevel() const;
    const Container<QString>& getFollowers() const;
    const Container<QString>& getFollowing() const;
    
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
    
};

#endif // NETWORK_H

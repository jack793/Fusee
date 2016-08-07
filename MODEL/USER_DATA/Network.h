#ifndef NETWORK_H
#define NETWORK_H

#include<list>
#include<Qstring>
#include<iostream>
#include<QXmlStreamReader>

using namespace std;

class Network{
private:
    std::list<QString> followers;
    std::list<QString> following;
public:
    Network(const std::list<QString>& flwe=std::list<QString>(), const std::list<QString>& flwi);
    
    //creo alias di tipi esistenti per facilitare il riferimento ai miei iteratori
    typedef std::list<QString>::iterator net_it;
    typedef std::list<QString>::const_iterator net_const_it;
    
    //per lista followers
    net_it beginFlwe();
    net_it endFlwe();
    net_const_it beginFlwe() const;
    net_const_it endFlwe() const;
    //per lista following
    net_it beginFlwi();
    net_it endFlwi();
    net_const_it beginFlwi() const;
    net_const_it endFlwi() const;
    
    //get
    const std::list<QString>& getFollowers() const;
    const std::list<QString>& getFollowing() const;
    
    //altri metodi
    bool isFlweEmpty() const;
    bool isFlwiEmpty() const;
    
    bool existFollower(const QString& user);
    bool existFollowing(const QString& user);
    
    void addFollower(const QString& user);
    void addFollowing(const QString& user);
    
    void rmFollower(const QString& user);
    void rmFollowing(const QString& user);
    
    
    //lettura in db
    static Network* readNetwork(QXmlStreamReader& );
    //non c'è controllo dell'esistenza dell'username, per quello si occupa chi aggiunge
    
};

#endif // NETWORK_H

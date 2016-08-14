#include<MODEL/USER_DATA/Network.h>

//COSTRUTTORE
Network::Network(Container<QString>& flwe, Container<QString> &flwi): followers(flwe), following(flwi) 
{   
    //il livello viene settato tramite la funzione adibita setLevel
    level=setLevel(flwe);
}

// Setta il giusto livello in base ai followers
QString Network::setLevel(const Container<QString>& c)
{
    int numeroFollowers = c.size();
    if( numeroFollowers < 3) //da 0 a 2
        return level="Newbie";
    else if( numeroFollowers >2 && numeroFollowers < 6) //da 3 a 5
        return level="Med";
    else if(numeroFollowers > 5) // da 5 in su
        return level="Pro";
}

void Network::updateLevel(unsigned int numFlwe){
    if( numFlwe < 3) //da 0 a 2
        level="Newbie";
    else if( numFlwe >2 && numeroFollowers < 6) //da 3 a 5
        level="Med";
    else if(numFlwe > 5) // da 5 in su
        level="Pro";
}


//GET
QString Network::getLevel() const {return level;}
Container<QString>& Network::getFollowers() const {return followers;}
Container<QString>& Network::getFollowing() const {return following;}

//METODI PRP
bool Network::isFlweEmpty() const {return followers.isEmpty();}
bool Network::isFlwiEmpty() const {return following.isEmpty();}

//exist
bool Network::existFollower(const QString& user){
    bool trovato=false;
    Container<QString>::Iterator it=followers.begin();
    while(!trovato && (it!=followers.end()) ){
        if(followers[it]==user) //è gia tra i followers
            trovato=true;
        it++;
    }
    return trovato;
}

bool Network::existFollowing(const QString& user){
    bool trovato=false;
    Container<QString>::Iterator it=following.begin();
    while(!trovato && (it!=following.end()) ){
        if(following[it]==user) //è gia tra i following
            trovato=true;
        it++;
    }
    return trovato;
}

//add
void Network::addFollower(const QString& user){
    if(!existFollower(user)){
        followers.push_back(user);
        updateLevel(followers.size());  //aggiorno il livello dopo l'aggiunta di un follower 
    }
}

void Network::addFollowing(const QString& user){
    if(!existFollowing(user))
        following.push_back(user);
}

//remove
void Network::rmFollower(QString user){
    followers.pop_element(user);
    std::cout<<followers.size()<<"followers"<<std::endl;
}

void Network::rmFollowing(QString user){
    following.pop_element(user);
    std::cout<<following.size()<<"following"<<std::endl;
}

//LETTURA IN DB
Network* Network::readNetwork(QXmlStreamReader& xmlReader){
    QString lev="Unknown";
    Container<QString> followers;
    Container<QString> followers;
    while(!xmlReader.isEndElement() || !(xmlReader.name()=="network")){
        if(xmlReader.isStartElement()){
            if(xmlReader.name()=="level")
                xmlReader.readElementText();
            if(xmlReader.name()=="follower")
                followers.push_back(xmlReader.readElementText());
            else if(xmlReader.name()="following")
                following.push_back( xmlReader.readElementText() );
        }
        xmlReader.readNext();
    }
    return new Network(lev,followers,following)
}




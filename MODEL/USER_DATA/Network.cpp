#include<MODEL/USER_DATA/Network.h>

//COSTRUTTORE
Network::Network(const QString &lev, Container<QString>& flwe, Container<QString> &flwi): followers(flwe), following(flwi) {}


//CON ITERATORI?????????manca se voglio fare


//GET
const QString& Network::getLevel() const {
    int numeroFollowers = followers.size();
    if( numeroFollowers < 3) //da 0 a 2
        level="Newbie";
    else if( numeroFollowers >2 && numeroFollowers < 6) //da 3 a 5
        level="Med";
    else if(numeroFollowers > 5) // da 5 in su
        level="Pro";
}

Container<QString> &Network::getFollowers() const {return followers;}
Container<QString>& Network::getFollowing() const {return following;}

//METODI PRP
bool Network::isFlweEmpty() const {return followers.empty();}
bool Network::isFlwiEmpty() const {return following.empty();}

//exist
bool Network::existFollower(const QString& user){
    bool trovato=false;
    std::list<QString>::const_iterator cit=followers.begin();
    while(!trovato && (cit!=followers.end()) ){
        if(*cit==user) //è gia tra i followers
            trovato=true;
        cit++;
    }
    return trovato;
}

bool Network::existFollowing(const QString& user){
    bool trovato=false;
    std::list<QString>::const_iterator cit=following.begin();
    while(!trovato && (cit!=following.end()) ){
        if(*cit==user) //è gia tra i following
            trovato=true;
        cit++;
    }
    return trovato;
}

//add
void Network::addFollower(const QString& user){
    if(!existFollower(user))
        followers.push_back(user);
}

void Network::addFollowing(const QString& user){
    if(!existFollowing(user))
        following.push_back(user);
}

//remove
void Network::rmFollower(const QString& user){
    followers.remove(user);
    //Removes from the container all the elements that compare equal to val. (in base al valore e non alla posiz.)
    //This calls the destructor of these objects and reduces the container size by the number of elements removed.
    std::cout<<followers.size()<<"followers"<<std::endl;
}

void Network::rmFollowing(const QString& user){
    following.remove(user);
    std::cout<<following.size()<<"following"<<std::endl;
}

//LETTURA IN DB
Network* Network::readNetwork(QXmlStreamReader& xmlReader){
    std::list<QString> followers;
    std::list<QString> followers;
    while(!xmlReader.isEndElement() || !(xmlReader.name()=="network")){
        if(xmlReader.isStartElement()){
            if(xmlReader.name()=="follower")
                followers.push_back( xmlReader.readElementText() );
            else if(xmlReader.name()="following")
                following.push_back( xmlReader.readElementText() );
        }
        xmlReader.readNext();
    }
    return new Network(followers,following)
}




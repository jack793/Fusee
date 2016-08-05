#include<MODEL/USER_DATA/Info3.h>

//COSTRUTTORE
Info3::Info3(const std::vector<const QString>& flwe, const std::vector<const QString>& flwi, const Qstring& lev):
    followers(flwe), following(flwi), level(lev) {}

//GET
const std::vector<const QString>& Info3::getFollowers() const {return followers;}
const std::vector<const QString>& Info3::getFollowing() const {return following;}
const QString& Info3::getLevel() const {return level;}

//SET
void Info3::setFollowers(const std::vector<const QString>& flwe) {followers=flwe;}
void Info3::setFollowing(const std::vector<const QString> &flwi) {following=flwi;}
void Info3::setLevel(const QString& lev) {level=lev;}

//ADD
void Info3::addFollower(const QString& flwe) {followers.push_back(flwe);}
void Info3::addFollowing(const QString& flwi) {following.push_back(flwi);}

//MATCH
bool Info3::matchFollower(const QString& text) const {
    for(std::vector<const QString>::const_iterator it=followers.begin(); it!=followers.end(); ++it){
        if( (*it).contains(text,Qt::CaseInsensitive) )
            return true;
    }
    return false;
}

bool Info3::matchFollowing(const QString& text) const {
    for(std::vector<const QString>::const_iterator it=following.begin(); it!=following.end(); ++it){
        if( (*it).contains(text,Qt::CaseInsensitive) )
            return true;
    }
    return false;
}

//LETTURA IN DATABASE
Info3 Info3::readInfo3(QXmlStreamReader& xmlReader){
    std::vector<const QString> followers;
    std::vector<const QString> following;
    Qstring level="Unknown";
    
    while(!xmlReader.isEndElement() || !(xmlReader.name()=="info3")){
        if(xmlReader.isStartElement()){
            if(xmlReader.name()=="follower"){followers.push_back(xmlReader.readElementText());}
            else if(xmlReader.name()=="following"){following.push_back(xmlReader.readElementText());}
            else if(xmlReader.name()=="level"){level=xmlReader.readElementText();}
        }
        xmlReader.readNext();
    }
    return Info3(followers,following,level);
}

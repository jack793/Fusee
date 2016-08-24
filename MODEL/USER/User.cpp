#include<MODEL/USER/User.h>

//COSTRUTTORE
User::User(Profilo* p,Network* n,Login* l): profile(p), net(n), login(l) {}

//METODI GET
Profilo* User::getProfile() const {return profile;}
Network* User::getNetwork() const {return net;}
Login* User::getLogin() const {return login;}

//SET
/*void setProfile(const Qstring& name, const Qstring& surname,bool sex,const QDate& date,
                    const Residenza& address,const Qstring& country,const Qstring& mail){
    profile->setInfo1(name,surname,sex,date,country);
    profile->setInfo2(address,language,mail);
}*/

//GET CAMPI DATI
const QString& User::getUsername() const{return login->getUsername();}
const QString& User::getPassword() const {return login->getPsw();}

const QString& User::getNome() const{return profile->getInfo1().getNome();}
const QString& User::getCognome() const{return profile->getInfo1().getCognome();}
bool User::getSesso() const{return profile->getInfo1().getSesso();}
QString User::getSessoString() const{return profile->getInfo1().getSessoString();}
const QDate& User::getData() const{return profile->getInfo1().getData();}
QString User::getDataString() const{return profile->getInfo1().getDataString();}
const QString& User::getNazione() const{return profile->getInfo1().getNazione();}

const Residenza& User::getResidenza() const{return profile->getInfo2().getResidenza();}
const QString& User::getProf() const {return profile->getInfo2().getProfessione();}
const QString& User::getNum() const {return profile->getInfo2().getNumero();}
const QString& User::getMail() const{return profile->getInfo2().getMail();}

const Container<QString>& User::getDiary() const{return profile->getInfo3().getDiary();}

const Container<QString>& User::getFollowers() const{return net->getFollowers();}
const Container<QString>& User::getFollowing() const{return net->getFollowing();}
const QString& User::getLevel() const{return net->getLevel();}

//DISTRUTTORE
User::~User(){
    delete profile;
    delete net;
    delete login;
}



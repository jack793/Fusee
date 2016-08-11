#include<MODEL/MODEL_DATA/Admin.h>

//COSTRUTTORE
Admin::Admin(Database* db) {pdb=db;}

//GET
User* Admin::getUser(const QString& user) const {return pdb->findUser(user);}

//METODI
void Admin::rmUser(const QString& user) {pdb->dtorUser(user);}

void Admin::addUser(const QString& user, const QString& password, int tipo, const QString& nome, const QString& cognome){
    pdb->newUser(user, password, tipo, nome, cognome);
}

void Admin::changeType(const QString& user, User* u){
    pdb->changeLevelUser(user, u);
}

bool Admin::matchUser(const QString& user) const{
    return pdb->matchUser(user);
}

bool Admin::dbEmpty() const {return pdb->dbEmpty();}

std::list<const User*> Admin::search(const QString& text) const{
    std::list<const User*> ris;
    
    for(Database::db_const_iterator cit=pdb->begin(); cit!=pdb->end(); ++it){
        if
    }
}


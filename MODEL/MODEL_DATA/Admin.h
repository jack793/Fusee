#ifndef ADMIN_H
#define ADMIN_H

#include<list>

#include<MODEL/MODEL_DATA/Database.h>

class Admin{
private:
    Database *pdb;
public:
    Admin(Database* db)
    
    void rmUser(const QString& user);
    void addUser(const QString& user, const QString& password, int tipo, const QString& nome, const QString& cognome);
    void changeType(const QString& user,User* u);
    User* getUser(const QString& user) const;
    bool matchUser(const QString& user) const;
    std::list<const User*> search(const QString& text) const;
    bool dbEmpty() const;
    
    Database::db_iterator begin();
    Database::db_iterator end();
    Database::db_const_iterator begin() const;
    Database::db_const_iterator end() const;
};

#endif // ADMIN_H

#ifndef MED_H
#define MED_H

#include "User.h"

class Med: public User{
public:
    Med(Profilo* p=0,Network* n=0,Login* l=0);
    
    virtual QString toString() const;
    virtual QString info() const;
    virtual void writeLevel(QXmlStreamWriter& xmlWriter) const;
    virtual bool search(User* user,const QString& text,const QString& category) const;
};

#endif


#ifndef NEWBIE_H
#define NEWBIE_H

#include "User.h"

class Newbie: public User{
public:
    Newbie(Profilo* p=0,Network* n=0,Login* l=0);
    
    virtual QString toString() const;
    virtual QString info() const;
    virtual void writeType(QXmlStreamWriter& xmlWriter) const;
    virtual bool search(const Utente* user,const QString& text,const QString& category) const;
};

#endif



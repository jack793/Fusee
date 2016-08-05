#ifndef PRO_H
#define PRO_H

#include "User.h"

class Pro: public User{
public:
    Pro(Profilo* p=0,Network* n=0,Login* l=0);
    
    virtual QString toString() const;
    virtual QString info() const;
    virtual void writeTipo(QXmlStreamWriter& xmlWriter) const;
    virtual bool ricerca(const Utente* user,const QString& text,const QString& category) const;
};

#endif

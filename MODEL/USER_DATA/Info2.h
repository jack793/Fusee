#ifndef INFO2_H
#define INFO2_H

#include<QXmlStreamReader>
#include<QString>

#include<MODEL/USER_DATA/Residenza.h>

class Info2{
private:
    Residenza residenza;
    QString professione;
    QString numero;
    QString mail;
public:
    Info2(const Residenza& res=Residenza(), const QString& prof="", const QString& num="", const QString& ml="");
    
    const Residenza& getResidenza() const;
    const QString& getProfessione() const;
    const QString& getNumero() const;
    const QString& getMail() const;
    
    void setResidenza(const Residenza& res);
    void setProfessione(const QString& prof);
    void setNumero(const QString& num);
    void setMail(const QString& ml);
    
    static Info2 readInfo2(QXmlStreamReader& );
};

#endif // INFO2_H

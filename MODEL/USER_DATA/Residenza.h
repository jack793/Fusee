#ifndef RESIDENZA_H
#define RESIDENZA_H

#include<QXmlStreamReader>

class Residenza{
private:
    QString regione;
    QString indirizzo;
public:
    Residenza(const QString& r="", const QString& p="");
    
    QString getRegione() const;
    QString getIndirizzo() const;
    
    static Residenza readResidenza(QXmlStreamReader& );
};

#endif // RESIDENZA_H

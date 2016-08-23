#ifndef RESIDENZA_H
#define RESIDENZA_H

#include<QXmlStreamReader>

class Residenza{
private:
    QString regione;
    QString paese;
    QString indirizzo;
public:
    Residenza(const QString& r="", const QString& p="", const QString& i="");
    
    const QString& getRegione() const;
    const QString& getPaese() const;    
    const QString& getIndirizzo() const;
    
    static Residenza readResidenza(QXmlStreamReader& );
};

#endif // RESIDENZA_H

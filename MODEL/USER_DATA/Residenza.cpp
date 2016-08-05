#include<MODEL/USER_DATA/Residenza.h>

//COTRUTTORE
Residenza::Residenza(const QString& r, const QString& p): regione(r), indirizzo(p) {}

//GET
QString Residenza::getRegione() const{return regione;}
QString Residenza::getIndirizzo() const{return indirizzo;}

Residenza Residenza::readResidenza(QXmlStreamReader& xmlReader){
    QString regione="Unknown";
    QString indirizzo="Unknown";
    
    while(!xmlReader.isEndElement() || !(xmlReader.name()=="residenza")){
        if(xmlReader.isStartElement()){
            if(xmlReader.name()=="regione"){regione=xmlReader.readElementText();}
            else if(xmlReader.name()=="indirizzo"){indirizzo=xmlReader.readElementText();}
        }
        xmlReader.readNext();
    }
    return Residenza(regione,indirizzo);
}

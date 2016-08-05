#include<MODEL/USER_DATA/Info2.h>

//COSTRUTTORE
Info2::Info2(const Residenza& res, const QString& prof, const QString& num, const QString& ml):
    residenza(res), professione(prof), numero(num), mail(ml) {}

//GET
const Residenza& Info2::getResidenza() const{return residenza;}
const QString& Info2::getProfessione() const{return professione;}
const QString& Info2::getNumero() const{return numero;}
const QString& Info2::getMail() const{return mail;}

//SET
void Info2::setResidenza(const Residenza& res) {residenza=res;}
void Info2::setProfessione(const QString& prof) {professione=prof;}
void Info2::setNumero(const QString& num) {numero=num;}
void Info2::setMail(const QString& ml) {mail=ml;}

//LETTURA IN DATABASE
Info2 Info2::readInfo2(QXmlStreamReader& xmlReader){
    Residenza residenza;
    QString professione="Unknown";
    QString numero="Unknown";
    QString mail="Unknown";
    
    while(!xmlReader.isEndElement() || !(xmlReader.name()=="info2")){
        if(xmlReader.isStartElement()){
            if(xmlReader.name()=="residenza"){residenza=Residenza::readResidenza(xmlReader);}
            else if(xmlReader.name()=="professione"){professione=xmlReader.readElementText();}
            else if(xmlReader.name()=="numero"){numero=xmlReader.readElementText();}
            else if(xmlReader.name()=="mail"){mail=xmlReader.readElementText();}
        }
        xmlReader.readNext();
    }
    return Info2(residenza,professione,numero,mail);
}

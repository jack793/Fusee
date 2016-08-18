#include<MODEL/USER_DATA/Info1.h>

//COSTRUTTORE
Info1::Info1(const QString& n, const QString& c, const bool s, const QDate& d, const QString& nz):
    nome(n), cognome(c), sesso(s), dataNascita(d), nazione(nz){}

//GET
const QString& Info1::getNome() const{return nome;}
const QString& Info1::getCognome() const{return cognome;}
bool Info1::getSesso() const{return sesso;}
QString Info1::getSessoString() const{
    if(sesso) return "F";
    else return "M";
}
const QDate& Info1::getData() const{return dataNascita;}
QString Info1::getDataString() const{return dataNascita.toString("d/M/yyyy");}
const QString& Info1::getNazione() const{return nazione;}

//SET
void Info1::setNome(const QString& n) {nome=n;}
void Info1::setCognome(const QString& c) {cognome=c;}
void Info1::setSesso(bool s) {sesso=s;}
void Info1::setData(const QDate& d) {data=d;}
void Info1::setNazione(const QString &nz) {nazione=nz;}

//LETTURA IN DATABASE
Info1 Info1::readInfo1(QXmlStreamReader& xmlReader){
    QString nome="Unknown";
    QString cognome="Unknown";
    bool sesso=0;   //maschio per default
    QString dataNascita="1/1/1910";
    QString nazione="Unknown";
    
    while(!xmlReader.isEndElement() || !(xmlReader.name()=="info1")){
        if(xmlReader.isStartElement()){
            if(xmlReader.name()=="nome"){nome=xmlReader.readElementText();}
            else if(xmlReader.name()=="cognome"){cognome=xmlReader.readElementText();}
            else if(xmlReader.name()=="sesso"){
                if(xmlReader.readElementText()=="M") sesso=0; //è maschio?
                else sesso=1;
            }
            else if(xmlReader.name()=="data"){dataNascita=xmlReader.readElementText();}
            else if(xmlReader.name()=="nazione"){nazione=xmlReader.readElementText();}
        }
        xmlReader.readNext();
    }
    QDate date(QDate::fromString(dataNascita,"d/M/yyyy"));
    return (Info1(nome,cognome,sesso,date,nazione));
}

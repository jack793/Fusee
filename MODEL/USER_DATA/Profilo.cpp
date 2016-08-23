#include<MODEL/USER_DATA/Profilo.h>

//COSTRUTTORE
Profilo::Profilo(const Info1 &i1, const Info2 &i2, const Info3 &i3): base(i1), lavorative(i2), social(i3) {}

//GET
const Info1& Profilo::getInfo1() const{return base;}
const Info2& Profilo::getInfo2() const{return lavorative;}
const Info3& Profilo::getInfo3() const{return social;}

//SET
void Profilo::setInfo1(const QString& name, const QString& surname, bool sex, const QDate& date, const QString& country){
    base.setNome(name);
    base.setCognome(surname);
    base.setSesso(sex);
    base.setData(date);
    base.setPaese(country);
}

void Profilo::setInfo2(const Residenza& res, const QString& profession, const QString& number, const QString& mail){
    lavorative.setResidenza(res);
    lavorative.setProfessione(profession);
    lavorative.setNumero(number);
    lavorative.setMail(mail);
}

void Profilo::setInfo3(const Container<QString>& dy){
    social.setDiary(dy);
}

//LETTURA IN DB
Profilo* Profilo::readProfilo(QXmlStreamReader& xmlReader){
    Info1 info1;
    Info2 info2;
    Info3 info3;
    
    while(!xmlReader.isEndElement() || !(xmlReader.name()=="profilo")){
        if(xmlReader.name()=="info1"){info1=Info1::readInfo1(xmlReader);}
        else if(xmlReader.name()=="info2"){info2=Info2::readInfo2(xmlReader);}
        else if(xmlReader.name()=="info3"){info3=Info3::readInfo3(xmlReader);}
        xmlReader.readNext();
    }
    return new Profilo(info1,info2,info3);
}

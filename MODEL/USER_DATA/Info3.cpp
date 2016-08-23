#include<MODEL/USER_DATA/Info3.h>

//COSTRUTTORE
Info3::Info3(const Container<QString>& dy): diario(dy) {}

//GET
const Container<QString>& Info3::getDiary() const {return diario;}

//SET
void Info3::setDiary(const Container<QString>& dy) {diario=dy;}

//altri metodi..

bool Info3::matchNote(const QString& text) const
{
    for(Container<QString>::Iterator it=diario.begin(); it!=diario.end(); ++it)
    {
        if(diario[it].contains(text,Qt::CaseInsensitive))
            return true;
    }
    return false;
}

//LETTURA IN DB
Info3 Info3::readInfo3(QXmlStreamReader& xmlReader){
    //var temporanea
    Container<QString> diario;
    while(!xmlReader.isEndElement() || !(xmlReader.name()=="info3")){
        if(xmlReader.isStartElement())
            if(xmlReader.name()=="post") {diario.push_back(xmlReader.readElementText());}
        xmlReader.readNext();
    }
    return Info3(diario);
}

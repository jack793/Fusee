#include<MODEL/USER/Med.h>

Med::Med(Profilo* p, Network* n, Login* l): User(p,n,l) {}

QString Med::toString() const{
    return "Med";
}

Qstring Med::info() const{
    QString info_txt;
    info_txt.append("Un utente <span style='font-style: italic'>Med</span> può pubblicare delle note fino ad un massimo di 500 caratteri. <br/>");
    info_txt.append("Le tue funzionalità non ti soddisfano? <br/>");
    info_txt.append("Aumenta i tuoi seguaci per passare di livello ed ottenere quindi maggiori features!!=) <br/>");
    return info_txt;
}

void Newbie::writeType(QXmlStreamWriter& xmlWriter) const{
    xmlWriter.writeTextElement("tipo","1");
}


#include<MODEL/USER/Newbie.h>

//COSTRUTTORE
Newbie::Newbie(Profilo *p, Network* n, Login *l): User(p,n,l) {}

//METODI PROPRI
QString Newbie::toString() const{
    return "Newbie";
}

QString Newbie::info() const{
    QString info_txt;
    info_txt.append("Un utente <span style='font-style: italic'>Newbie</span> è abilitato solamente a pubblicare delle note da 200 caratteri massimo. <br/>");
    info_txt.append("Le tue funzionalità non ti soddisfano? <br/>");
    info_txt.append("Aumenta i tuoi seguaci per passare di livello ed ottenere quindi maggiori features!!=) <br/>");
    return info_txt;
}

void Newbie::writeType(QXmlStreamWriter& xmlWriter) const{
    xmlWriter.writeTextElement("tipo","0");
}

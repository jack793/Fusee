#include<MODEL/USER/Pro.h>

//COSTRUTTORE
Pro::Pro(Profilo* p, Network* n, Login* l): User(p,n,l) {}

//METODI PROPRI
QString Pro::toString() const{
    return "Pro";
}

QString Pro::info() const{
    QString info_txt;
    info_txt.append("Un utente <span style='font-style: italic'>Pro</span> non ha limiti per la pubblicazione di note. <br/>");
    info_txt.append("inoltre un utente pro ha la funzionalità aggiuntiva di poter caricare un foto.<br/>");
    return info_txt;
}

void Newbie::writeType(QXmlStreamWriter& xmlWriter) const{
    xmlWriter.writeTextElement("tipo","2");
}


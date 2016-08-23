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

void Med::writeLevel(QXmlStreamWriter& xmlWriter) const{
    xmlWriter.writeTextElement("level","Med");
}

bool Med::search(User* user, const QString& text, const QString& category) const
{
    std::cout<<std::endl<<"Ricerca utente Med"<<user->getLogin()->getUsername().toStdString()<<std::endl;
    
    if((category=="Tutto") || (category=="Username") && (user->getUsername().contains(text,Qt::CaseInsensitive)))
    {
        std::cout<<"Username match"<<std::endl;
        return true;
    }
    else if((category=="Tutto") || (category=="Nome") && (user->getNome().contains(text, Qt::CaseInsensitive)))
    {
        std::cout<<"Nome match"<<std::endl;
        return true;
    }
    else if((category=="Tutto") || (category=="Cognome") && (user->getCognome().contains(text, Qt::CaseInsensitive)))
    {
        std::cout<<"Cognome match"<<std::endl;
        return true;
    }
    else
        return false;
}


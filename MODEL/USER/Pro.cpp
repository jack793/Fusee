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

void Pro::writeLevel(QXmlStreamWriter& xmlWriter) const{
    xmlWriter.writeTextElement("level","Pro");
}

bool Pro::search(User *user, const QString &text, const QString &category) const
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
    else if((category=="Tutto") || (category=="Nazione") && (user->getNazione().contains(text,Qt::CaseInsensitive)))
    {
        std::cout<<"Nazione match"<<std::endl;
        return true;
    }
    else if((category=="Tutto") || (category=="Regione") && (user->getResidenza().getRegione().contains(text,Qt::CaseInsensitive)))
    {
        std::cout<<"Regione match"<<std::endl;
        return true;
    }
    else if((category=="Tutto") || (category=="Paese") && (user->getResidenza().getPaese().contains(text,Qt::CaseInsensitive)))
    {
        std::cout<<"Paese match"<<std::endl;
        return true;
    }
    else
        return false;
}


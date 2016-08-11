#include<MODEL/MODEL_DATA/Database.h>

QString Database::filename"../Database.xml";

//COSTRUTTORE E DISTRUTTORE
Database::Database() { Load(); }
Database::~Database(){ Close(); }

//METODI PROPRI

bool Database::isEmpty() const {return FuseeDb.isEmpty();}

bool Database::verifyUser(const QString& username, const QString& psw ) const{
    for(Container<User*>::Iterator it=FuseeDb.begin(); it!=FuseeDb.end(); ++it){
        if(FuseeDb[it]->getUsername()==username && FuseeDb[it]->getPassword()==psw)
            return true;
    }
    return false;
}

//non so se è giusta¿¿
void Database::dtorUser(User* u){
    delete *u;
    FuseeDb.pop_element(u);
}

void Database::addUser(User* u){
    if(!matchUser(u->getUsername())){   //se non esiste già
        Profilo* p=new Profilo(Info1(nome,cognome), Info2()); //crea primo campo dati di un User
        Network* n=new Network(std::list<QString>(),std::list<QString>()); //secondo campo dati
        Login* l=new Login(user, psw); //terzo campo dati
        
        //si parte sempre da livello Newbie(il più basso)
        User* new=new Newbie(p,n,l);
        FuseeDb.push_front(new);
        
        //pulisco heap
        delete p;
        delete n;
        delete l;
        delete new;
    }
}

bool Database::matchUser(const QString& u) const{
    //Cerca in tutto il contenitore un elemento con una chiave uguale a quella passata 
    for(Container<User*>::Iterator it=FuseeDb.begin(); it!=FuseeDb.end(); ++it)
        if(FuseeDb[it]->getUsername()==u) return true;
    return false;
}

User* Database::getUser(const QString &user, const QString& psw) const{
    for(Container<User*>::Iterator it=FuseeDb.begin(); it!=FuseeDb.end(); ++it)
    {
        if(FuseeDb[it]->getUsername()==u && FuseeDb[it]->getPassword()==psw) //se corrisponde
            return FuseeDb[it]; //resituisco l'user trovato
    }
    return 0; //senno un puntatore nullo
}

void Database::changeLevelUser(User* u){
    if(matchUser(u->getUsername())){ //matcha l'utente a cui cambiare il livello
        //ne preleva i dati aggiornati prima di distruggere il nodo dell'user nel db
        User* old=getUser(u->getUsername(),u->getPassword());
        
        Profilo* p=old->getProfile();
        Network* n=old->getNetwork();
        Login* l=old->getLogin();
        
        FuseeDb.pop_element(u);
    }
    
    if(matchUser(user)){ //matcha l'utente a cui cambiare il livello
        //ne preleva i dati aggiornati prima di distruggere il nodo di questo utente nel db
        User* old=db[user];
        
        Profilo* p=old->getProfile();
        Network* n=old->getNetwork();
        Login* l=old->getLogin();
        
        db.erase(user);
        
        //ESEGUE CONTROLLI PER IL LIVELLO DA ATTRIBUIRE IN BASE AL NUMERO DI FOLLOWERS!
        int numeroFollowers = u->getNetwork()->getFollowers().size();
        if( numeroFollowers < 3) //da 0 a 2
            db[user]=new Newbie(p,n,l);
        else if( numeroFollowers >2 && numeroFollowers < 6) //da 3 a 5
            db[user]=new Med(p,n,l);
        else if(numeroFollowers > 5) // da 5 in su
            db[user]=new Pro(p,n,l);
        
        old=p=n=l=0; //azzero puntatori che alla chiusura sarebbe garbage altrimenti
    }
}

void Database::printUser(const User* u) const{
    std::count<<std::endl<<u->getUsername().toStdString()<<std::endl;
    std::count<<u->getNome().toStdString();
    std::count<<" "<<u->getCognome().toStdString()<<std::endl<<std::endl;
}

//CARICAMENTO E SALVATAGGIO DEL DATABASE

//Caricamento
void Database::Load(){
    //variabili temporanee
    QString username="Unknown";
    QString password="Unknown";
    int tipo=0;
    Profilo* p=0;
    Network* n=0;
    Login* l=0;
    
    QFile file(filename);
    if (!file.open(QFile::ReadOnly | QFile::Text)) //per problemi con apertura file
        std::cout<<"Error: Cannot read file"<<std::endl;
    
    QXmlStreamReader xmlReader(&file);
    xmlReader.readNext();
    
    while (!xmlReader.atEnd())
    {
        if(xmlReader.isStartElement())
        {
            //legge il tag dal .xml
            if(xmlReader.name()="database" || xmlReader.name()="user")
                xmlReader.readNext();
            
            else if(xmlReader.name()="login"){
                l=Login::readLogin(xmlReader);
                username=l->getUsername();
                password=l->getPsw();
            }
            
            else if(xmlReader.name()="tipo")
                tipo=xmlReader.readElementText().toInt();
            
            else if(xmlReader.name()="profilo")
                p=Profilo::readProfilo(xmlReader);
            
            else if(xmlReader.name()="network")
                n=Network::readNetwork(xmlReader);
            
            else // c'è un problema di lettura (non riconosce alcun tag del .xml?)
                std::count<<"Houston, we got a problem..";
            
        }
        
        else //legge la chiusura di un tag nel .xml ( </tag> )
        {
            if(xmlReader.isEndElement() && xmlReader.name()=="user")
            {
                if(tipo==0)
                    db[username]=new Newbie(p,n,l);
                else if(tipo==1)
                    db[username]=new Med(p,n,l);
                else if(tipo==2)
                    db[username]=new Pro(p,n,l);
                
                //resetto
                tipo=0;
                username="Unknown";
                password="Unknown";
                
                xmlReader.readNext();
            }
            
            else //legge vuoto o un EndElement != da "user"
                xmlReader.readNext();
        }
    }
    std::count<<std::endl<<"read database"<<std::endl;
    file.close();
}

//Salvataggio
void Database::Close(){
    
    Qfile file(filename);
    file.open(QIODevice::WriteOnly);
    
    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    
    xmlWriter.writeStartElement("database");
    
    std::map<QString,User*>::const_iterator cit=db.begin(); // auto it=db.begin() ?¿
    for(; cit!=db.end(); ++cit){
        
        xmlWriter.writeStartElement("user");
        
        xmlWriter.writeStartElement("login");//<login>
            xmlWriter.writeTextElement("username",(cit->first)); //Writes a text element with qualifiedName and text.
            xmlWriter.writeTextElement("password",cit->second->getPsw());
        xmlWriter.writeEndElement();    //</login>
        
        (cit->second)->writeTipo(xmlWriter); //SCRITTURA POLIMORFA DEL TIPO
        
        xmlWriter.writeStartElement("profilo");//<profilo>
        
            xmlWriter.writeStartElement("info1");   //<info1>
                xmlWriter.writeTextElement("nome",cit->second->getNome());
                xmlWriter.writeTextElement("cognome",cit->second->getCognome());
                xmlWriter.writeTextElement("sesso",cit->second->getSessoString());
                xmlWriter.writeTextElement("data", cit->second->getDataString());
                xmlWriter.writeTextElement("paese", cit->second->getPaese());
            xmlWriter.writeEndElement();            //</info1>
        
            xmlWriter.writeStartElement("info2");   //<info2>
                xmlWriter.writeStartElement("residenza");   //<residenza>
                    xmlWriter.writeTextElement("regione", cit->second->getResidenza().getRegione());
                    xmlWriter.writeTextElement("indirizzo", cit->second->getResidenza().getIndirizzo());
                xmlWriter.writeEndElement();                //</residenza>
                xmlWriter.writeTextElement("professione", cit->second->getProfessione());
                xmlWriter.writeTextElement("numero",cit->second->getNumero());
                xmlWriter.writeTextElement("mail", cit->second->getMail());
            xmlWriter.writeEndElement();            //</info2>
            
        xmlWriter.writeEndElement();        //</profilo>
        
        xmlWriter.writeStartElement("network");//<network>
            if(cit->second->getNetwork()){
                std::list<QString> followers=(cit->second->getNetwork()->getFollowers());
                std::list<QString>::const_iterator citFlwe=followers.begin();
                for(; citFlwe!=followers.end(); ++citFlwe){
                    std::map<QString, User*>::const_iterator citMap=db.find(*citFlwe); //lo trova
                    if(citFlwe!=db.end()) //se esiste (cioè se la find sopra non da end)
                        xmlWriter.writeTextElement("follower", *citFlwe);
                }
                
                std::list<QString> following=(cit->second->getNetwork()->getFollowing());
                std::list<QString>::const_iterator citFlwi=following.begin();
                for(; citFlwi!=following.end(); ++citFlwi){
                    std::map<QString, User*>::const_iterator citMap=db.find(*citFlwi); //lo trova
                    if(citFlwi!=db.end()) //se esiste (cioè se la find sopra non da end)
                        xmlWriter.writeTextElement("following", *citFlwi);
                }
            }
        xmlWriter.writeEndElement();           //</network>
        
        xmlWriter.writeEndElement();//</user>   
                
    }
    
    xmlWriter.writeEndElement();//</database>
    
    xmlWriter.writeEndDocument();
    
    file.close();
    std::count<<std::endl<<"database written"<<std::endl;
}

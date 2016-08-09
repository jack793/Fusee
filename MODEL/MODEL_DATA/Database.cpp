#include<MODEL/MODEL_DATA/Database.h>

QString Database::filename"../Database.xml";

//COSTRUTTORE
Database::Database() { Load(); }

//DISTRUTTORE
Database::~Database(){
    Close();
    for(db_const_iterator cit=db.begin(); cit!=db.end(); ++cit)
        dtorUser(cit->first);
}

//METODI PROPRI
Database::db_iterator Database::begin() {return db.begin();}
Database::db_iterator Database::end() {return db.end();}

Database::db_const_iterator Database::begin() const {return db.begin();}
Database::db_const_iterator Database::end() const {return db.end();}

bool Database::dbEmpty() const {return db.empty();}

void Database::dtorUser(const QString& user){
    delete db.find(user)->second;
    db.erase(user);
}

void Database::newUser(const QString& user,const QString& psw, int tipo, const QString& nome, const QString& cognome){
    if(!matchUser(user)){
        Profilo* p=new Profilo(Info1(nome,cognome), Info2()); //crea primo campo dati di un generico User
        Network* n=new Network(std::list<QString>(),std::list<QString>()); //secondo campo dati
        Login* l=new Login(user, psw); //terzo campo dati
        
        //si parte sempre da livello Newbie(il più basso)
        db[user]=new Newbie(p,n,l);
    }
}

bool Database::matchUser(const QString& user) const{
    //Cerca in tutto il contenitore un elemento con una chiave uguale a quella passata,
    //se non la trova ritorna un iteratore equiv. a map::end 
    if(db.find(user)!=db.end()) 
        return true;
    else
        return false;
}

void Database::changeLevelUser(const QString& user, User* u){
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

User* Database::findUser(const QString& user) const{
    if(matchUser(user))
        return db.find(user)->second;
    else
        return 0;
}

void Database::printUser(const User* u) const{
    std::count<<std::endl<<u->getUsername().toStdString()<<std::endl;
    std::count<<u->getNome().toStdString();
    std::count<<" "<<u->getCognome().toStdString()<<std::endl<<std::endl;
}

//CARICAMENTO E CHIUSURA DEL DATABASE

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

//Chiusura
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
        
        xmlWriter.writeTextElement("username",(cit->first)); //Writes a text element with qualifiedName and text.
        xmlWriter.writeTextElement("password",cit->second->getPsw());
        (cit->second)->writeTipo(xmlWriter);//???????????
        
        xmlWriter.writeStartElement("profilo");
        
        xmlWriter.writeTextElement("nome",cit->second->getNome());
        xmlWriter.writeTextElement("cognome",cit->second->);
        
    }
}

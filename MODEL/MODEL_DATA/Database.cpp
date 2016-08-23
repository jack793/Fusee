#include<MODEL/MODEL_DATA/Database.h>

QString Database::filename"../Fusee/Database.xml";

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

//true sse esiste username associato ad un utente nel db
bool Database::matchUser(const QString& u) const{
    //Cerca in tutto il contenitore un elemento con una chiave (username) uguale a quella passata 
    for(Container<User*>::Iterator it=FuseeDb.begin(); it!=FuseeDb.end(); ++it)
        if(FuseeDb[it]->getUsername()==u) return true;
    return false;
}

//torna un puntatore a quell'utente
User* Database::getUser(const QString& user, const QString& psw) const{
    for(Container<User*>::Iterator it=FuseeDb.begin(); it!=FuseeDb.end(); ++it)
    {
        if(FuseeDb[it]->getUsername()==u && FuseeDb[it]->getPassword()==psw) //se corrisponde
            return FuseeDb[it]; //restituisco l'user trovato
    }
    return 0; //senno un puntatore nullo
}

void Database::updateLevelUser(User* u){
    User* toUpdate=getUser(u->getUsername(),u->getPassword());
    if(toUpdate)//se getUser ha trovato..
    {
        unsigned int numflwe=u->getNetwork()->getFollowers().size();
        toUpdate->getNetwork()->updateLevel(numflwe);
    }   
}

//di prova 
void Database::printUser(const User* u) const{
    std::count<<std::endl<<u->getUsername().toStdString()<<std::endl;
    std::count<<u->getNome().toStdString();
    std::count<<" "<<u->getCognome().toStdString()<<std::endl<<std::endl;
}

//CARICAMENTO E SALVATAGGIO DEL DATABASE

//Caricamento
void Database::Load(){
    
    //variabili temporanee
    QString livello="";
    Profilo* p=0;
    Network* n=0;
    Login* l=0;
    
    QFile dbFile(filename);
    if (!dbFile.open(QFile::ReadOnly | QFile::Text)) //per problemi con apertura file
        std::cout<<"Error: Cannot read the database file"<<std::endl;
    
    QXmlStreamReader xmlReader(&dbFile);
    xmlReader.readNext();
    
    while (!xmlReader.atEnd())
    {
        if(xmlReader.isStartElement())
        {
            //legge il tag d'apertura dal .xml
            if(xmlReader.name()="database" || xmlReader.name()="user")
                xmlReader.readNext();
            
            else if(xmlReader.name()="login"){
                l=Login::readLogin(xmlReader);
                username=l->getUsername();
                password=l->getPsw();
            }
            
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
                livello=n->getLevel();
                if(livello=="Newbie")
                {
                    User* newbie=new Newbie(p,n,l);
                    FuseeDb.push_back(newbie);
                }   
                else if(livello=="Med")
                {
                    User* med=new Med(p,n,l);
                    FuseeDb.push_back(med);
                }
                else if(livello=="Pro")
                {
                    User* pro=new Pro(p,n,l);
                    FuseeDb.push_back(pro);
                }

                //resetto
                livello="";
                p=n=l=0;
                
                xmlReader.readNext();
            }
            
            else //legge vuoto o un EndElement != da "user"
                xmlReader.readNext();
        }
    }
    std::count<<std::endl<<"read database"<<std::endl;
    dbFile.close();
}

//Salvataggio
void Database::Close(){
    
    Qfile dbFile(filename);
    file.open(QIODevice::WriteOnly);
    
    QXmlStreamWriter xmlWriter(&dbFile);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    
    xmlWriter.writeStartElement("database");
    
    if(!FuseeDb.isEmpty()) //se è vuoto non fa nulla
        for(Container<User*>::Iterator it=FuseeDb.begin(); it!=FuseeDb.end(); ++it)    
        xmlWriter.writeStartElement("user");
        
        xmlWriter.writeStartElement("login");//<login>
            xmlWriter.writeTextElement("username",FuseeDb[it]->getUsername()); //Writes a text element with qualifiedName and text.
            xmlWriter.writeTextElement("password",FuseeDb[it]->getPassword());
        xmlWriter.writeEndElement();    //</login>
        
        xmlWriter.writeStartElement("profilo");//<profilo>
        
            xmlWriter.writeStartElement("info1");   //<info1>
                xmlWriter.writeTextElement("nome",FuseeDb[it]->getNome());
                xmlWriter.writeTextElement("cognome",FuseeDb[it]->getCognome());
                xmlWriter.writeTextElement("sesso",FuseeDb[it]->getSessoString());
                xmlWriter.writeTextElement("data",FuseeDb[it]->getDataString());
                xmlWriter.writeTextElement("paese",FuseeDb[it]->getPaese());
            xmlWriter.writeEndElement();            //</info1>
        
            xmlWriter.writeStartElement("info2");   //<info2>
                xmlWriter.writeStartElement("residenza");   //<residenza>
                    xmlWriter.writeTextElement("regione", FuseeDb[it]->getResidenza().getRegione());
                    xmlWriter.writeTextElement("indirizzo", FuseeDb[it]->getResidenza().getIndirizzo());
                xmlWriter.writeEndElement();                //</residenza>
                xmlWriter.writeTextElement("professione", FuseeDb[it]->getProfessione());
                xmlWriter.writeTextElement("numero",FuseeDb[it]->getNumero());
                xmlWriter.writeTextElement("mail", FuseeDb[it]->getMail());
            xmlWriter.writeEndElement();            //</info2>
            
        xmlWriter.writeEndElement();        //</profilo>
        
        xmlWriter.writeStartElement("network");//<network>
            if(FuseeDb[it]->getNetwork()){
                
                FuseeDb[it]->writeLevel(xmlWriter);//SCRITTURA POLIMORFA DEL LIVELLO
                        
                Container<QString> followers=(FuseeDb[it]->getNetwork()->getFollowers());
                Container<QString>::Iterator itFlwe=followers.begin();
                for(; itFlwe!=followers.end(); ++itFlwe)
                    xmlWriter.writeTextElement("follower", followers[itFlwe]);
                
                Container<QString> following=(FuseeDb[it]->getNetwork()->getFollowing());
                Container<QString>::Iterator itFlwi=following.begin();
                for(; itFlwi!=following.end(); ++itFlwi)
                    xmlWriter.writeTextElement("following", following[itFlwi]);
            }
                
            
        xmlWriter.writeEndElement();           //</network>
        
        xmlWriter.writeEndElement();//</user>   
                
    }
    
    xmlWriter.writeEndElement();//</database>
    
    xmlWriter.writeEndDocument();
    
    file.close();
    std::count<<std::endl<<"database written"<<std::endl;
}

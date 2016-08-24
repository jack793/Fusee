#include <QApplication>

#include<MODEL/MODEL_DATA/Database.h>
#include<VIEW/startView.h>

int main(int argc, char *argv[])
{
    //La classe QApplication controlla il flusso di esecuzione della GUI    
	QApplication Fusee(argc, argv);
    
    //Database
    Database database;

    //Finestra Principale    
    StartView startView;
    
    //Il main passa il controllo a QT    
    return Fusee.exec();

}



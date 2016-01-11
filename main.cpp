#include <QApplication>

#include "MainWindow.h"

int main(int argc, char *argv[])
{
    //La classe QApplication controlla il flusso di esecuzione della GUI    
	QApplication Fusee(argc, argv);

    //Finestra Principale    
    MainWindow mainWindow;

    //Il main passa il controllo a QT    
    return mainWindow.exec();

}



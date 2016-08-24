#ifndef FUSEECONTROLLER_H
#define FUSEECONTROLLER_H

#include <QObject>
#include <string>

#include<VIEW/startView.h>
#include<VIEW/loginView.h>


class FuseeController: public QObject{
public:
    FuseeController();
    ~FuseeController();
};

#endif // FUSEECONTROLLER_H

#ifndef USERDATAVIEW_H
#define USERDATAVIEW_H

#include <QWidget>
#include <QScrollArea>
#include <QLabel>
#include <QRadioButton>
#include <QString>
#include <QFrame>
#include <QFont>
#include <QGridLayout>

#include<MODEL/USER/User.h>

class userDataView: public QScrollArea
{
    Q_OBJECT
private:
    const User* user;
    QFrame* ScrollArea;
    QLabel* usernameLabel;
    QLabel*
};

#endif // USERDATAVIEW_H

#ifndef MAINWINDOWCONTROLLER_H
#define MAINWINDOWCONTROLLER_H

#include <QObject>

#include "MainWindowModel.h"
#include "MainWindowView.h"

class MainWindowController : public QObject
{
    Q_OBJECT

private:

    MainWindowModel* Model;
    MainWindowView* View;

public slots:

    void showAdmin()const;
    void showLoginMember()const;

public:
    MainWindowController(MainWindowModel* = new MainWindowModel,
                         MainWindowView* = new MainWindowView);

    void showUI();

    ~MainWindowController();


};

#endif // MAINWINDOWCONTROLLER_H

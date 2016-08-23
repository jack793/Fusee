#ifndef STARTVIEW_H
#define STARTVIEW_H

#include <QWidget>
#include <QApplication>
#include <QDesktopWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

class StartView: public QWidget
{
    Q_OBJECT
private:
    QLabel* welcomeTitle;
    QPushButton* loginPButton;
    QPushButton* registerPButton;
    
    void centerWindow(int,int);    
public:
    StartView();
    ~StartView();
private slots:
    void loadLogin();
    void loadRegistration();
signals:
    void signalLogin();
    void signalRegistration();
};

#endif // STARTVIEW_H

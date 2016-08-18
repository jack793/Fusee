#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QWidget>
#include <QDesktopWidget>

class mainview : public QWidget {
    Q_OBJECT
private:
    void centraWidget();
public:
    explicit mainview(QWidget *parent = 0);
    virtual ~mainview();
    virtual void caricaGrafica() =0;
};

#endif // MAINVIEW_H

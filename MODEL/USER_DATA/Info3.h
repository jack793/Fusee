#ifndef INFO3_H
#define INFO3_H

#include<QXmlStreamReader>
#include<QString>

#include<MODEL/MODEL_DATA/Container.h>

class Info3{
private:
    Container<QString> diario;
public:
    Info3(const Container<QString>& dy=Container::Container() );
    
    const Container<QString>& getDiary() const;
    unsigned int getSizeD() const;
    
    void setDiary(const Container<QString>& dy);
    bool matchNote(const QString& text) const;
    
    void addNote(const QString& text);
    
    static Info3 readInfo3(QXmlStreamReader& );
};

#endif // INFO3_H

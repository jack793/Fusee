#ifndef INFO1_H
#define INFO1_H

#include<QDate>
#include<QString>

#include<MODEL/USER_DATA/Residenza.h>

class Info1{
private:
    QString nome;
    QString cognome;
    bool sesso;
    QDate dataNascita;
public:
    Info1(const QString& n="Unknown", const QString& c="Unknown", const bool s=0, const QDate& d=QDate(1970,1,1) );
    
    const QString& getNome() const;
    const QString& getCognome() const;
    bool getSesso() const
    QString getSessoString() const;
    const QDate& getData() const;
    QString getDataString() const;
    
    void setNome(const QString& n);
    void setCognome(const QString& c);
    void setSesso(bool s);
    void setData(const QDate& d);  
    
    static Info1 readInfo1(QXmlStreamReader& );
    
};

#endif // INFO1_H
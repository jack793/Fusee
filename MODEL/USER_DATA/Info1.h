#ifndef INFO1_H
#define INFO1_H

#include<QXmlStreamReader>
#include<QDate>
#include<QString>

class Info1{
private:
    QString nome;
    QString cognome;
    bool sesso;
    QDate dataNascita;
    QString nazione;
public:
    Info1(const QString& n="Unknown", const QString& c="Unknown", const bool s=0, const QDate& d=QDate(1970,1,1), const QString& nz="" );
    
    const QString& getNome() const;
    const QString& getCognome() const;
    bool getSesso() const;
    QString getSessoString() const;
    const QDate& getData() const;
    QString getDataString() const;
    const QString& getNazione() const;
    
    void setNome(const QString& n);
    void setCognome(const QString& c);
    void setSesso(bool s);
    void setData(const QDate& d);  
    void setNazione(const QString& nz);
    
    static Info1 readInfo1(QXmlStreamReader& );
    
};

#endif // INFO1_H

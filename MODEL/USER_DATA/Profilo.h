#ifndef PROFILO_H
#define PROFILO_H

#include<MODEL/USER_DATA/Info1.h>
#include<MODEL/USER_DATA/Info2.h>
#include<MODEL/USER_DATA/Info3.h>

class Profilo{
private:
    Info1 base;
    Info2 lavorative;
    Info3 social;
public:
    Profilo(const Info1& i1, const Info2& i2, const Info3& i3);
    const Info1& getInfo1() const;
    const Info2& getInfo2() const;
    const Info3& getInfo3() const;

    void setInfo1(const QString& name, const QString& surname, bool sex, const QDate& date, const QString& country);
    void setInfo2(const Residenza& res, const QString& profession,
                  const QString& number, const QString& mail);
    void setInfo3(const Container<QString>& dy);
    
    static Profilo* readProfilo(QXmlStreamReader& );
};

#endif // PROFILO_H

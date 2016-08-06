#ifndef PROFILO_H
#define PROFILO_H

#include<UDATA/info1.h>
#include<UDATA/info2.h>
#include<UDATA/info3.h>

class Profilo{
private:
    Info1 base;
    Info2 lavorative;
public:
    Profilo(const Info1& i1, const Info2& i2, const Info3& i3);
    const Info1& getInfo1() const;
    const Info2& getInfo2() const;

    void setInfo1(const QString& name, const QString& surname, bool sex, const QDate& date, const QString& country);
    void setInfo2(const Residenza& res, const QString& profession,
                  const QString& number, const QString& mail,);
    
    static Profilo* readProfilo(QXmlStreamReader& );
};

#endif // PROFILO_H

#ifndef USER_H
#define USER_H


#include <QString>

class User: public Profile
{
public:
    User( const QString &) = 0;
    virtual ~User();
};
#endif //USER_H

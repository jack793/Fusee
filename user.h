#ifndef USER_H
#define USER_H


#include <QString>

class user: public profile
{
public:
    user( const QString &) = 0;
    virtual ~user();
};
#endif //USER_H

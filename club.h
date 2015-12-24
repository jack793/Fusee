#ifndef CLUB_H
#define CLUB_H


#include <QString>

class club: public profile
{
public:
    club( const QString &) = 0;
    virtual ~club();
};
#endif //CLUB_H

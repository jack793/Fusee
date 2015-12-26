#ifndef CLUB_H
#define CLUB_H


#include <QString>

//Club classe virtuale
class Club: public Profile
{
public:
    Club( const QString &) = 0;
    virtual ~Club();
};
#endif //CLUB_H

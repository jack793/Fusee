#ifndef CONTAINER_H
#define CONTAINER_H
#include <QString>

template<class T>
class Container
{
public:
    Container();
    Container(const QString&, const T&);
    Container(nodo<T>* =new nodo() );
    
    
    
}
#endif // CONTAINER_H

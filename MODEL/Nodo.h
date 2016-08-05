#ifndef NODO_H
#define NODO_H
#include <QString>

template<class T>
class nodo{
public:
    nodo(const QString& s ="", const T& i =T(), nodo<T>* n =0);
    ~nodo();

    //GET
    QString getUser() const;
    T getInfo() const;
    nodo<T>* getNext() const;

    //SET
    void setUser(const QString& u);
    void setInfo(const T& i);
    void setNext(const nodo<T>* n);

private:
    QString user;
    T info;
    nodo* next;
};
template<class T>
nodo<T>::nodo(const QString& u, const T& i, nodo<T>* n): user(u),info(i), next(n){}

template<class T>
nodo<T>::~nodo(){if(next) delete next; }


//GET
template<class T>
QString nodo<T>::getUser() const{ return user;}

template<class T>
T nodo<T>::getInfo() const{ return info; }

template<class T>
nodo<T>* nodo<T>::getNext() const{ return next;}


//SET
template<class T>
void nodo<T>::setInfo(const T &i){ info=i;}

template<class T>
void nodo<T>::setUser(const QString& u){ user=u;}

template<class T>
void nodo<T>::setNext(const nodo<T>* n){next=n;}

#endif // NODO_H

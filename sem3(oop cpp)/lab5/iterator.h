//
// Created by mikarkon on 18.12.22.
//

#ifndef LAB4_ITERATOR_H
#define LAB4_ITERATOR_H

#include "arr.h"
template<typename T>
class iterator
{
    int idx;
    arr<T>* vec;
public:
    iterator(int i, arr<T>* anArr);
    iterator(iterator &other);
    iterator &operator=(const iterator &other);
    T& operator*();
    arr<T>* operator->();
    iterator &operator++(); //prefix
    iterator operator++(int); //postfix
    bool operator==(iterator &other);
    bool operator!=(iterator &other);
};

template<typename T>
iterator<T>::iterator(int i, arr<T> *anArr) : idx(i), vec(anArr){};

template<typename T>
iterator<T>::iterator(iterator<T> &other) : idx(other.idx), vec(other.vec){};

template<typename T>
iterator<T> &iterator<T>::operator=(const iterator<T> &other) {
    if(this!= &other)
    {
        idx = other.idx;
        vec = other.vec;
    }
    return *this;
}
template<typename T>
T &iterator<T>::operator*() {
    return (*vec)[idx];
}

template<typename T>
arr<T>* iterator<T>::operator->() {
    return vec;
}

template<typename T>
iterator<T> &iterator<T>::operator++() {
    idx++;
    return *this;
}

template<typename T>
iterator<T> iterator<T>::operator++(int) {
    iterator copy = (*this);
    ++(*this);
    return copy;
}

template<typename T>
bool iterator<T>::operator==(iterator<T> &other) {
    return idx==other.idx;
}
template<typename T>
bool iterator<T>::operator!=(iterator<T> &other) {
    return idx!=other.idx;
}
#endif //LAB4_ITERATOR_H

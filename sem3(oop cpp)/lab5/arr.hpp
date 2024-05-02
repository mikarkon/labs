//
// Created by mikarkon on 18.12.22.
//

#ifndef LAB4_ARR_H
#define LAB4_ARR_H
#include <iostream>

template<typename T>
class iterator;

template<typename T>
class arr {
private:
    int amount;
    int capacity;
    T* ptr;

    void resize(int newSize);
public:
    arr();
    explicit arr(int size);
    arr(const arr<T>& other);
    arr(arr<T>&& other) noexcept;

    arr<T> &operator=(const arr<T>& other);
    arr<T> &operator=(arr<T>&& other) noexcept;

    T &operator[](int idx) const;
    int getAmount() const;
    void pushback(T element);
    iterator<T> begin();
    iterator<T> end();
    ~arr();
};

template<typename T>
arr<T>::arr() : amount(0), capacity(1), ptr(new T[1]){};

template<typename T>
arr<T>::arr(int size) : amount(size), capacity(size), ptr(new T[size]) {};

template<typename T>
arr<T>::arr(const arr<T>& other): amount(other.amount), capacity(other.capacity), ptr(new T[amount])
{
    for(int i = 0; i < amount; i++)
        ptr[i] = other.ptr[i];
}

template<typename T>
arr<T>::arr(arr<T>&& other) noexcept : amount(other.amount), capacity(other.capacity), ptr(other.ptr)
{
    other.ptr = nullptr;
    other.amount = 0;
    other.capacity = 0;
}

template<typename T>
arr<T> &arr<T>::operator=(const arr<T> &other){
    if(this != &other)
    {
        amount = other.amount;
        capacity = other.capacity;
        T* newPtr = new T[amount];
        for(int i = 0; i < amount; i++)
            newPtr[i] = other.ptr[i];
        delete[] ptr;
        ptr = newPtr;
    }
    return *this;
}

template<typename T>
arr<T> &arr<T>::operator=(arr<T>&& other) noexcept
{
    if(this != &other)
    {
        delete[] ptr;
        amount = other.amount;
        capacity = other.capacity;
        ptr = other.ptr;
        other.amount = 0;
        other.capacity = 0;
        other.ptr = nullptr;
    }
    return *this;
}

template<typename T>
T &arr<T>::operator[](int idx) const
{
    if(idx < amount)
        return ptr[idx];
    throw std::invalid_argument("Wrong idx");
}

template<typename T>
void arr<T>::resize(int newSize)
{
    T* newPtr = new T[newSize];
    for(int i = 0; i < amount; i++)
        newPtr[i] = ptr[i];
    delete[] ptr;
    ptr = newPtr;
    capacity = newSize;
}

template<typename T>
int arr<T>::getAmount() const
{
    return amount;
}

template<typename T>
void arr<T>::pushback(T element)
{
    if(amount == capacity)
        resize(capacity * 2);
    ptr[amount++] = element;
}

template<typename T>
iterator<T> arr<T>::begin()
{
    return iterator<T>(0, this);
}

template<typename T>
iterator<T> arr<T>::end()
{
    return iterator<T>(amount, this);
}
template<typename T>
arr<T>::~arr()
{
    delete[] ptr;
    capacity = 0; amount = 0;
}
#endif //LAB4_ARR_H

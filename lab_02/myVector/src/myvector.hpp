#ifndef _MY_VECTOR_HPP_
#define _MY_VECTOR_HPP_

#include "myvector.h"

template<typename T>
MyVector<T>::MyVector(size_t sz) : capacity(sz)
{
    allocate(sz);
}

template<typename T>
MyVector<T>::MyVector(size_t sz, const T *arr)
{
    if (!arr)
        throw; // TODO EXCEPTION

    allocate(sz);
    // TODO IMPLEMENT
}

template<typename T>
bool MyVector<T>::isEmpty() const
{
    return size == 0;
}

template<typename T>
void MyVector<T>::clear()
{
    data.reset();
    size = 0;
    capacity = 0; // TODO LOW-LVL?
}

template<typename T>
void MyVector<T>::allocate(size_t sz)
{
    data = std::shared_ptr<T[]>(new T[sz]); // TODO ADD MEM ALLOCATION CHECK
    capacity = sz;
}

template<typename T>
void MyVector<T>::pushBack(const T &value)
{
    if (size + 1 > capacity) // TODO
        throw;

    data[size++] = value;
}

template<typename T>
typename MyVector<T>::Iter MyVector<T>::begin()
{
    return Iterator<T>(*this);
}

template<typename T>
typename MyVector<T>::Iter MyVector<T>::end()
{
    return Iterator<T>(*this, size);
}

#endif // _MY_VECTOR_HPP_

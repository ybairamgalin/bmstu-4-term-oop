#ifndef __ITERATOR_HPP__
#define __ITERATOR_HPP__

#include "iterator.h"

template<typename T>
Iterator<T>::Iterator(MyVector<T> &vector, size_t pos) :
        ptr(vector.getData()), index(pos) { }

template<typename T>
Iterator<T>::Iterator(const Iterator<T> &iter) :
        ptr(iter.ptr), index(iter.index) { }

template<typename T>
Iterator<T>::Iterator(Iterator<T> &&iter) noexcept :
        ptr(iter.ptr), index(iter.index) { }

template<typename T>
Iterator<T> &Iterator<T>::operator=(const Iterator<T> &iter)
{
    index = iter.index;
    ptr = iter.ptr;

    return *this;
}

template<typename T>
Iterator<T> &Iterator<T>::operator++()
{
    index++;

    return *this;
}

template<typename T>
Iterator<T> Iterator<T>::operator++(int)
{
    Iterator<T> tmp(*this);
    index++;

    return tmp;
}

template<typename T>
bool Iterator<T>::operator==(const Iterator<T> &iter) const
{
    return ptr.lock() == iter.ptr.lock() && index == iter.index;
}

template<typename T>
bool Iterator<T>::operator!=(const Iterator<T> &iter) const
{
    return !(*this == iter);
}

template<typename T>
T &Iterator<T>::operator*()
{
    return ptr.lock()[index];
}

template<typename T>
T *Iterator<T>::operator->()
{
    return &(ptr.lock()[index]);
}

#endif // __ITERATOR_HPP__

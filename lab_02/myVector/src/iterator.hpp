#ifndef __ITERATOR_HPP__
#define __ITERATOR_HPP__

#include "iterator.h"

template<typename T>
Iterator<T>::Iterator(MyVector<T> &vector, size_t pos)
{
    ptr = vector.data;
    index = pos;
}

template<typename T>
Iterator<T>::Iterator(const Iterator<T> &iter)
{
    index = iter.index;
    ptr = iter.ptr;
}

template<typename T>
Iterator<T>::Iterator(Iterator<T> &&iter) noexcept
{
    index = iter.index;
    ptr = iter.ptr;
}

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
    return ptr == iter.ptr && index == iter.index;
}

#endif // __ITERATOR_HPP__

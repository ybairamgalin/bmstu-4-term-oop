#ifndef __CONST_ITERATOR_HPP__
#define __CONST_ITERATOR_HPP__

#include "constiterator.h"
#include "myvectorexceptions.h"

template<typename T>
ConstIterator<T>::ConstIterator(const MyVector<T> &vector, size_t pos) :
        ptr(vector.getData()), index(pos) { }

template<typename T>
ConstIterator<T>::ConstIterator(const ConstIterator<T> &iter) :
        ptr(iter.ptr), index(iter.index) { }

template<typename T>
ConstIterator<T>::ConstIterator(ConstIterator<T> &&iter) noexcept :
        ptr(iter.ptr), index(iter.index) { }

template<typename T>
ConstIterator<T> &ConstIterator<T>::operator=(const ConstIterator<T> &iter)
{
    ptr = iter.ptr;
    index = iter.index;

    return *this;
}

template<typename T>
ConstIterator<T> &ConstIterator<T>::operator++()
{
    index++;

    return *this;
}

template<typename T>
ConstIterator<T> ConstIterator<T>::operator++(int)
{
    ConstIterator<T> tmp(*this);
    index++;

    return tmp;
}

template<typename T>
bool ConstIterator<T>::operator==(const ConstIterator<T> &iter) const
{
    if (ptr.expired() || iter.ptr.expired())
    {
        time_t currTime = std::time(nullptr);
        throw DataExpired(__FILE__, typeid(*this).name(), __LINE__,
                               ctime(&currTime));
    }

    return ptr.lock() == iter.ptr.lock() && index == iter.index;
}

template<typename T>
bool ConstIterator<T>::operator!=(const ConstIterator<T> &iter) const
{
    return !(*this == iter);
}

template<typename T>
const T &ConstIterator<T>::operator*()
{
    if (ptr.expired())
    {
        time_t currTime = std::time(nullptr);
        throw DataExpired(__FILE__, typeid(*this).name(), __LINE__,
                          ctime(&currTime));
    }

    return ptr.lock()[index];
}

template<typename T>
const T *ConstIterator<T>::operator->()
{
    if (ptr.expired())
    {
        time_t currTime = std::time(nullptr);
        throw DataExpired(__FILE__, typeid(*this).name(), __LINE__,
                          ctime(&currTime));
    }

    return &(ptr.lock()[index]);
}

#endif //__CONST_ITERATOR_HPP

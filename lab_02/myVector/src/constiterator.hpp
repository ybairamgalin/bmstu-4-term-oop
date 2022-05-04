#ifndef __CONST_ITERATOR_HPP__
#define __CONST_ITERATOR_HPP__

#include "constiterator.h"
#include "myvectorexceptions.h"

template<typename T>
ConstIterator<T>::ConstIterator(const MyVector<T> &vector, size_t pos) :
        BaseIterator<T>(pos, vector.size()), ptr(vector.getData())
{
    if (pos > vector.size())
    {
        time_t currTime = std::time(nullptr);
        throw IndexOutOfRange(__FILE__, typeid(*this).name(), __LINE__,
                              ctime(&currTime));
    }
}

template<typename T>
ConstIterator<T> &ConstIterator<T>::operator=(const ConstIterator<T> &iter)
{
    ptr = iter.ptr;
    maxIndex = iter.maxIndex;
    index = iter.index;

    return *this;
}

template<typename T>
ConstIterator<T> &ConstIterator<T>::operator++()
{
    if (index >= maxIndex)
    {
        time_t currTime = std::time(nullptr);
        throw IndexOutOfRange(__FILE__, typeid(*this).name(), __LINE__,
                              ctime(&currTime));
    }

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
const T &ConstIterator<T>::operator*() const
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
const T *ConstIterator<T>::operator->() const
{
    if (ptr.expired())
    {
        time_t currTime = std::time(nullptr);
        throw DataExpired(__FILE__, typeid(*this).name(), __LINE__,
                          ctime(&currTime));
    }

    return &(ptr.lock()[index]);
}

template<typename T>
ConstIterator<T>::operator bool() const noexcept
{
    return !ptr.expired();
}

#endif //__CONST_ITERATOR_HPP

#ifndef __ITERATOR_HPP__
#define __ITERATOR_HPP__

#include "myvectorexceptions.h"
#include "iterator.h"

template<typename T>
Iterator<T>::Iterator(MyVector<T> &vector, size_t pos) :
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
Iterator<T> &Iterator<T>::operator=(const Iterator<T> &iter)
{
    index = iter.index;
    ptr = iter.ptr;
    maxIndex = iter.maxIndex;

    return *this;
}

template<typename T>
Iterator<T> &Iterator<T>::operator++()
{
    if (!isValidIndexDiff(1))
    {
        time_t currTime = std::time(nullptr);
        throw IndexOutOfRange(__FILE__, typeid(*this).name(), __LINE__,
                          ctime(&currTime));
    }

    index++;

    return *this;
}

template<typename T>
Iterator<T> Iterator<T>::operator++(int)
{
    if (!isValidIndexDiff(1))
    {
        time_t currTime = std::time(nullptr);
        throw IndexOutOfRange(__FILE__, typeid(*this).name(), __LINE__,
                              ctime(&currTime));
    }

    Iterator<T> tmp(*this);
    index++;

    return tmp;
}

template<typename T>
Iterator<T> &Iterator<T>::operator--()
{
    if (!isValidIndexDiff(-1))
    {
        time_t currTime = std::time(nullptr);
        throw IndexOutOfRange(__FILE__, typeid(*this).name(), __LINE__,
                              ctime(&currTime));
    }

    index -= 1;

    return *this;
}

template<typename T>
Iterator<T> Iterator<T>::operator--(int)
{
    if (!isValidIndexDiff(-1))
    {
        time_t currTime = std::time(nullptr);
        throw IndexOutOfRange(__FILE__, typeid(*this).name(), __LINE__,
                              ctime(&currTime));
    }

    Iterator<T> tmp(*this);
    index -= 1;

    return tmp;
}

template<typename T>
bool Iterator<T>::operator==(const Iterator<T> &iter) const
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
bool Iterator<T>::operator!=(const Iterator<T> &iter) const
{
    return !(*this == iter);
}

template<typename T>
T &Iterator<T>::operator*()
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
T *Iterator<T>::operator->()
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
const T &Iterator<T>::operator*() const
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
const T *Iterator<T>::operator->() const
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
template<class NumType>
Iterator<T> &Iterator<T>::operator+=(NumType num)
{
    if (!isValidIndexDiff(num))
    {
        time_t currTime = std::time(nullptr);
        throw IndexOutOfRange(__FILE__, typeid(*this).name(), __LINE__,
                               ctime(&currTime));
    }

    index += num;

    return *this;
}

template<typename T>
template<class NumType>
Iterator<T> Iterator<T>::operator+(NumType num) const
{
    if (!isValidIndexDiff(num))
    {
        time_t currTime = std::time(nullptr);
        throw IndexOutOfRange(__FILE__, typeid(*this).name(), __LINE__,
                              ctime(&currTime));
    }

    if (index + num > maxIndex)
    {
        time_t currTime = std::time(nullptr);
        throw IndexOutOfRange(__FILE__, typeid(*this).name(), __LINE__,
                              ctime(&currTime));
    }

    Iterator<T> result(*this);
    result.index += num;

    return result;
}

template<typename T>
template<class NumType>
Iterator<T> &Iterator<T>::operator-=(NumType num)
{
    if (!isValidIndexDiff(-num))
    {
        time_t currTime = std::time(nullptr);
        throw IndexOutOfRange(__FILE__, typeid(*this).name(), __LINE__,
                              ctime(&currTime));
    }

    index -= num;

    return *this;
}

template<typename T>
template<class NumType>
Iterator<T> Iterator<T>::operator-(NumType num) const
{
    if (!isValidIndexDiff(-num))
    {
        time_t currTime = std::time(nullptr);
        throw IndexOutOfRange(__FILE__, typeid(*this).name(), __LINE__,
                              ctime(&currTime));
    }

    Iterator<T> result(*this);
    result.index -= num;

    return result;
}

template<typename T>
Iterator<T>::operator bool() const noexcept
{
    return !ptr.expired();
}

template<typename T>
template<class NumType>
bool Iterator<T>::isValidIndexDiff(NumType diff) const
{
    bool valid = true;

    if (index + diff > maxIndex)
        valid = false;

    if (diff < 0 && std::abs(diff) > index)
        valid = false;

    return valid;
}

template<typename T>
bool Iterator<T>::equal(const Iterator<T> &iter) const
{
    return *this == iter;
}

template<typename T>
bool Iterator<T>::nequal(const Iterator<T> &iter) const
{
    return !(*this == iter);
}

template<typename T>
template<typename NumType>
const T &Iterator<T>::operator[](NumType index) const
{
    return *(*this + index);
}

template<typename T>
template<typename NumType>
T &Iterator<T>::operator[](NumType index)
{
    return *(*this + index);
}

template<typename T>
std::ptrdiff_t Iterator<T>::operator-(const Iterator<T> &other) const
{
    return index - other.index;
}

template<typename T, typename NumType>
Iterator<T> operator+(NumType num, const Iterator<T> &iter)
{
    return iter + num;
}

#endif // __ITERATOR_HPP__

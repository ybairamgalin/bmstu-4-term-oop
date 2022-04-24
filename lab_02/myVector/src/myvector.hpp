#ifndef _MY_VECTOR_HPP_
#define _MY_VECTOR_HPP_

#include <ctime>

#include "myvector.h"
#include "myvectorexceptions.h"

template<typename T>
MyVector<T>::MyVector(size_t size)
{
    sz = size;
    allocate(size);
}

template<typename T>
MyVector<T>::MyVector(const MyVector::Vector &vector)
{
    allocate(vector.capacity);
    sz = vector.sz;
    std::copy_n(vector.cbegin(), sz, begin());
}

template<typename T>
MyVector<T>::MyVector(size_t size, const T *arr)
{
    if (!arr)
    {
        time_t currTime = std::time(nullptr);
        throw NullPtrException(__FILE__, typeid(*this).name(), __LINE__,
                               ctime(&currTime));
    }

    allocate(size);
    sz = size;
    std::copy_n(arr, sz, begin());
}

template<typename T>
bool MyVector<T>::isEmpty() const
{
    return sz == 0;
}

template<typename T>
void MyVector<T>::clear()
{
    data.reset();
    sz = 0;
    capacity = 0; // TODO LOW-LVL?
}

template<typename T>
void MyVector<T>::allocate(size_t size)
{
    data = std::shared_ptr<T[]>(new T[size]()); // TODO ADD MEM ALLOCATION CHECK
    capacity = size;
}

template<typename T>
void MyVector<T>::pushBack(const T &value)
{
    if (sz >= capacity) // TODO
        reallocate();

    data[sz++] = value;
}

template<typename T>
typename MyVector<T>::Iter MyVector<T>::begin()
{
    return Iterator<T>(*this);
}

template<typename T>
typename MyVector<T>::Iter MyVector<T>::end()
{
    return Iterator<T>(*this, sz);
}

template<typename T>
typename MyVector<T>::Vector &MyVector<T>::operator+(MyVector::Vector &vec)
{
    MyVector<T> newVector(*this);
    newVector += vec;

    return newVector;
}

template<typename T>
typename MyVector<T>::Vector &MyVector<T>::operator+=(MyVector::Vector &other)
{
    if (sz != other.sz)
        throw;

    for (Iter a = begin(), b = other.begin(); a != end() && b != other.end();
         a++, b++)
        *a += *b;

    return *this;
}

template<typename T>
size_t MyVector<T>::size()
{
    return sz;
}

template<typename T>
T &MyVector<T>::operator[](size_t index)
{
    if (index >= sz)
    {
        time_t currTime = std::time(nullptr);
        throw IndexOutOfRange(__FILE__, typeid(*this).name(), __LINE__,
                               ctime(&currTime));
    }

    return *Iterator<T>(*this, index);
}

template<typename T>
void MyVector<T>::reallocate()
{
    Vector tmp(*this);

    capacity *= 2;
    allocate(capacity);

    std::copy(tmp.cbegin(), tmp.cend(), begin());
}

template<typename T>
typename MyVector<T>::CIter MyVector<T>::cbegin() const
{
    return CIter(*this);
}

template<typename T>
typename MyVector<T>::CIter MyVector<T>::cend() const
{
    return CIter(*this, sz);
}

template<typename T>
bool MyVector<T>::operator==(MyVector::Vector &vec) const
{
    if (this == &vec)
        return true;

    if (sz != vec.sz)
        return false;

    bool equal = true;

    for (CIter a = cbegin(), b = vec.cbegin(); a != cend() && equal;
            ++a, ++b)
        if (*a != *b)
            equal = false;

    return equal;
}

template<typename T>
bool MyVector<T>::operator!=(MyVector::Vector &vec) const
{
    return !(*this == vec);
}

#endif // _MY_VECTOR_HPP_

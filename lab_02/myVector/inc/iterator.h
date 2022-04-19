#ifndef __ITERATOR_H__
#define __ITERATOR_H__

template <typename T>
class MyVector;

template <typename T>
class Iterator
{
    typedef std::weak_ptr<T> pointer;
public:
    explicit Iterator(MyVector<T> &vector, size_t pos = 0);

    Iterator(const Iterator<T> &iter);
    Iterator(Iterator<T> &&iter) noexcept;
    Iterator<T> &operator=(const Iterator<T> &iter);

    Iterator<T> &operator++();
    Iterator<T> operator++(int);

    bool operator==(const Iterator<T> &iter) const;
private:
    pointer ptr;
    size_t index;
};

#include "iterator.hpp"

#endif

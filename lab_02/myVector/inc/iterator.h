#ifndef __ITERATOR_H__
#define __ITERATOR_H__

template <typename T>
class MyVector;

template <typename T>
class Iterator
{
    using iterator_category = std::output_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = std::weak_ptr<T[]>;
    using reference = T&;
public:
    explicit Iterator(MyVector<T> &vector, size_t pos = 0);
    Iterator(const Iterator<T> &iter);
    Iterator(Iterator<T> &&iter) noexcept;

    Iterator<T> &operator=(const Iterator<T> &iter);

    Iterator<T> &operator++();
    Iterator<T> operator++(int);

    bool operator==(const Iterator<T> &iter) const;
    bool operator!=(const Iterator<T> &iter) const;

    T &operator*();
    T* operator->();
private:
    pointer ptr;
    size_t index;
};

#include "iterator.hpp"

#endif // __ITERATOR_H__

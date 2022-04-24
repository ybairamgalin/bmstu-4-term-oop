//
// Created by Yaroslav Bairamgalin on 23.04.2022.
//

#ifndef __CONST_ITERATOR_H__
#define __CONST_ITERATOR_H__

template <typename T>
class MyVector;

template<typename T>
class ConstIterator
{
public:
    using iterator_category = std::input_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = std::weak_ptr<T[]>;
    using reference = T&;

    explicit ConstIterator(const MyVector<T> &vector, size_t pos = 0);
    ConstIterator(const ConstIterator<T> &iter);
    ConstIterator(ConstIterator<T> &&iter) noexcept;

    ConstIterator<T> &operator=(const ConstIterator<T> &iter);

    ConstIterator<T> &operator++();
    ConstIterator<T> operator++(int);

    bool operator==(const ConstIterator<T> &iter) const;
    bool operator!=(const ConstIterator<T> &iter) const;

    const T& operator*();
    const T* operator->();

private:
    pointer ptr = nullptr;
    size_t index;
};

#include "constiterator.hpp"

#endif //__CONST_ITERATOR_H__

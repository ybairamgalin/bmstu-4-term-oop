#ifndef __CONST_ITERATOR_H__
#define __CONST_ITERATOR_H__

#include "baseiterator.h"

template <typename T>
class MyVector;

template<typename T>
class ConstIterator : public BaseIterator<T>
{
    using BaseIterator<T>::index;
    using BaseIterator<T>::maxIndex;
public:
    using iterator_category = std::input_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = std::weak_ptr<const T[]>;
    using reference = T&;

    explicit ConstIterator(const MyVector<T> &vector, size_t pos = 0);
    ConstIterator(const ConstIterator<T> &iter) = default;
    ConstIterator(ConstIterator<T> &&iter) noexcept = default;
    ~ConstIterator() override = default;

    ConstIterator<T> &operator=(const ConstIterator<T> &iter);

    ConstIterator<T> &operator++();
    ConstIterator<T> operator++(int);

    bool operator==(const ConstIterator<T> &iter) const;
    bool operator!=(const ConstIterator<T> &iter) const;

    const T& operator*() const override;
    const T* operator->() const override;
    explicit operator bool() const noexcept override;

private:
    pointer ptr;
};

#include "constiterator.hpp"

#endif //__CONST_ITERATOR_H__

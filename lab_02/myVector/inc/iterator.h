#ifndef __ITERATOR_H__
#define __ITERATOR_H__

#include "baseiterator.h"

template <typename T>
class MyVector;


template <typename T>
class Iterator : public BaseIterator<T>
{
    using BaseIterator<T>::index;
    using BaseIterator<T>::maxIndex;
public:
    using iterator_category = std::random_access_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = std::weak_ptr<T[]>;
    using reference = T&;

    explicit Iterator(MyVector<T> &vector, size_t pos = 0);
    Iterator(const Iterator<T> &iter) = default;
    Iterator(Iterator<T> &&iter) noexcept = default;
    ~Iterator() override = default;

    Iterator<T> &operator=(const Iterator<T> &iter);

    Iterator<T> &operator++();
    Iterator<T> operator++(int);

    template<class NumType>
    Iterator<T>& operator+=(NumType num);

    template<class NumType>
    Iterator<T> operator+(NumType num) const;

    Iterator<T> &operator--();
    Iterator<T> operator--(int);

    template<class NumType>
    Iterator<T>& operator-=(NumType num);

    std::ptrdiff_t operator-(const Iterator<T> &other) const;

    template<class NumType>
    Iterator<T> operator-(NumType num) const;

    bool operator==(const Iterator<T> &iter) const;
    bool equal(const Iterator<T> &iter) const;
    bool operator!=(const Iterator<T> &iter) const;
    bool nequal(const Iterator<T> &iter) const;

    template<typename NumType>
    const T& operator[](NumType index) const;

    template<typename NumType>
    T& operator[](NumType index);

    T &operator*();
    const T& operator*() const override;
    T* operator->();
    const T* operator->() const override;
    explicit operator bool() const noexcept override;

protected:
    template<class NumType>
    bool isValidIndexDiff(NumType diff) const;

private:
    pointer ptr;
};

template<typename T, typename NumType>
Iterator<T> operator+(NumType num, const Iterator<T> &iter);

#include "iterator.hpp"

#endif // __ITERATOR_H__

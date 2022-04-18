#ifndef _MY_ITERATOR_
#define _MY_ITERATOR_

#include "myvector.hpp"

template <typename T>
class MyIterator : private std::iterator<std::random_access_iterator_tag, T>
{
    friend class MyVector<T>;

public:
    explicit MyIterator(const MyVector<T> &vector) noexcept;

    explicit MyIterator(const MyIterator<T> &iter) = default;
    explicit MyIterator(MyIterator<T> &&iter) noexcept = default;
    explicit MyIterator<T> &operator=(const MyIterator<T> &other);

    MyIterator<T> operator++();
    MyIterator<T> operator++(int);

    T& operator*();

private:
    std::weak_ptr<T[]> dataPtr;
    size_t currentIndex;
    size_t containerSize;
};

#endif

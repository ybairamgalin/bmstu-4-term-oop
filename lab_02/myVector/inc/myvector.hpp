#include <__bit_reference>

#ifndef _MY_VECTOR_HPP_
#define _MY_VECTOR_HPP_

#include <iterator>
#include <memory>
#include "myiterator.hpp"


template <typename T>
class MyIterator;

template <typename T>
class MyVector
{
    friend class MyIterator<T>;
public:
    MyVector();
    ~MyVector() = default;

    MyVector(const MyVector<T> &vector);
    MyVector(MyVector<T> &&vector) noexcept;

    MyVector<T> &operator=(const MyVector<T> &);
    MyVector<T> &operator=(MyVector<T> &&) noexcept;

    explicit MyVector(int sz);

    size_t size() const noexcept;

    MyIterator<T> begin();
    MyIterator<T> end();


protected:
    void allocate(size_t sz);

private:
    size_t capacity;
    size_t sz;
    std::shared_ptr<T[]> data;
};

#endif // _MY_VECTOR_HPP_

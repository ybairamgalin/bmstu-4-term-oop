#ifndef __MY_VECTOR_H__
#define __MY_VECTOR_H__

#include <memory>
#include "basecontainer.h"
#include "iterator.h"
#include "constiterator.h"

template <typename T>
class MyVector : public BaseContainer
{
    typedef std::shared_ptr<T[]> pointer;
    typedef MyVector<T> Vector;
    typedef Iterator<T> Iter;
    typedef ConstIterator<T> CIter;
    using BaseContainer::sz;

    friend Iterator<T>;
    friend ConstIterator<T>;
public:

    MyVector() = default;
    MyVector(const Vector &vector);
    MyVector(Vector &&vector) noexcept = default;
    ~MyVector() override = default;

    explicit MyVector(size_t sz);
    explicit MyVector(size_t sz, const T* arr);

    [[nodiscard]] bool isEmpty() const override;
    void clear() override;

    bool operator==(Vector &vec) const;
    bool operator!=(Vector &vec) const;

    Vector& operator+(Vector &vec);
    Vector& operator+=(Vector &other);

    size_t size();

    Iter begin();
    Iter end();

    CIter cbegin() const;
    CIter cend() const;

    T& operator[](size_t index);

    void pushBack(const T &);
private:
    pointer data = nullptr;
    size_t capacity = 0;

    void reallocate();
    void allocate(size_t sz);
};

#include "myvector.hpp"

#endif // __MY_VECTOR_H__

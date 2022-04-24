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

    MyVector<T> &operator=(const Vector &vector);
    MyVector<T> &operator=(Vector &&vector) noexcept;

    explicit MyVector(size_t size);
    explicit MyVector(size_t size, const T* arr);

    [[nodiscard]] bool isEmpty() const override;
    void clear() override;

    bool operator==(const Vector &vec) const;
    bool operator!=(const Vector &vec) const;

    Vector operator-();

    Vector operator+(const Vector &vec) const;
    Vector& operator+=(const Vector &other);

    Vector operator-(const Vector &other) const;
    Vector& operator-=(const Vector &other);

    size_t size();

    Iter begin();
    Iter end();

    CIter cbegin() const;
    CIter cend() const;

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    void pushBack(const T &);

protected:
    size_t capacity = 0;
    static const size_t allocationStep = 10;

    void reallocate();
    void allocate(size_t size);
    pointer getData() const;
private:
    pointer data = nullptr;
};

#include "myvector.hpp"

#endif // __MY_VECTOR_H__

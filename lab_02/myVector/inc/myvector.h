#ifndef __MY_VECTOR_H__
#define __MY_VECTOR_H__

#include <memory>
#include <cmath>

#include "basecontainer.h"
#include "iterator.h"
#include "constiterator.h"

template <typename T>
class MyVector : public BaseContainer
{
    using pointer = std::shared_ptr<T[]>;
    using Vector = MyVector<T>;
    using Iter = Iterator<T>;
    using CIter = ConstIterator<T>;
    using BaseContainer::sz;

    friend Iterator<T>;
    friend ConstIterator<T>;
public:
    MyVector() = default;
    MyVector(const Vector &vector);
    MyVector(Vector &&vector) noexcept = default;
    ~MyVector() override = default;

    Vector& operator=(const Vector &vector);
    Vector& operator=(Vector &&vector) noexcept;

    explicit MyVector(size_t size);
    explicit MyVector(size_t size, const T* arr);

    bool isEmpty() const override;
    void clear() override;

    bool operator==(const Vector &vec) const;
    bool operator!=(const Vector &vec) const;

    Vector operator-();

    Vector operator+(const Vector &vec) const;
    Vector& operator+=(const Vector &other);

    Vector operator-(const Vector &other) const;
    Vector& operator-=(const Vector &other);

    Vector operator+(double number) const;
    Vector& operator+=(double number);

    Vector operator-(double number) const;
    Vector& operator-=(double number);

    Vector operator*(const Vector &other) const;
    Vector& operator*=(const Vector &other) const;

    Vector operator*(double number) const;
    Vector& operator*=(double number);

    double scalarProduct(const Vector &other) const;
    double length() const;

    double angle(const Vector &other) const;

    size_t size();

    Iter begin();
    Iter end();

    CIter begin() const;
    CIter end() const;

    CIter cbegin() const;
    CIter cend() const;

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    T& at(size_t index);
    const T& at(size_t index) const;

    void pushBack(const T &);
protected:
    static const size_t allocationStep = 10;
    size_t capacity = 0;

    void reallocate();
    void allocate(size_t size);
    pointer getData() const;
private:
    pointer data = nullptr;
};

template<typename T>
double scalarProduct(const MyVector<T> &first, const MyVector<T> &second);

template<typename T>
double angle(const MyVector<T> &first, const MyVector<T> &second);

#include "myvector.hpp"

#endif // __MY_VECTOR_H__

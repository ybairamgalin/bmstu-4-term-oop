#ifndef __MY_VECTOR_H__
#define __MY_VECTOR_H__

#include <memory>
#include <cmath>
#include <complex>

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
    explicit MyVector(const Vector &vector);
    MyVector(Vector &&vector) noexcept = default;
    MyVector(std::initializer_list<T> initializerList);
    explicit MyVector(size_t size);
    MyVector(size_t size, const T* arr);

    template<typename InputIt>
    MyVector(InputIt first, InputIt last);

    ~MyVector() override = default;

    Vector& operator=(const Vector &vector);
    Vector& operator=(Vector &&vector) noexcept;
    Vector& operator=(std::initializer_list<T> initializerList);

    bool isEmpty() const override;
    void clear() override;

    T& operator[](size_t index);
    T& at(size_t index);
    const T& operator[](size_t index) const;
    const T& at(size_t index) const;

    Iter begin();
    Iter end();

    CIter begin() const;
    CIter end() const;

    CIter cbegin() const;
    CIter cend() const;

    bool operator==(const Vector &vec) const;
    bool equals(const Vector &vec) const;
    bool operator!=(const Vector &vec) const;
    bool nequals(const Vector &vec) const;

    size_t size() const;
    std::complex<double> length() const;
    double angle(const Vector &other) const;

    Vector operator+(const Vector &vec) const;
    Vector& operator+=(const Vector &other);
    Vector add(const Vector &vec) const;
    void plus(const Vector &vec);

    Vector operator+(double number) const;
    Vector& operator+=(double number);
    Vector add(double number) const;
    void plus(double number);

    Vector operator-() const;
    Vector neg() const;
    void changeSign();

    Vector operator-(const Vector &other) const;
    Vector& operator-=(const Vector &other);
    Vector subtract(const Vector &other) const;
    void minus(const Vector &other);

    Vector operator-(double number) const;
    Vector& operator-=(double number);
    Vector subtract(double number) const;
    void minus(double number);

    Vector operator*(const Vector &other) const;
    Vector& operator*=(const Vector &other);
    Vector dotProduct(const Vector &other) const;
    void multiplyByVector(const Vector &other) const;

    Vector operator*(double number) const;
    Vector& operator*=(double number);
    Vector multiply(double number) const;
    void multiplyByNumber(double number);

    Vector elementMultiply(const Vector &other) const;
    void multiplyByElement(const Vector &other);
    double scalarProduct(const Vector &other) const;
    bool collinear(const Vector &other) const;
    bool orthogonal(const Vector &other) const;

    void setEps(double value);
    double getEps() const noexcept;
protected:
    void allocate(size_t size);
    pointer getData() const;
    double eps = 1e-6;
private:
    pointer data = nullptr;
};

template<typename T>
double scalarProduct(const MyVector<T> &first, const MyVector<T> &second);

template<typename T>
MyVector<T> elementMultiply(const MyVector<T> &first,
                            const MyVector<T> &second);

template<typename T>
double angle(const MyVector<T> &first, const MyVector<T> &second);

template<typename T>
double collinear(const MyVector<T> &first, const MyVector<T> &second);

template<typename T>
double orthogonal(const MyVector<T> &first, const MyVector<T> &second);

template<typename T>
MyVector<T> add(const MyVector<T> &first, const MyVector<T> &second);

template<typename T>
MyVector<T> subtract(const MyVector<T> &first, const MyVector<T> &second);

template<typename T>
MyVector<T> operator+(double number, const MyVector<T> &myVector);

template<typename T>
MyVector<T> operator-(double number, const MyVector<T> &myVector);

template<typename T>
MyVector<T> operator*(double number, const MyVector<T> &myVector);

#include "myvector.hpp"

#endif // __MY_VECTOR_H__

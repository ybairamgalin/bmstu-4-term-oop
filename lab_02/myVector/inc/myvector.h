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

    decltype(auto) length() const;
    double angle(const Vector &other) const;

    Vector operator+(const Vector &vec) const;
    Vector& operator+=(const Vector &other);
    Vector add(const Vector &vec) const;
    Vector& plus(const Vector &vec);

    template<typename NumType>
    decltype(auto) operator+(const NumType &number) const;

    template<typename NumType>
    Vector& operator+=(const NumType &number);

    template<typename NumType>
    decltype(auto) add(const NumType &number) const;

    template<typename NumType>
    Vector& plus(const NumType &number);

    Vector operator-() const;
    Vector neg() const;
    void changeSign();

    template<typename OtherVector>
    decltype(auto) operator-(const OtherVector &other) const;
    Vector& operator-=(const Vector &other);

    template<typename OtherVector>
    decltype(auto) subtract(const OtherVector &other) const;
    Vector& minus(const Vector &other);

    template<typename NumType>
    decltype(auto) operator-(const NumType& number) const;

    template<typename NumType>
    Vector& operator-=(const NumType& number);

    template<typename NumType>
    decltype(auto) subtract(const NumType& number) const;

    template<typename NumType>
    Vector& minus(const NumType& number);

    Vector operator*(const Vector &other) const;
    Vector& operator*=(const Vector &other);
    Vector dotProduct(const Vector &other) const;
    Vector& multiplyByVector(const Vector &other) const;

    template<typename NumType>
    decltype(auto) operator*(const NumType& number) const;

    template<typename NumType>
    Vector& operator*=(const NumType& number);

    template<typename NumType>
    Vector multiply(const NumType& number) const;

    template<typename NumType>
    Vector& multiplyByNumber(const NumType& number);

    decltype(auto) operator&(const Vector &other) const;
    decltype(auto) scalarProduct(const Vector &other) const;

    Vector operator%(const Vector &other) const;
    Vector& operator%=(const Vector &other);
    Vector elementMultiply(const Vector &other) const;
    Vector& multiplyByElement(const Vector &other);

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
bool collinear(const MyVector<T> &first, const MyVector<T> &second);

template<typename T>
bool orthogonal(const MyVector<T> &first, const MyVector<T> &second);

template<typename T>
MyVector<T> add(const MyVector<T> &first, const MyVector<T> &second);

template<typename T>
MyVector<T> subtract(const MyVector<T> &first, const MyVector<T> &second);

template<typename T, typename NumType>
MyVector<T> operator+(const NumType &number, const MyVector<T> &myVector);

template<typename T, typename NumType>
MyVector<T> operator-(const NumType &number, const MyVector<T> &myVector);

template<typename T, typename NumType>
MyVector<T> operator*(const NumType &number, const MyVector<T> &myVector);

#include "myvector.hpp"

#endif // __MY_VECTOR_H__

#ifndef _MY_VECTOR_HPP_
#define _MY_VECTOR_HPP_

#include <ctime>

#include "myvector.h"
#include "myvectorexceptions.h"

template<typename T>
MyVector<T>::MyVector(size_t size)
{
    if (size == 0)
    {
        time_t currTime = std::time(nullptr);
        throw EmptyVector(__FILE__, typeid(*this).name(), __LINE__,
                               ctime(&currTime));
    }

    sz = size;
    allocate(size);
}

template<typename T>
MyVector<T>::MyVector(const MyVector::Vector &vector)
{
    allocate(vector.sz);
    sz = vector.sz;
    std::copy_n(vector.cbegin(), sz, begin());
}

template<typename T>
MyVector<T>::MyVector(size_t size, const T *arr)
{
    if (!arr)
    {
        time_t currTime = std::time(nullptr);
        throw NullPtrException(__FILE__, typeid(*this).name(), __LINE__,
                               ctime(&currTime));
    }

    allocate(size);
    sz = size;
    std::copy_n(arr, sz, begin());
}

template<typename T>
MyVector<T> &MyVector<T>::operator=(const MyVector::Vector &vector)
{
    allocate(vector.sz);
    sz = vector.sz;
    std::copy_n(vector.cbegin(), sz, begin());

    return *this;
}

template<typename T>
MyVector<T> &MyVector<T>::operator=(MyVector::Vector &&vector) noexcept
{
    allocate(vector.s);
    sz = vector.sz;
    std::copy_n(vector.cbegin(), sz, begin());

    return *this;
}

template<typename T>
typename MyVector<T>::Vector& MyVector<T>::operator=(
        std::initializer_list<T> initializerList)
{
    if (initializerList.size() != size())
        allocate(initializerList.size());

    std::copy(initializerList.begin(), initializerList.end(), begin());
}

template<typename T>
MyVector<T>::MyVector(std::initializer_list<T> initializerList)
{
    sz = initializerList.size();
    allocate(sz);
    std::copy(initializerList.begin(), initializerList.end(), begin());
}

template<typename T>
template<typename InputIt>
MyVector<T>::MyVector(InputIt first, InputIt last)
{
    sz = std::distance(first, last);
    allocate(sz);
    std::copy(first, last, begin());
}

template<typename T>
bool MyVector<T>::isEmpty() const
{
    return sz == 0;
}

template<typename T>
void MyVector<T>::clear()
{
    data.reset();
    sz = 0;
}

template<typename T>
void MyVector<T>::allocate(size_t size)
{
    try
    {
        data = std::shared_ptr<T[]>(new T[size]());
    }
    catch (std::bad_alloc &)
    {
        time_t currTime = std::time(nullptr);
        throw BadAllocation(__FILE__, typeid(*this).name(), __LINE__,
                               ctime(&currTime));
    }
}

template<typename T>
typename MyVector<T>::Iter MyVector<T>::begin()
{
    return Iterator<T>(*this);
}

template<typename T>
typename MyVector<T>::Iter MyVector<T>::end()
{
    return Iterator<T>(*this, sz);
}

template<typename T>
typename MyVector<T>::CIter MyVector<T>::begin() const
{
    return cbegin();
}

template<typename T>
typename MyVector<T>::CIter MyVector<T>::end() const
{
    return cend();
}

template<typename T>
size_t MyVector<T>::size() const
{
    return sz;
}

template<typename T>
T &MyVector<T>::operator[](size_t index)
{
    if (index >= sz)
    {
        time_t currTime = std::time(nullptr);
        throw IndexOutOfRange(__FILE__, typeid(*this).name(), __LINE__,
                               ctime(&currTime));
    }

    return *Iterator<T>(*this, index);
}

template<typename T>
const T &MyVector<T>::operator[](size_t index) const
{
    if (index >= sz)
    {
        time_t currTime = std::time(nullptr);
        throw IndexOutOfRange(__FILE__, typeid(*this).name(), __LINE__,
                              ctime(&currTime));
    }

    return *ConstIterator<T>(*this, index);
}

template<typename T>
typename MyVector<T>::CIter MyVector<T>::cbegin() const
{
    return CIter(*this);
}

template<typename T>
typename MyVector<T>::CIter MyVector<T>::cend() const
{
    return CIter(*this, sz);
}

template<typename T>
bool MyVector<T>::operator==(const MyVector::Vector &vec) const
{
    if (this == &vec)
        return true;

    if (sz != vec.sz)
        return false;

    bool equal = true;

    for (CIter a = cbegin(), b = vec.cbegin(); a != cend() && equal;
            ++a, ++b)
        if (*a != *b)
            equal = false;

    return equal;
}

template<typename T>
bool MyVector<T>::equals(const MyVector::Vector &vec) const
{
    return *this == vec;
}

template<typename T>
bool MyVector<T>::nequals(const MyVector::Vector &vec) const
{
    return !equals(vec);
}

template<typename T>
bool MyVector<T>::operator!=(const MyVector::Vector &vec) const
{
    return !(*this == vec);
}

template<typename T>
typename MyVector<T>::pointer MyVector<T>::getData() const
{
    return data;
}

template<typename T>
typename MyVector<T>::Vector MyVector<T>::operator-() const
{
    MyVector<T> newVector(sz);
    Iter iter = newVector.begin();

    for (const auto &element: *this)
        *(iter++) = -element;

    return newVector;
}

template<typename T>
void MyVector<T>::changeSign()
{
    for (auto &element: *this)
        element = -element;
}

template<typename T>
typename MyVector<T>::Vector MyVector<T>::neg() const
{
    return -(*this);
}

template<typename T>
template<typename OtherVector>
decltype(auto) MyVector<T>::operator+(
        const MyVector<OtherVector> &vec) const
{
    MyVector<decltype(this->at(0) + vec.at(0))> newVector(*this);
    newVector += vec;

    return newVector;
}

template<typename T>
template<typename OtherVector>
typename MyVector<T>::Vector &MyVector<T>::operator+=(
        const MyVector<OtherVector> &other)
{
    if (sz != other.sz)
    {
        time_t currTime = std::time(nullptr);
        throw InappropriateDimensions(__FILE__, typeid(*this).name(), __LINE__,
                                      ctime(&currTime));
    }

    CIter b = other.cbegin();

    for (Iter a = begin(); a != end() && b != other.cend(); a++, b++)
        *a += *b;

    return *this;
}

template<typename T>
template<typename OtherVector>
typename MyVector<T>::Vector& MyVector<T>::operator-=(
        const MyVector<OtherVector> &other)
{
    *this += -other;

    return *this;
}

template<typename T>
template<typename NumType>
decltype(auto) MyVector<T>::operator+(const NumType& number) const
{
    MyVector<decltype(this->at(0) + number)> newVector(*this);

    for (auto &element: newVector)
        element += number;

    return newVector;
}

template<typename T>
template<typename NumType>
typename MyVector<T>::Vector &MyVector<T>::operator+=(const NumType& number)
{
    for (auto &element: *this)
        element += number;

    return *this;
}

template<typename T>
template<typename NumType>
decltype(auto) MyVector<T>::operator-(const NumType& number) const
{
    return *this + (-number);
}

template<typename T>
template<typename NumType>
typename MyVector<T>::Vector &MyVector<T>::operator-=(const NumType& number)
{
    *this += -number;

    return *this;
}

template<typename T>
typename MyVector<T>::Vector MyVector<T>::operator*(
        const MyVector::Vector &other) const
{
    if (sz != 3 || other.sz != 3)
    {
        time_t currTime = std::time(nullptr);
        throw InappropriateDimensions(__FILE__, typeid(*this).name(), __LINE__,
                                      ctime(&currTime));
    }

    MyVector<T> vector = {at(1) * other.at(2) - at(2) * other.at(1),
                          at(2) * other.at(0) - at(0) * other.at(2),
                          at(0) * other.at(1) - at(1) * other.at(0)};

    return vector;
}

template<typename T>
typename MyVector<T>::Vector &MyVector<T>::operator*=(
        const MyVector::Vector &other)
{
    if (sz != 3 || other.sz != 3)
    {
        time_t currTime = std::time(nullptr);
        throw InappropriateDimensions(__FILE__, typeid(*this).name(), __LINE__,
                                      ctime(&currTime));
    }

    MyVector<T> result = *this * other;
    *this = result;
}

template<typename T>
template<typename NumType>
decltype(auto) MyVector<T>::operator*(const NumType& number) const
{
    MyVector<decltype(this->at(0) + number)> newVector(*this);

    for (auto &element: newVector)
        element *= number;

    return newVector;
}

template<typename T>
template<typename NumType>
typename MyVector<T>::Vector &MyVector<T>::operator*=(const NumType& number)
{
    for (auto &element: *this)
        element *= number;

    return *this;
}

template<typename T>
decltype(auto) MyVector<T>::scalarProduct(const MyVector::Vector &other) const
{
    if (sz != other.sz)
    {
        time_t currTime = std::time(nullptr);
        throw InappropriateDimensions(__FILE__, typeid(*this).name(), __LINE__,
                                      ctime(&currTime));
    }

    auto sum = 0;

    for (CIter a = cbegin(), b = other.cbegin(); a != cend() && b != cend();
            ++a, ++b)
        sum += *a * *b;

    return sum;
}

template<typename T>
double MyVector<T>::angle(const MyVector::Vector &other) const
{
    if (size() != other.size())
    {
        time_t currTime = std::time(nullptr);
        throw InappropriateDimensions(__FILE__, typeid(*this).name(), __LINE__,
                                      ctime(&currTime));
    }

    double angleCos = scalarProduct(other) /
            length() * other.length();

    return std::acos(angleCos);
}

template<typename T>
decltype(auto) MyVector<T>::length() const
{
    auto squaresSum = 0;

    for (const auto &element: *this)
        squaresSum += element * element;

    return std::sqrt(squaresSum);
}

template<typename T>
T& MyVector<T>::at(size_t index)
{
    return (*this)[index];
}

template<typename T>
const T& MyVector<T>::at(size_t index) const
{
    return (*this)[index];
}

template<typename T>
template<typename OtherVector>
decltype(auto) MyVector<T>::add(const MyVector<OtherVector> &vec) const
{
    return *this + vec;
}

template<typename T>
template<typename OtherVector>
typename MyVector<T>::Vector& MyVector<T>::plus(const MyVector<OtherVector> &vec)
{
    *this += vec;

    return *this;
}

template<typename T>
template<typename OtherVector>
decltype(auto) MyVector<T>::subtract(
        const MyVector<OtherVector> &other) const
{
    return *this - other;
}

template<typename T>
template<typename NumType>
decltype(auto) MyVector<T>::add(const NumType& number) const
{
    return *this + number;
}

template<typename T>
template<typename NumType>
typename MyVector<T>::Vector& MyVector<T>::plus(const NumType& number)
{
    *this += number;

    return *this;
}

template<typename T>
template<typename NumType>
decltype(auto) MyVector<T>::subtract(const NumType& number) const
{
    return *this - number;
}

template<typename T>
template<typename NumType>
typename MyVector<T>::Vector& MyVector<T>::minus(const NumType& number)
{
    *this -= number;

    return *this;
}

template<typename T>
typename MyVector<T>::Vector& MyVector<T>::minus(const MyVector::Vector &other)
{
    *this -= other;

    return *this;
}

template<typename T>
typename MyVector<T>::Vector MyVector<T>::dotProduct(
        const MyVector::Vector &other) const
{
    return *this * other;
}

template<typename T>
template<typename NumType>
typename MyVector<T>::Vector MyVector<T>::multiply(const NumType &number) const
{
    return *this *number;
}

template<typename T>
template<typename NumType>
typename MyVector<T>::Vector& MyVector<T>::multiplyByNumber(
        const NumType& number)
{
    *this += number;

    return *this;
}

template<typename T>
typename MyVector<T>::Vector MyVector<T>::elementMultiply(
        const MyVector::Vector &other) const
{
    if (sz != other.sz)
    {
        time_t currTime = std::time(nullptr);
        throw WrongDimensions(__FILE__, typeid(*this).name(), __LINE__,
                               ctime(&currTime));
    }

    MyVector<T> result(sz);
    Iter resIter = result.begin();
    CIter first = cbegin();
    CIter second = other.cbegin();

    for ( ; resIter != result.end(); ++resIter, ++first, ++second)
        *resIter = *first * *second;

    return result;
}

template<typename T>
typename MyVector<T>::Vector& MyVector<T>::multiplyByElement(const MyVector<T>::Vector &other)
{
    if (sz != other.sz)
    {
        time_t currTime = std::time(nullptr);
        throw WrongDimensions(__FILE__, typeid(*this).name(), __LINE__,
                              ctime(&currTime));
    }

    Iter first = begin();
    CIter second = other.cbegin();

    for ( ; first != end(); ++first, ++second)
        *first = *first * *second;

    return *this;
}

template<typename T>
bool MyVector<T>::collinear(const MyVector::Vector &other) const
{
    double ang = angle(other);

    return std::abs(ang) < eps ||
           std::abs(ang - M_PI) < eps;
}

template<typename T>
bool MyVector<T>::orthogonal(const MyVector::Vector &other) const
{
    return std::abs(angle(other) - M_PI_2) < eps;
}

template<typename T>
void MyVector<T>::setEps(double value)
{
    if (value <= 0)
    {
        time_t currTime = std::time(nullptr);
        throw BadEpsValue(__FILE__, typeid(*this).name(), __LINE__,
                              ctime(&currTime));
    }

    eps = value;
}

template<typename T>
double MyVector<T>::getEps() const noexcept
{
    return eps;
}

template<typename T>
typename MyVector<T>::Vector& MyVector<T>::multiplyByVector(
        const MyVector::Vector &other) const
{
    *this *= other;

    return *this;
}

template<typename T>
decltype(auto) MyVector<T>::operator&(const MyVector::Vector &other) const
{
    return scalarProduct(other);
}

template<typename T>
typename MyVector<T>::Vector MyVector<T>::operator%(
        const MyVector::Vector &other) const
{
    return elementMultiply(other);
}

template<typename T>
typename MyVector<T>::Vector &MyVector<T>::operator%=(
        const MyVector::Vector &other)
{
    return multiplyByElement(other);
}

template<typename T>
template<typename OtherVector>
decltype(auto) MyVector<T>::operator-(const MyVector<OtherVector> &other) const
{
    return *this + (-other);
}

template<typename T>
double scalarProduct(const MyVector<T> &first, const MyVector<T> &second)
{
    return first.scalarProduct(second);
}


template<typename T>
double angle(const MyVector<T> &first, const MyVector<T> &second)
{
    return first.angle(second);
}

template<typename T, typename NumType>
MyVector<T> operator+(const NumType &number, const MyVector<T> &myVector)
{
    return myVector + number;
}


template<typename T, typename NumType>
MyVector<T> operator-(const NumType& number, const MyVector<T> &myVector)
{
    return myVector - number;
}


template<typename T, typename NumType>
MyVector<T> operator*(const NumType& number, const MyVector<T> &myVector)
{
    return myVector * number;
}

template<typename T>
MyVector<T> elementMultiply(const MyVector<T> &first,
                            const MyVector<T> &second)
{
    return first.elementMultiply(second);
}

template<typename T>
double collinear(const MyVector<T> &first, const MyVector<T> &second)
{
    return first.collinear(second);
}

template<typename T>
bool orthogonal(const MyVector<T> &first, const MyVector<T> &second)
{
    return first.orthogonal(second);
}

template<typename T>
MyVector<T> add(const MyVector<T> &first, const MyVector<T> &second)
{
    return first + second;
}

template<typename T>
MyVector<T> subtract(const MyVector<T> &first, const MyVector<T> &second)
{
    return first - second;
}

#endif // _MY_VECTOR_HPP_

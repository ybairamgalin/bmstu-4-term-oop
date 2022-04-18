#include "myvector.hpp"

template<typename T>
MyVector<T>::MyVector() : capacity(0) { }

template<typename T>
MyVector<T>::MyVector(const int sz) : capacity(sz)
{
    allocate(sz);
}

template<typename T>
MyVector<T>::MyVector(const MyVector<T> &other)
{
    capacity = other.capacity;

}

template<typename T>
MyVector<T>::MyVector(MyVector<T> &&vector) noexcept
{

}

template<typename T>
MyVector<T> &MyVector<T>::operator=(const MyVector<T> &)
{
    return *this;
}

template<typename T>
MyVector<T> &MyVector<T>::operator=(MyVector<T> &&other) noexcept {
    return *this;
}

template<typename T>
void MyVector<T>::allocate(size_t sz)
{
    data = std::make_shared<T>(sizeof(T) * capacity);
}

template<typename T>
size_t MyVector<T>::size() const noexcept
{
    return sz;
}

template<typename T>
MyIterator<T> MyVector<T>::begin()
{
    return MyIterator<T>(*this);
}

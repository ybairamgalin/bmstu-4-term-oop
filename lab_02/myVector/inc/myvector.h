#ifndef __MY_VECTOR_H__
#define __MY_VECTOR_H__

#include <memory>
#include "basecontainer.h"
#include "iterator.h"

template <typename T>
class MyVector : public BaseContainer
{
    typedef std::shared_ptr<T> pointer;
    typedef MyVector<T> Vector;
    typedef Iterator<T> Iter;
    using BaseContainer::size;

    friend Iterator<T>;
public:
    MyVector() = default;
    explicit MyVector(size_t sz);
    explicit MyVector(size_t sz, const T* arr);

    virtual bool isEmpty() const override;
    virtual void clear() override;
    ~MyVector() override = default;

    Iter begin();
    Iter end();

    void pushBack(const T &);
private:
    pointer data = nullptr;
    size_t capacity = 0;

    void allocate(size_t sz);
};

#include "myvector.hpp"

#endif // __MY_VECTOR_H__

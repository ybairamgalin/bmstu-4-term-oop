#ifndef _BASE_ITERATOR_H_
#define _BASE_ITERATOR_H_

#include <memory>

template <typename T>
class BaseIterator
{
public:
    BaseIterator(size_t index, size_t maxIndex);
    virtual ~BaseIterator() = default;

    virtual explicit operator bool() const noexcept = 0;
    virtual const T* operator->() const = 0;
    virtual const T& operator*() const = 0;
protected:
    size_t index;
    size_t maxIndex;
};

#include "baseiterator.hpp"

#endif

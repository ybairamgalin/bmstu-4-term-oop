#ifndef _BASE_ITERATOR_HPP_
#define _BASE_ITERATOR_HPP_

#include "baseiterator.h"

template<typename T>
BaseIterator<T>::BaseIterator(size_t index, size_t maxIndex) :
        index(index), maxIndex(maxIndex) { }

#endif

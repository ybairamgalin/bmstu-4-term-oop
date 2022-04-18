#include "myiterator.hpp"}

template<typename T>
MyIterator<T>::MyIterator(const MyVector<T> &vector) noexcept
{
    dataPtr = std::weak_ptr<T[]>(vector.data); // TODO REMOVE PRIVATE DATA ACCESS
    currentIndex = 0;
    containerSize = vector.size();
}

template<typename T>
MyIterator<T> MyIterator<T>::operator++() {
    if (currentIndex + 1 >= containerSize)
        throw; // TODO ADD EXCEPTION DEFINITION

    currentIndex++;

    return *this;
}

template<typename T>
MyIterator<T> MyIterator<T>::operator++(int) {
    if (currentIndex + 1 >= containerSize)
        throw;

    MyIterator<T> tmp(*this);
    currentIndex++;

    return tmp;
}

template<typename T>
MyIterator<T> &MyIterator<T>::operator=(const MyIterator<T> &other)
{
    dataPtr = other.dataPtr;
    currentIndex = other.currentIndex;
    containerSize = other.containerSize;

    return *this;
}

template<typename T>
T &MyIterator<T>::operator*()
{

    return <#initializer#>;
}

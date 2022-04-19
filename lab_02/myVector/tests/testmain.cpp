#include <iostream>
#include <vector>
#include "myvector.h"
#include "iterator.h"

int main()
{
    MyVector<int> vector(10);
    vector.pushBack(1);
    vector.pushBack(2);
    vector.pushBack(3);

    Iterator<int> iterBegin = vector.begin();
    Iterator<int> iterEnd = vector.end();


    return EXIT_SUCCESS;
}

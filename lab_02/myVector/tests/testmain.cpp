#include <gtest/gtest.h>


#include "myvector.h"
#include "iterator.h"
#include "myvectorexceptions.h"

class MyVectorTestNegative : public ::testing::Test { };
class MyVectorTestPositive : public ::testing::Test { };

TEST_F(MyVectorTestNegative, constructorFromArray)
{
    EXPECT_THROW(MyVector<int> vector(3, nullptr), NullPtrException);
}

TEST_F(MyVectorTestNegative, worngVectorDims)
{
    int arr[5] = { 10, 11, 12, 13, 14 };

    MyVector<int> first(5, arr);
    MyVector<int> second(4, arr);

    EXPECT_THROW(first += second, InappropriateDimensions);
}

TEST_F(MyVectorTestPositive, constructorFromArray)
{
    int arr[5] = { 10, 11, 12, 13, 14 };

    MyVector<int> vector(5, arr);

    EXPECT_EQ(5, vector.size());

    EXPECT_EQ(10, vector[0]);
    EXPECT_EQ(11, vector[1]);
    EXPECT_EQ(12, vector[2]);
    EXPECT_EQ(13, vector[3]);
    EXPECT_EQ(14, vector[4]);
}

TEST_F(MyVectorTestPositive, copyConstructor)
{
    MyVector<int> vector(10); // TODO INIT LIST
    vector.pushBack(5);
    vector.pushBack(4);
    vector.pushBack(3);
    vector.pushBack(2);
    vector.pushBack(1);

    MyVector<int> newVector(vector);

    EXPECT_EQ(vector.size(), newVector.size());

    EXPECT_EQ(vector[0], newVector[0]);
    EXPECT_EQ(vector[1], newVector[1]);
    EXPECT_EQ(vector[2], newVector[2]);
    EXPECT_EQ(vector[3], newVector[3]);
    EXPECT_EQ(vector[4], newVector[4]);
}

TEST_F(MyVectorTestPositive, subscription)
{
    MyVector<int> vector(10);
    vector[0] = 0;
    vector[1] = 1;
    vector[2] = 2;

    EXPECT_EQ(vector[0], 0);
    EXPECT_EQ(vector[1], 1);
    EXPECT_EQ(vector[2], 2);
}

TEST_F(MyVectorTestPositive, stdCopy)
{
    MyVector<int> source(7);
    source[0] = 9;
    source[1] = 90;
    source[2] = 900;
    source[3] = 9000;

    MyVector<int> dest(6);

    std::copy(source.cbegin(), source.cend(), dest.begin());

    EXPECT_EQ(source[0], dest[0]);
    EXPECT_EQ(source[1], dest[1]);
    EXPECT_EQ(source[2], dest[2]);
    EXPECT_EQ(source[3], dest[3]);
}

TEST_F(MyVectorTestPositive, equalSimple)
{
    MyVector<int> first(4);

    first[0] = 1;
    first[1] = 10;
    first[2] = 100;
    first[3] = 1000;

    MyVector<int> second(4);

    second[0] = 1;
    second[1] = 10;
    second[2] = 100;
    second[3] = 1000;

    EXPECT_TRUE(first == second);
}

TEST_F(MyVectorTestPositive, nequalSimple)
{
    MyVector<int> first(4);

    first[0] = 1;
    first[1] = 10;
    first[2] = 100;
    first[3] = 1000;

    MyVector<int> second(4);

    second[0] = 1;
    second[1] = 10;
    second[2] = 100;
    second[3] = 10000;

    EXPECT_TRUE(first != second);
}

TEST_F(MyVectorTestPositive, nequalSize)
{
    MyVector<int> first(4);

    first[0] = 1;
    first[1] = 10;
    first[2] = 100;
    first[3] = 1000;

    MyVector<int> second(5);

    second[0] = 1;
    second[1] = 10;
    second[2] = 100;
    second[3] = 1000;
    second[3] = 0;

    EXPECT_TRUE(first != second);
}

TEST_F(MyVectorTestPositive, isEmptyNormal)
{
    MyVector<int> emp;

    EXPECT_EQ(true, emp.isEmpty());

    MyVector<int> notEmpty(2);
    notEmpty[0] = 10;
    notEmpty[1] = 20;

    EXPECT_FALSE(notEmpty.isEmpty());
}

TEST_F(MyVectorTestPositive, pushBackEmpty)
{
    MyVector<int> vector;

    vector.pushBack(123);

    EXPECT_EQ(1, vector.size());
    EXPECT_EQ(123, vector[0]);
}

TEST_F(MyVectorTestPositive, pushBackFull)
{
    MyVector<int> vector(3);

    EXPECT_EQ(3, vector.size());

    vector[0] = 2;
    vector[1] = 4;
    vector[2] = 8;

    EXPECT_EQ(3, vector.size());

    vector.pushBack(16);

    EXPECT_EQ(4, vector.size());
    EXPECT_EQ(16, vector[3]);

}

TEST_F(MyVectorTestPositive, unaryMinus)
{
    MyVector<int> vector(3);

    EXPECT_EQ(3, vector.size());

    vector[0] = 2;
    vector[1] = 4;
    vector[2] = 8;

     MyVector<int> newVector(-vector);

    EXPECT_EQ(-2, newVector[0]);
    EXPECT_EQ(-4, newVector[1]);
    EXPECT_EQ(-8, newVector[2]);

    EXPECT_EQ(3, newVector.size());
}

TEST_F(MyVectorTestPositive, addition)
{
    MyVector<int> first(3);

    first[0] = 2;
    first[1] = 4;
    first[2] = 8;

    MyVector<int> second(3);

    second[0] = 10;
    second[1] = 10;
    second[2] = 10;

    MyVector<int> result = first + second;

    EXPECT_EQ(3, result.size());

    EXPECT_EQ(result[0], 12);
    EXPECT_EQ(result[1], 14);
    EXPECT_EQ(result[2], 18);
}

TEST_F(MyVectorTestPositive, additionEq)
{
    MyVector<int> first(3);

    first[0] = 2;
    first[1] = 4;
    first[2] = 8;

    MyVector<int> second(3);

    second[0] = 10;
    second[1] = 10;
    second[2] = 10;

    first += second;

    EXPECT_EQ(3, first.size());

    EXPECT_EQ(first[0], 12);
    EXPECT_EQ(first[1], 14);
    EXPECT_EQ(first[2], 18);
}

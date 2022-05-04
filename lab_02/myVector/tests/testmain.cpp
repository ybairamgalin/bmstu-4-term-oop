#include <gtest/gtest.h>
#include <vector>

#include "myvector.h"
#include "iterator.h"
#include "myvectorexceptions.h"

class MyVectorTestNegative : public ::testing::Test { };
class MyVectorTestPositive : public ::testing::Test { };

TEST_F(MyVectorTestNegative, constructorFromArray)
{
    EXPECT_THROW(MyVector<int> vector(3, nullptr), NullPtrException);
}

TEST_F(MyVectorTestNegative, wrongDimsAddition)
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
    vector[0] = 5;
    vector[1] = 4;
    vector[2] = 3;
    vector[3] = 2;
    vector[4] = 1;

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

    MyVector<int> dest(7);

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

TEST_F(MyVectorTestPositive, addNumber)
{
    MyVector<int> first(3);

    first[0] = 2;
    first[1] = 4;
    first[2] = 8;

    MyVector<int> result = first + 10;

    EXPECT_EQ(3, first.size());

    EXPECT_EQ(result[0], 12);
    EXPECT_EQ(result[1], 14);
    EXPECT_EQ(result[2], 18);
}

TEST_F(MyVectorTestPositive, subtractNumber)
{
    MyVector<int> first(3);

    first[0] = 2;
    first[1] = 4;
    first[2] = 8;

    MyVector<int> result = first - 10;

    EXPECT_EQ(3, first.size());

    EXPECT_EQ(result[0], -8);
    EXPECT_EQ(result[1], -6);
    EXPECT_EQ(result[2], -2);
}

TEST_F(MyVectorTestPositive, scalarProduct)
{
    MyVector<double> first(3);
    first[0] = 2.0;
    first[1] = 4.0;
    first[2] = 8.0;

    MyVector<double> second(3);
    second[0] = -2.0;
    second[1] = -3.0;
    second[2] = -4.0;

    double result = first.scalarProduct(second);

    EXPECT_DOUBLE_EQ(result, -48.0);
}

TEST_F(MyVectorTestPositive, angle)
{
    MyVector<double> first(2);
    first[0] = 2.0;
    first[1] = 1.0;

    MyVector<double> second(2);
    second[0] = -1.0;
    second[1] = 2.0;

    double result = first.angle(second);

    EXPECT_DOUBLE_EQ(result, M_PI / 2);
}

TEST_F(MyVectorTestPositive, at)
{
    MyVector<double> first(2);
    first[0] = 2.0;
    first[1] = 1.0;

    EXPECT_DOUBLE_EQ(first.at(0), 2.0);
    EXPECT_DOUBLE_EQ(first.at(1), 1.0);

    MyVector<int> tmp(2);
    tmp[0] = 5;
    tmp[1] = 10;

    const MyVector<int> second(tmp);

    EXPECT_EQ(second.at(0), 5);
    EXPECT_EQ(second.at(1), 10);
}

TEST_F(MyVectorTestPositive, initListConstructor)
{
    MyVector<int> vector = { 1, 2, 3, 4, 5 };

    EXPECT_EQ(5, vector.size());

    EXPECT_EQ(1, vector[0]);
    EXPECT_EQ(2, vector[1]);
    EXPECT_EQ(3, vector[2]);
    EXPECT_EQ(4, vector[3]);
    EXPECT_EQ(5, vector[4]);
}

TEST_F(MyVectorTestPositive, stdVectorCopy)
{
    std::vector<int> vector = { 10, 11, 12, 13};

    MyVector<int> myVector(vector.begin(), vector.end());

    EXPECT_EQ(4, myVector.size());

    EXPECT_EQ(10, myVector[0]);
    EXPECT_EQ(11, myVector[1]);
    EXPECT_EQ(12, myVector[2]);
    EXPECT_EQ(13, myVector[3]);
}

TEST_F(MyVectorTestPositive, boolIter)
{
    MyVector<int> vec(5);
    Iterator<int> iter(vec, 2);

    {
        MyVector<int> myVector = { 10, 11, 12, 13 };
        iter = myVector.begin();

        EXPECT_TRUE(bool(iter));
    }

    EXPECT_FALSE(bool(iter));
}

TEST_F(MyVectorTestPositive, elementMultiply)
{
    MyVector<int> first = { 0, 2, 4 };
    MyVector<int> second = { 2, 4, 8 };

    auto result = first.elementMultiply(second);

    EXPECT_EQ(0, result[0]);
    EXPECT_EQ(8, result[1]);
    EXPECT_EQ(32, result[2]);
}

//TEST_F(MyVectorTestPositive, collinear)
//{
//    MyVector<int> first = { 0, 3 };
//    MyVector<int> second = { 0, 15 };
//
//    EXPECT_TRUE(first.collinear(second));
//}
//
//TEST_F(MyVectorTestPositive, collinearReverse)
//{
//    MyVector<int> first = { 1, 3 };
//    MyVector<int> second = { -2, -6 };
//
//    EXPECT_TRUE(first.collinear(second));
//}

TEST_F(MyVectorTestPositive, othogonal)
{
    MyVector<int> first = { 1, 1 };
    MyVector<int> second = { -1, 1 };

    EXPECT_TRUE(first.orthogonal(second));
}

TEST_F(MyVectorTestPositive, notOthogonal)
{
    MyVector<int> first = { 2, 1 };
    MyVector<int> second = { 1, 0 };

    EXPECT_FALSE(orthogonal(first, second));
}

TEST_F(MyVectorTestPositive, othogonalReverse)
{
    MyVector<int> first = { 1, 1 };
    MyVector<int> second = { 1, -1 };

    EXPECT_TRUE(orthogonal(first, second));
}

//TEST_F(MyVectorTestPositive, stdSort)
//{
//    MyVector<int> vector = { 10, 5, 8, 1, 3, 2, 9, 4, 6, 7, 8 };
//
//    std::sort(vector.begin(), vector.end());
//
//    EXPECT_TRUE(std::is_sorted(vector.cbegin(), vector.cend()));
//
//    EXPECT_EQ(vector[0], 1);
//    EXPECT_EQ(vector[1], 2);
//    EXPECT_EQ(vector[2], 3);
//    EXPECT_EQ(vector[3], 4);
//    EXPECT_EQ(vector[4], 5);
//    EXPECT_EQ(vector[5], 6);
//    EXPECT_EQ(vector[6], 7);
//    EXPECT_EQ(vector[7], 8);
//    EXPECT_EQ(vector[8], 9);
//    EXPECT_EQ(vector[9], 10);
//}

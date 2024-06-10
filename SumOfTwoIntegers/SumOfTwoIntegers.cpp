// SumOfTwoIntegers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Solution
{
public:
    int getSum(int a, int b)
    {
        while (b != 0)
        {
            int temp = (a & b) << 1;
            a = a ^ b;
            b = temp;
        }
        return a;
    }
};

int main()
{
}
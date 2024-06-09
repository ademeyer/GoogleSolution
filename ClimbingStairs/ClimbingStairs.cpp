// ClimbingStairs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        int first = 1;
        int second = 1;

        for (int i = 0; i < (n - 1); ++i)
        {
            int temp = first;
            first += second;
            second = temp;
        }

        return first;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
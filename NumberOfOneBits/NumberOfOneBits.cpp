// NumberOfOneBits.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Solution
{
public:
    int hammingWeight(int n)
    {
        int count = 0;
        while (n)
        {
            if (n & 0x01)
                ++count;
            n >>= 1;
        }
        return count;
    }
};
int main()
{
}

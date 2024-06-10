// ReverseBits.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t res = 0;
        for (int i = 0; i < 32; ++i)
        {
            int bit = (n >> i) & 0x01;
            res |= (bit << (31 - i));
        }
        return res;
    }
};

int main()
{

}

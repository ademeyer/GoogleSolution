// HouseRobber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int rob(vector<int>& nums)
    {
        int rob1 = 0;
        int rob2 = 0;
        // [rob1, rob2, n, n+1, ...] 
        for (auto n : nums)
        {
            int temp = max((n + rob1), rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;
    }
};


int main()
{
}

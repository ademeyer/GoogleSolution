// MaximumSubarray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        int maxSub = nums[0];
        int curSub = 0;

        for (auto n : nums)
        {
            if (curSub < 0)
            {
                curSub = 0;
            }
            curSub += n;
            maxSub = max(maxSub, curSub);
        }
        return maxSub;
    }
};

int main()
{
}
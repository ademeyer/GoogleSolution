// MinimumSizeSubarraySum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;


class Solution
{
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        // boundary condition
        if (accumulate(nums.begin(), nums.end(), 0) < target) return 0;

        int l = 0, total = 0;
        int res = INT_MAX;
        for (int r = 0; r < nums.size(); r++)
        {
            total += nums[r];
            while (total >= target)
            {
                res = min(r - l + 1, res);
                total -= nums[l];
                l++;
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};

int main()
{

}

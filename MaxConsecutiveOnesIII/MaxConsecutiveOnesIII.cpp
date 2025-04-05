// MaxConsecutiveOnesIII.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int l = 0, max_ones = 0, zero_cnt = 0;

        for (int r = 0; r < nums.size(); ++r)
        {
            zero_cnt += nums[r] == 0 ? 1 : 0;
            // maintain valid window size
            while (zero_cnt > k)
            {
                zero_cnt -= nums[l] == 0 ? 1 : 0;
                ++l;
            }
            max_ones = max(max_ones, r - l + 1);
        }
        return max_ones;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1,1,1,0,0,0,1,1,1,1,0 };
    int k = 2;
    cout << "max number of ones: " << s.longestOnes(nums, k) << endl;

    nums = { 0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1 };
    k = 3;
    cout << "max number of ones: " << s.longestOnes(nums, k) << endl;

    return 0;
}

// LongestSubarrayOf1'sAfterDeletingOneElement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    int longestSubarray(vector<int>& nums) 
    {
        int l = 0, max_len = 0, zero_cnt = 0;
        
        for (int r = 0; r < nums.size(); ++r)
        {
            zero_cnt += nums[r] == 0 ? 1 : 0;

            while (zero_cnt > 1)
            {
                zero_cnt -= nums[l] == 0 ? 1 : 0;
                ++l;
            }
            max_len = max(max_len, r - l);
        }
        return max_len == nums.size() ? max_len - 1 : max_len;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1,1,0,1 };
    cout << "longest subarray of 1's: " << s.longestSubarray(nums) << endl;

    nums = { 0,1,1,1,0,1,1,0,1 };
    cout << "longest subarray of 1's: " << s.longestSubarray(nums) << endl;

    nums = { 1,1,1 };
    cout << "longest subarray of 1's: " << s.longestSubarray(nums) << endl;

    return 0;
}

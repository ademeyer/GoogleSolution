// LongestIncreasingSubsequence.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int longestIncreasingSubsequence(vector<int>& nums)
    {
        vector<int> LIS(nums.size(), 1);
        int result = 1;
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            for (int j = (i + 1); j < nums.size(); j++)
            {
                if (nums[i] < nums[j])
                {
                    LIS[i] = max(LIS[i], (1 + LIS[j]));
                    
                }
                result = max(LIS[i], result);
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 10,9,2,5,3,7,101,18 };
    cout << s.longestIncreasingSubsequence(nums) << endl;

    nums = { 0,1,0,3,2,3 };
    cout << s.longestIncreasingSubsequence(nums) << endl;

    nums = { 7,7,7,7,7,7,7 };
    cout << s.longestIncreasingSubsequence(nums) << endl;
}

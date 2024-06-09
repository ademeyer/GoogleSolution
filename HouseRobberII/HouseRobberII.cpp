// HouseRobberII.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    int helper(vector<int> nums)
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
public:
    int rob(vector<int>& nums)
    {
        return max(nums[0], 
            max(helper(vector<int>(nums.begin() + 1, nums.end())), 
                helper(vector<int>(nums.begin(), nums.end() - 1))));
    }
}; 

int main()
{
    Solution s;
    vector<int> nums = { 2,3,2 };
    cout << s.rob(nums) << endl;

    nums = { 1,2,3,1 };
    cout << s.rob(nums) << endl;

    nums = { 1,2,3 };
    cout << s.rob(nums) << endl;
}

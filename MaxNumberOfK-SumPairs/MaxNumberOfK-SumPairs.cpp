// MaxNumberOfK-SumPairs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    int maxOperations(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        int op = 0;

        while (l < r)
        {
            int sum = nums[l] + nums[r];
            if (sum == k)
            {
                ++op;
                ++l;
                --r;
            }
            else if (sum < k)
                ++l;
            else
                --r;
        }
        return op;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1, 2, 3, 4 }; int k = 5;
    cout << "ops: " << s.maxOperations(nums, k) << endl;

    nums = { 3,1,3,4,3 }; k = 6;
    cout << "ops: " << s.maxOperations(nums, k) << endl;

    return 0;
}
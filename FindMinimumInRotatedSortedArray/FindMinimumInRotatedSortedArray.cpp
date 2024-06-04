// FindMinimumInRotatedSortedArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findMin(vector<int>& nums)
    {
        int l = 0, r = nums.size() - 1;
        
        int result = nums[0];
        while (l <= r)
        {
            if (nums[l] < nums[r])
            {
                result = min(result, nums[l]);
                break;
            }
            int mid = (l + r) / 2;
            result = min(result, nums[mid]);
            if (nums[mid] >= nums[l])
                l++; // search to the right
            else
                --r; // search to the left
        }
        return result;
    }
};

int main()
{
    Solution s;

    vector<int> nums = { 3,4,5,1,2 };
    cout << s.findMin(nums) << endl;

    nums = { 4,5,6,7,0,1,2 };
    cout << s.findMin(nums) << endl;

    nums = { 11,13,15,17 };
    cout << s.findMin(nums) << endl;
}


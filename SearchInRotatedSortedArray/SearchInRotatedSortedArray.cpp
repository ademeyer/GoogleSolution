// SearchInRotatedSortedArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        int l = 0, r = nums.size() - 1;

        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (target == nums[mid])
                return mid;

            // Check which portion of the array we are in
            if (nums[l] <= nums[mid]) // if we are in left sorted portion
            {
                if (target > nums[mid] || target < nums[l])
                    l = mid + 1;
                else
                    r = mid - 1;

            }
            else // if we are in the right sorted array
            {
                if (target < nums[mid] || target > nums[r])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;

    vector<int> nums = { 4,5,6,7,0,1,2 };
    cout << s.search(nums, 0) << endl;

    nums = { 4,5,6,7,0,1,2 };
    cout << s.search(nums, 3) << endl;

    nums = { 1 };
    cout << s.search(nums, 0) << endl;
}


// FindFirstAndLastPositionOfElementInSortedArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        if (nums.empty()) return { -1, -1 };

        function<int()> findFirst = [&]() -> int 
        {
            int l = 0;
            int r = nums.size() - 1;
            int first = -1;

            while (l <= r)
            {
                int mid = l + (r - l) / 2;
                if (nums[mid] >= target)
                    r = mid - 1;
                else
                    l = mid + 1;

                if (nums[mid] == target)
                    first = mid;
            }
            return first;
        };

        function<int()> findLast = [&]() -> int 
        {
            int l = 0;
            int r = nums.size() - 1;
            int last = -1;

            while (l <= r)
            {
                int mid = l + (r - l) / 2;
                if (nums[mid] <= target)
                    l = mid + 1; 
                else
                    r = mid - 1;

                if (nums[mid] == target)
                    last = mid;
            }
            return last;
        };

        int first = findFirst();
        if (first == -1) return { -1, -1 };
        int last = findLast();

        return { first, last };
    }
};

int main()
{

}

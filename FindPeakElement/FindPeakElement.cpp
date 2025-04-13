// FindPeakElement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int>& nums)
    {
        int l = 0, r = nums.size() - 1;

        while (l <= r)
        {
            auto mid = l + (l - r) / 2;

            // right neighbour is greater
            if (mid < nums.size() - 1 && nums[mid] < nums[mid + 1])
                l = mid + 1;
            // left neighbour is greater
            else if (mid > 0 && nums[mid] < nums[mid - 1])
                r = mid - 1;
            else return mid;
        }
        return -1;
    }
};

int main()
{

}

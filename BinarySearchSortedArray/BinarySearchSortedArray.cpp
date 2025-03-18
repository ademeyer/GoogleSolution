// BinarySearchSortedArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(const vector<int>& nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (l + (r - l)) / 2;

            if (nums[mid] == target)
                return mid;

            if (nums[mid] < target)
                ++l;
            else
                --r;
        }
        return -1;
    }
};

int main()
{
    Solution s;
    cout << (s.search(vector<int>{1, 2, 3, 4, 5, 6, 7}, 2) == -1 ? "Not Found!" : "Found!") << endl;

    cout << (s.search(vector<int>{1, 2, 3, 4, 5, 6, 7}, 3) == -1 ? "Not Found!" : "Found!") << endl;

    cout << (s.search(vector<int>{1, 1, 1, 1, 2, 2, 2, 2, 3, 4, 5, 6, 7}, 8) == -1 ? "Not Found!" : "Found!") << endl;
}
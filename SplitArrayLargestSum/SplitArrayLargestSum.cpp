// SplitArrayLargestSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>
#include <vector>

using namespace std;

class Solution 
{
public:
    int splitArray(vector<int>& nums, int k) 
    {
        int left = 0, right = 0;
        for (const auto& n : nums)
        {
            right += n;
            left = max(left, n);
        }
        auto result = right;

        function<bool(int)> canSplit = [&](int largest)
        {
            int subArr = 0;
            int curSum = 0;
            for (const auto& n : nums)
            {
                curSum += n;
                if (curSum > largest)
                {
                    subArr += 1;
                    curSum = n;
                }
            }
            return subArr + 1 <= k;
        };

        while (left <= right)
        {
            auto mid = left + (right - left) / 2;
            if (canSplit(mid))
            {
                result = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector <int>nums{ 7, 2, 5, 10, 8 };
    int k = 2;
    cout << "minimized largest sum of the split: " << s.splitArray(nums, k) << endl;

    return 0;
}

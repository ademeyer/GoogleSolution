// LongestConsecutiveSequence.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        int count = 0, longest = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        int val = -1;
        for (const auto i : nums)
        {
            if (s.find(i - 1) == s.end())
            {
                count = 0;
                while (s.find(i + count) != s.end())
                {
                    ++count;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};


int main()
{
    Solution s;
    vector<int> nums_1 = { 100,4,200,1,3,2 };
    auto res = s.longestConsecutive(nums_1);
    cout << "longest consecutive: " << res << endl;

    vector<int> nums_2 = { 0,3,7,2,5,8,4,6,0,1 };
    res = s.longestConsecutive(nums_2);
    cout << "longest consecutive: " << res << endl;
}

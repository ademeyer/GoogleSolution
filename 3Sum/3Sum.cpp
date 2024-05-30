// 3Sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) //if we encounter similar element after the first one
            {
                continue;
            }
            int l = i + 1, r = nums.size() - 1;
            while (l < r)
            {
                int threeSum = nums[i] + nums[l] + nums[r];
                if (threeSum > 0)
                    --r;
                else if (threeSum < 0)
                    ++l;
                else
                {
                    result.push_back({ nums[i], nums[l], nums[r] });
                    ++l;
                    while (nums[l] == nums[l - 1] && l < r)
                        ++l;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int>nums_1 = { -1,0,1,2,-1,-4 };
    auto res = s.threeSum(nums_1);
    cout << "[";
    for (auto v : res)
    {
        cout << "[";
        for (auto i : v)
        {
            cout << i << ", ";
        }
        cout << "], ";
    }
    cout << "]" << endl;

    vector<int>nums_2 = { 0,1,1 };
    res = s.threeSum(nums_2);
    cout << "[";
    for (auto v : res)
    {
        cout << "[";
        for (auto i : v)
        {
            cout << i << ", ";
        }
        cout << "], ";
    }
    cout << "]" << endl;

    vector<int>nums_3 = { 0,0,0 };
    res = s.threeSum(nums_3);
    cout << "[";
    for (auto v : res)
    {
        cout << "[";
        for (auto i : v)
        {
            cout << i << ", ";
        }
        cout << "], ";
    }
    cout << "]" << endl;
}

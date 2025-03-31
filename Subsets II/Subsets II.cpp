// Subsets II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        function<void(int, vector<int>)> dfs = [&](int i, vector<int> subset) 
        {
            if (i == nums.size())
            {
                result.push_back(subset);
                return;
            }

            // All subsets that include nums[i]
            subset.push_back(nums[i]);
            dfs((i + 1), subset);
            subset.pop_back();

            // All subsets that don't include nums[i]
            while ((i + 1) < nums.size() && nums[i] == nums[i + 1])
                ++i;
            dfs(i+1, subset);
        };

        dfs(0, {});
        return result;
    }
};

void Print(const vector<vector<int>>& vec)
{
    cout << "[\n";
    for (const auto& v : vec)
    {
        cout << "[";
        for (const auto i : v)
            cout << i << ",";
        cout << "]\n";
    }
    cout << "]\n\n";
}

int main()
{
    Solution s;
    vector<int> nums{ 1,2,2 };
    auto res = s.subsetsWithDup(nums);
    Print(res);

    nums = { 0 };
    res = s.subsetsWithDup(nums);
    Print(res);
}

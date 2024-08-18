// Permutations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> result;
        
        function<void(vector<int>&, int, vector<vector<int>>&)> dfs =
        [&](vector<int>& nums, int start, vector<vector<int>>& result)
        {
            if (start == nums.size())
            {
                result.push_back(nums);
                return;
            }

            for (int i = start; i < nums.size(); ++i)
            {
                swap(nums[i], nums[start]);
                dfs(nums, start + 1, result);
                swap(nums[i], nums[start]);
            }
        };
        dfs(nums, 0, result);
        return result; 
    }
};

void printVec(const vector<vector<int>>& vec)
{
    cout << "[";
    for (auto v : vec)
    {
        cout << "[";
        for (auto n : v)
            cout << n << ",";
        cout << "], ";
    }
    cout << "]" << endl;
}

int main()
{
    Solution s;
    vector<int> nums = { 1, 2, 3 };
    auto res = s.permute(nums);
    printVec(res);
    nums = { 0, 1 };
    res = s.permute(nums);
    printVec(res);
    nums = { 1 };
    res = s.permute(nums);
    printVec(res);
}

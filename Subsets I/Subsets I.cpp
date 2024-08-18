// Subsets I.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> result;
        vector<int> subset;
        function<void(int)> dfs = [&](int i) 
        {
            if (i >= nums.size())
            {
                result.push_back(subset);
                return;
            }
            // decision to include nums[i]
            subset.push_back(nums[i]);
            dfs(i + 1);
            // decision not to include nums[i]
            subset.pop_back();
            dfs(i + 1);
        };
        dfs(0);
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
    vector<int> nums = {1, 2, 3};
    auto res = s.subsets(nums);
    printVec(res);
    nums = { 0 };
    res = s.subsets(nums);
    printVec(res);

}

// CombinationSumII.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;

        function<void(int, vector<int>, int)> dfs = 
            [&](int i, vector<int> cur, int total) 
        {
            if (total == target)
            {
                result.push_back(cur);
                return;
            }

            if (total > target || i >= candidates.size())
                return;

            // here we include candidate[i]
            cur.push_back(candidates[i]);
            dfs((i + 1), cur, total + candidates[i]);
            cur.pop_back();

            // here we skip candidate[i] and its duplicates
            while ((i + 1 < candidates.size()) && candidates[i] == candidates[i + 1])
                ++i;
            dfs(i + 1, cur, total);
        };
        
        dfs(0, {}, 0);

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
    vector<int> candidates{ 10,1,2,7,6,1,5 };
    int target = 8;
    auto res = s.combinationSum2(candidates, target);
    Print(res);

    candidates = { 2,5,2,1,2 };
    target = 8;
    res = s.combinationSum2(candidates, target);
    Print(res);
}

// CombinationSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Time: 2^t

#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> cur;

        function<void(int, int, vector<int>&, vector<vector<int>>&)> BackTrack = [&](int i, int newTarget, vector<int>& cur, vector<vector<int>>& res)
        {
            if (0 == newTarget)
            {
                res.push_back(cur);
                return;
            }
            if (i >= candidates.size() || newTarget < 0)
                return;

            cur.push_back(candidates[i]);
            BackTrack(i, (newTarget - candidates[i]), cur, res);
            cur.pop_back();
            BackTrack((i + 1), newTarget, cur, res);
        };

        BackTrack(0, target, cur, result);

        return result;
    }
};

int main()
{
    Solution s;
    vector<int> candidates = { 2,3,6,7 };
    auto res = s.combinationSum(candidates, 7);
    cout << "[";
    for (auto arr : res)
    {
        cout << "[";
        for (auto a : arr)
            cout << a << ",";
        cout << "],";
    }
    cout << "]" << endl;

    candidates = { 2,3,5 };
    res = s.combinationSum(candidates, 8);
    cout << "[";
    for (auto arr : res)
    {
        cout << "[";
        for (auto a : arr)
            cout << a << ",";
        cout << "],";
    }
    cout << "]" << endl;
}

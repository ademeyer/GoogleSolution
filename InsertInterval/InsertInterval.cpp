// InsertInterval.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        vector<vector<int>> res;
        for (int i = 0; i < intervals.size(); ++i)
        {
            if (newInterval[1] < intervals[i][0])
            {
                res.push_back(newInterval);
                res.insert(res.end(), intervals.begin() + i, intervals.end());
                return res;
            }
            else if (newInterval[0] > intervals[i][1]) // not overlapping
            {
                res.push_back(intervals[i]);
            }
            else
            {
                newInterval = { min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[i][1]) };
            }
        }
        res.push_back(newInterval);

        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> intervals = { {1,3}, {6,9} };
    vector<int> newInterval = { 2,5 };
    auto result = s.insert(intervals, newInterval);
    cout << '[';
    for (auto Inter : result)
    {
        cout << '[';
        for (auto in : Inter)
            cout << in << ",";
        cout << "],";
    }
    cout << "]" << endl;

    intervals = { {1,2}, {3,5}, {6,7}, {8,10}, {12,16} };
    newInterval = { 4,8 };
    result = s.insert(intervals, newInterval);
    cout << '[';
    for (auto Inter : result)
    {
        cout << '[';
        for (auto in : Inter)
            cout << in << ",";
        cout << "],";
    }
    cout << "]" << endl;
}
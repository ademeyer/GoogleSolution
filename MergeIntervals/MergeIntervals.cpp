// MergeIntervals.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>
#include <algorithm> 
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        // sort O(nlogn)
        function<bool(vector<int>, vector<int>)> comp = [](vector<int> s1, vector<int> s2)
        {
            return s2[0] > s1[0];
        };
        sort(intervals.begin(), intervals.end(), comp);
        
        vector<vector<int>> output = {intervals[0]};

        for (int i = 1; i < intervals.size(); ++i)
        {
            auto last = output.end() - 1;
            auto& lastEnd = (*last)[1];
            auto pos = intervals[i];
            // if there is overlapping
            if (pos[0] <= lastEnd)
                lastEnd = max(lastEnd, pos[1]);
            else
                output.push_back(pos);

        }
        return output;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> intervals = { {1,3}, {2,6}, {8,10}, {15,18} };
    auto result = s.merge(intervals);
    cout << '[';
    for (auto Inter : result)
    {
        cout << '[';
        for (auto in : Inter)
            cout << in << ",";
        cout << "],";
    }
    cout << "]" << endl;

    intervals = { {1,4}, {4,5} };
    result = s.merge(intervals);
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

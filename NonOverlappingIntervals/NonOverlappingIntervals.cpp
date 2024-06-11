// NonOverlappingIntervals.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm> 
using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        // sort O(nlogn)
        function<bool(vector<int>, vector<int>)> comp = [](vector<int> s1, vector<int> s2)
        {
            return s2[0] > s1[0];
        };
        sort(intervals.begin(), intervals.end(), comp);

        int removal = 0;

        auto prevEnd = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i][0] >= prevEnd)
                prevEnd = intervals[i][1];
            else
            {
                ++removal;
                prevEnd = min(intervals[i][1], prevEnd);
            }
        }

        return removal;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> intervals = { {1,2}, {2,3}, {3,4}, {1,3} };
    auto result = s.eraseOverlapIntervals(intervals);
    cout << "result: " << result << endl;

    intervals = { {1,2}, {1,2}, {1,2} };
    result = s.eraseOverlapIntervals(intervals);
    cout << "result: " << result << endl;

    intervals = { {1,2}, {2,3} };
    result = s.eraseOverlapIntervals(intervals);
    cout << "result: " << result << endl;

    intervals = { {0,2},  {1,3}, {2,4}, {3,5}, {4,5} };
    result = s.eraseOverlapIntervals(intervals);
    cout << "result: " << result << endl;
}
// MeetingScheduleII.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

class Interval
{
public:
    int start, end;
    Interval(int start, int end)
    {
        this->start = start;
        this->end = end;
    }
};

class Solution
{
public:
    int minMeetingRooms(vector<Interval>& intervals)
    {
        vector<int> start, end;
        for (auto ch : intervals)
        {
            start.push_back(ch.start);
            end.push_back(ch.end);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int res = 0, count = 0;
        int s = 0, e = 0;

        while (s < intervals.size())
        {
            if (start[s] < end[e])
            {
                ++s;
                ++count;
            }
            else
            {
                ++e;
                --count;
            }
            res = max(res, count);
        }
        return res;
    }
};

int main()
{
    Solution s;
    Interval I1(0, 40);
    Interval I2(5, 10);
    Interval I3(15, 20);
    vector<Interval> intervals = { I1, I2, I3 };
    cout << s.minMeetingRooms(intervals) << endl;

    Interval I4(4, 9);
    intervals = { I4 };
    cout << s.minMeetingRooms(intervals) << endl;
}

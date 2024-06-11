// MeetingSchedule.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>
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
    bool canAttendMeetings(vector<Interval>& intervals)
    {
        function<bool(Interval, Interval)> comp = [](Interval s1, Interval s2)
        {
            return s2.start > s1.start;
        };
        sort(intervals.begin(), intervals.end(), comp);

        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i - 1].end > intervals[i].start)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    Interval I1(0, 30);
    Interval I2(5, 10);
    Interval I3(15, 20);
    vector<Interval> intervals = {I1, I2, I3};
    cout << (s.canAttendMeetings(intervals) ? "True" : "False") << endl;

    Interval I4(5, 8);
    Interval I5(9, 15);
    intervals = { I4, I5 };
    cout << (s.canAttendMeetings(intervals) ? "True" : "False") << endl;
}
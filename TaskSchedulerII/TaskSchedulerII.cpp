// TaskSchedulerII.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution 
{
public:
    long long taskSchedulerII(vector<int>& tasks, int space) 
    {
        unordered_map<int, long long> lastExecDay;
        long long curDay = 1; // first day

        for (auto t : tasks)
        {
            if (lastExecDay.find(t) != lastExecDay.end())
            {
                // enforce cooldown: wait until 
                if (curDay <= lastExecDay[t] + space)
                {
                    curDay = lastExecDay[t] + space + 1;
                }
            }

            // perform the task
            lastExecDay[t] = curDay;
            ++curDay;
        }
        return curDay - 1;
    }
};

int main()
{
    Solution s;
    vector<int> tasks = { 1,2,1,2,3,1 }; int space = 3;
    cout << "day: " << s.taskSchedulerII(tasks, space) << endl;

    tasks = { 5,8,8,5 }; space = 2;
    cout << "day: " << s.taskSchedulerII(tasks, space) << endl;

    return 0;
}

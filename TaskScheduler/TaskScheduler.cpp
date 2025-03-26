// TaskScheduler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        // each task 1 unit time
        // minimize idle time

        vector<int> count(26, 0);
        for (const auto& t : tasks)
            count[t - 'A']++;

        priority_queue<int> maxHeap;
        for (const auto& cnt : count)
        {
            if (cnt > 0)
                maxHeap.push(cnt);
        }

        int time = 0;
        queue<pair<int, int>> q; // count, time

        while (!maxHeap.empty() || !q.empty())
        {
            ++time;

            if (maxHeap.empty())
            {
                time = q.front().second;
            }
            else
            {
                int cnt = maxHeap.top() - 1;
                maxHeap.pop();
                if (cnt > 0)
                {
                    q.push({ cnt, time + n });
                }
            }

            if (!q.empty() && q.front().second == time)
            {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};

int main()
{
    Solution s;
    vector<char>tasks{'A', 'A', 'A', 'B', 'B', 'B' };
    int n = 2;
    cout << "unit time: " << s.leastInterval(tasks, n) << endl;
}

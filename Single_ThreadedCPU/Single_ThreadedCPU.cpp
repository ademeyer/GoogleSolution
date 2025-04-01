// Single_ThreadedCPU.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class compare 
{
public:
    bool operator()(const pair<int, int>& a, const pair<int, int>& b)
    {
        return a.first >= b.first;
    }
};

class Solution
{
public:
    vector<int> getOrder(vector<vector<int>>& tasks)
    {
        int i = 0;
        for (auto& t : tasks)
            t.push_back(i++);

        // sort tasks
        sort(tasks.begin(), tasks.end(), 
            [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });

        // we don't need to sort again
        vector<int> res;
        priority_queue<pair<int,int>, vector<pair<int, int>>, compare> minHeap;
        i = 0;
        auto time = tasks[0][0];
        while (!minHeap.empty() || i < tasks.size())
        {
            while (i < tasks.size() && time >= tasks[i][0])
            {
                minHeap.push({ tasks[i][1], tasks[i][2] }); // processingTime, index
                ++i;
            }
            if (minHeap.empty())
            {
                time = tasks[i][0];
            }
            else
            {
                auto [procTime, index] = minHeap.top(); minHeap.pop(); // require C++20
                time += procTime;
                res.push_back(index);
            }
        }
        return res;
    }
};
void Print(const vector<int> vec)
{
    cout << '[';
    for (const auto& v : vec)
        cout << v << ',';
    cout << "]\n";
}
int main()
{
    Solution s;
    vector<vector<int>> tasks{ {1,2}, {2,4}, {3,2}, {4,1} };
    auto res = s.getOrder(tasks);
    Print(res);

    tasks = { {7,10}, {7,12}, {7,5}, {7,4}, {7,2} };
    res = s.getOrder(tasks);
    Print(res);

    return 0;
}

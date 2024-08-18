// Single_ThreadedCPU.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> getOrder(vector<vector<int>>& tasks)
    {
        //sort(tasks.begin(), tasks.end());
        vector<pair<int, vector<int>>>indexedTask;
        int i = 0;
        for (auto t : tasks)
        {
            indexedTask.push_back({i, t});
            ++i;
        }
        // we don't need to sort again
        vector<int> res;
        priority_queue<vector<int>> minHeap;

    }
};

int main()
{
    std::cout << "Hello World!\n";
}

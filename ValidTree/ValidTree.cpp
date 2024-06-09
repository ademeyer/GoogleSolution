// ValidTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Time = Space = O(V+E);


#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <functional>
using namespace std;

class Solution
{
public:
    bool validTree(int n, vector<vector<int>>& edges)
    {
        if (n == 0)
            return true;

        unordered_map<int, vector<int>> hashMap;
        for (auto edge : edges)
        {
            hashMap[edge[0]].push_back(edge[1]);
            hashMap[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> visited;

        function<bool(int, int)> dfs = [&](int node, int prevNode)
        {
            if (visited.count(node))
                return false;

            visited.insert(node);
            for (auto j : hashMap[node])
            {
                if (j == prevNode)
                    continue;
                if (!dfs(j, node))
                    return false;
            }
            return true;
        };

        return (dfs(0, -1) && n == visited.size());
    }
};


int main()
{
}
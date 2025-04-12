// FindClosestNodeToGivenTwoNodes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <unordered_map>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2)
    {
        auto n = edges.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; ++i)
            adj[i].push_back(edges[i]);

        auto bfs = [&](int src, unordered_map<int, int>& distMap) 
        {
            queue<pair<int, int>> q; // node, distance
            q.push({ src, 0 });
            distMap[src] = 0;
            while (!q.empty())
            {
                auto [node, dist] = q.front(); q.pop(); // requires C++20
                if (node < 0) continue;
                for (const auto& nei : adj[node]) // find neighbors
                {
                    if (distMap.find(nei) == distMap.end()) // if not added, add
                    {
                        q.push({ nei, dist + 1 });
                        distMap[nei] = dist + 1;
                    }
                }
            }
        };

        unordered_map<int, int>node1Dist;
        unordered_map<int, int>node2Dist;
        bfs(node1, node1Dist);
        bfs(node2, node2Dist);

        auto res = -1;
        auto resDist = INT_MAX;

        for (int i = 0; i < n; ++i)
        {
            if (node1Dist.find(i) != node1Dist.end() && 
                node2Dist.find(i) != node2Dist.end())
            {
                auto dist = max(node1Dist[i], node2Dist[i]);
                if (dist < resDist)
                {
                    res = i;
                    resDist = dist;
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<int>edges = { 2, 2, 3, -1 };
    int node1 = 0, node2 = 1;
    cout << s.closestMeetingNode(edges, node1, node2) << endl;
    return 0;
}

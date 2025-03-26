// CourseScheduleII.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <functional>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // build adjacency list of prereqs
        vector<vector<int>> prereq(numCourses);
        for (const auto& p : prerequisites)
            prereq[p[0]].push_back(p[1]);

        // a course has 3 possible states:
        // - visited -> crs has been added to output
        // - visiting -> crs not added to ouptut, but added to cycle
        // - unvisited -> crs not added to output or cycle
        vector<int> result;
        set<int> cycle, visited;

        function<bool(int)> dfs = [&](int crs)
        {
            if (cycle.count(crs))
                return false;
            if(visited.count(crs))
                return true;

            cycle.insert(crs);
            for (const auto& pre : prereq[crs])
            {
                if (!dfs(pre)) // if we detect a cycle
                    return false;
            }
            cycle.erase(crs); // we didn't detect any cycle
            visited.insert(crs); // mark as visited
            result.push_back(crs); // add to result
            return true;
        };

        for (int c = 0; c < numCourses; ++c)
        {
            if (!dfs(c))
                return {};
        }

        return result;
    }
};

int main()
{
}

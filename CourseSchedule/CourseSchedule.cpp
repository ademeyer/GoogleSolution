// CourseSchedule.cpp : This file contains the 'main' function. Program execution begins and ends there.
//      Time: O(V + E)
//      Space: O(V + E)

#include <iostream>
#include <functional>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        unordered_map<int, vector<int>> courseMap;
        for (int i = 0; i < prerequisites.size(); ++i)
            courseMap[prerequisites[i][0]].push_back(prerequisites[i][1]);

        unordered_set<int> visited;

        function<bool(int)> dfs = [&](int c)
        {
            // if we have seen the course before
            if (visited.count(c))
                return false;

            if (courseMap[c].empty())
                return true;

            // mark as seen
            visited.insert(c);
            for (int i = 0; i < courseMap[c].size(); ++i)
            {
                int nextCourse = courseMap[c][i];
                if (!dfs(nextCourse))
                    return false;
            }

            courseMap[c].clear();
            visited.erase(c);
            return true;
        };

        for (int course = 0; course < numCourses; ++course)
        {
            if (!dfs(course))
                return false;
        }
        return true;
    }
};

int main()
{

}


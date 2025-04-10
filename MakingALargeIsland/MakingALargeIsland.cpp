// MakingALargeIsland.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int largestIsland(vector<vector<int>>& grid)
    {
        auto N = grid.size();

        auto out_of_bound = [&](int r, int c) 
        {
            return r < 0 || c < 0 || r == N || c == N;
        };

        function<int(int, int, int)> dfs =
            [&](int r, int c, int label) -> int 
        {
            if (out_of_bound(r, c) || grid[r][c] != 1) //|| grid[r][c] == label
                return 0;

            grid[r][c] = label;
            auto size = 1;
            const vector<pair<int, int>> nei = { {r + 1, c}, {r - 1, c}, {r, c + 1}, {r, c - 1} };

            for (const auto& [nr, nc] : nei)
                size += dfs(nr, nc, label);
            return size;
        };

        // 1. precompute areas
        unordered_map<int, int> size; // label, size
        int label = 2;

        for (int r = 0; r < N; ++r)
        {
            for (int c = 0; c < N; ++c)
            {
                if (grid[r][c] == 1)
                {
                    size[label] = dfs(r, c, label);
                    ++label;
                }
            }
        }

        auto connect = [&](int r, int c) -> int 
        {
            auto res = 1;
            const vector<pair<int, int>> nei = { {r + 1, c}, {r - 1, c}, {r, c + 1}, {r, c - 1} };
            unordered_set<int> visited;
            visited.insert(0);
            for (const auto& [nr, nc] : nei)
            {
                if (!out_of_bound(nr, nc) && !visited.count(grid[nr][nc]))
                {
                    res += size[grid[nr][nc]];
                    visited.insert(grid[nr][nc]);
                }
            }
            return res;
        };
        // 2. Try flipping water
        int result = 0;
        if (!size.empty())
        {
            for (const auto& [k, v] : size)
                result = max(result, v);
        }
        for (int r = 0; r < N; ++r)
        {
            for (int c = 0; c < N; ++c)
            {
                if (grid[r][c] == 0)
                    result = max(result, connect(r, c)); // connect island
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid = { {1,0}, {0,1} };
    cout << s.largestIsland(grid) << endl;

    grid = { {1,1}, {1,0} };
    cout << s.largestIsland(grid) << endl;

    grid = { {1,1}, {1,1} };
    cout << s.largestIsland(grid) << endl;

    return 0;
}

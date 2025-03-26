// RottingOranges.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        queue<pair<int, int>> q;
        int time = 0, freshOrange = 0;
        int ROW = grid.size(), COLS = grid[0].size();

        for (int r = 0; r < ROW; ++r)
        {
            for (int c = 0; c < COLS; ++c)
            {
                // if it is a fresh orange
                if (grid[r][c] == 1)
                    ++freshOrange;

                // if it is a rotten orange
                if (grid[r][c] == 2)
                    q.push({r, c});
            }
        }

        // 4 - directionally adjacent movement
        vector<pair<int, int>> dirs = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
        while (!q.empty() && freshOrange > 0)
        {
            int n = q.size();
            for (int i = 0; i < n; ++i)
            {
                auto orange = q.front(); q.pop();
                auto r = orange.first;
                auto c = orange.second;
                for (const auto& [dr, dc] : dirs) // requires cpp >= C++20
                {
                    auto row = dr + r;
                    auto col = dc + c;
                    if (row < 0 || row == ROW   ||
                        col < 0 || col == COLS  ||
                        grid[row][col] != 1)
                        continue;
                    // orange is inbound and fresh, we make rotten
                    grid[row][col] = 2;
                    q.push({ row, col });
                    --freshOrange;
                }
            }
            ++time;
        }

         return freshOrange == 0 ? time : -1;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid = { { 2,1,1 }, { 1,1,0 }, { 0,1,1 } };
    cout << "time taken: " << s.orangesRotting(grid) << "s\n";

    grid = { { 2,1,1 }, { 0,1,1 }, { 1,0,1 } };
    cout << "time taken: " << s.orangesRotting(grid) << "s\n";

    grid = { { 0,2 } };
    cout << "time taken: " << s.orangesRotting(grid) << "s\n";

    grid = { { 2,1,1 }, { 1,1,1 }, { 0,1,2 } };
    cout << "time taken: " << s.orangesRotting(grid) << "s\n";

    return 0;
}

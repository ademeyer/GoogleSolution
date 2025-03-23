// NumberOfIslands.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <functional>
#include <queue>
#include <set>
using namespace std;

/*
class Solution
{
public:
    int numIslands(vector<vector<char>>& grid)
    {
        if (grid.empty())
            return 0;
        int rows = grid.size();
        int cols = grid[0].size();

        set<pair<int, int>> visited;
        int island = 0;

        function<void(int, int)> bfs = [&](int r, int c)
        {
            queue<pair<int, int>> q;
            visited.insert({ r,c });
            q.push({ r,c });
            const vector<pair<int, int>> dirs = { {1,0}, {-1,0}, {0,1}, {0, -1} };

            while (!q.empty())
            {
                auto loc = q.front(); q.pop();
                int row = loc.first;
                int col = loc.second;

                for (auto dir : dirs)
                {
                    int i = row + dir.first;
                    int j = col + dir.second;

                    if (i < rows &&
                        j < cols &&
                        grid[i][j] == '1' &&
                        visited.count({ i, j }) == 0)
                    {
                        q.push({ i, j });
                        visited.insert({ i, j });
                    }
                }
            }

        };

        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                if (grid[r][c] == '1' && visited.count({ r,c }) == 0)
                {
                    bfs(r, c);
                    ++island;
                }
            }
        }


        return island;
    }
};
*/

class Solution
{

    void mark_visited(vector<vector<char>>&grid, int i, int j, int row, int col)
    {
        if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j] != '1') return;

        grid[i][j] = '2';

        mark_visited(grid, i - 1, j, row, col); //left
        mark_visited(grid, i + 1, j, row, col); //right
        mark_visited(grid, i, j - 1, row, col); //up
        mark_visited(grid, i, j + 1, row, col); //down
    }
public:
    int numIslands(vector<vector<char>>&grid)
    {
        int row = grid.size();
        if (row == 0) return 0;
        int col = grid[0].size();

        int ans = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == '1')
                {
                    ans++;
                    mark_visited(grid, i, j, row, col);
                }
            }
        }

        return ans;
    }
};

int main()
{
}
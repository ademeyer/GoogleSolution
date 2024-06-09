// NumberOfIslands.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <functional>
#include <queue>
#include <set>
using namespace std;

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
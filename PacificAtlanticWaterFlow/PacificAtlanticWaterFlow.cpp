// PacificAtlanticWaterFlow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <set>
#include <functional>
using namespace std;
using pairs = pair<int,int>;
class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        int ROWS = heights.size();
        int COLS = heights[0].size();
        set<pairs> pac, atl;

        function<void(int, int, set<pairs>&, int)> dfs = [&](int r, int c, set<pairs>& visited, int prevHeight)
        {
            if (visited.count({ r,c }) || r < 0 || c < 0 ||
                r == ROWS || c == COLS || heights[r][c] < prevHeight)
                return;
            visited.insert({ r,c });
            dfs(r + 1, c, visited, heights[r][c]);
            dfs(r - 1, c, visited, heights[r][c]);
            dfs(r, c + 1, visited, heights[r][c]);
            dfs(r, c - 1, visited, heights[r][c]);
        };

        for (int c = 0; c < COLS; ++c)
        {
            dfs(0, c, pac, heights[0][c]);
            dfs(ROWS - 1, c, atl, heights[ROWS - 1][c]);
        }

        for (int r = 0; r < ROWS; ++r)
        {
            dfs(r, 0, pac, heights[r][0]);
            dfs(r, COLS - 1, atl, heights[r][COLS - 1]);
        }
        vector<vector<int>> result;
        for (int r = 0; r < ROWS; ++r)
        {
            for (int c = 0; c < COLS; ++c)
            {
                if (pac.count({ r,c }) && atl.count({ r,c }))
                {
                    result.push_back({ r,c });
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> heights = 
    {
        {1,2,2,3,5},
        {3,2,3,4,4},
        {2,4,5,3,1},
        {6,7,1,4,5}
    };
    auto res = s.pacificAtlantic(heights);
    cout << "[";
    for (auto r : res)
    {
        cout << "[";
        for (auto i : r)
        {
            cout << i << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;
     
    return 0;
}

// EqualRowAndColumnPairs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution 
{
public:
    int equalPairs(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        unordered_map<string, int> rowFreq;
        int cnt = 0;

        // store each row frequency with string key
        for (int i = 0; i < n; ++i)
        {
            string rowstr = "";
            for (int j = 0; j < n; ++j)
                rowstr += to_string(grid[i][j]) + ",";
            rowFreq[rowstr]++;
        }

        // check each column against the rows
        for (int j = 0; j < n; ++j)
        {
            string colstr = "";
            for (int i = 0; i < n; ++i)
                colstr += to_string(grid[i][j]) + ",";
            
            if (rowFreq.find(colstr) != rowFreq.end())
                cnt += rowFreq[colstr];
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> grid = { {3,2,1}, {1,7,6}, {2,7,7} };
    cout << "no. of equare pairs: " << s.equalPairs(grid) << endl;

    grid = { {3,1,2,2}, {1,4,4,5}, {2,4,2,2}, {2,4,2,2} };
    cout << "no. of equare pairs: " << s.equalPairs(grid) << endl;

    return 0;
}
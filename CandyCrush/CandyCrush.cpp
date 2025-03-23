// CandyCrush.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board)
    {
        auto m = board.size(); // row
        auto n = board[0].size(); // column

        bool needCrush = false;

        // check horrizontally
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n - 2; ++j)
            {
                if (abs(board[i][j]) == abs(board[i][j + 1]) &&
                    abs(board[i][j]) == abs(board[i][j + 2]) &&
                    abs(board[i][j]) != 0)
                {
                    board[i][j] = -abs(board[i][j]);
                    board[i][j+1] = -abs(board[i][j]);
                    board[i][j+2] = -abs(board[i][j]);
                    needCrush = true;
                }
            }
        }

        // check vertically
        for (int i = 0; i < m - 2; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (abs(board[i][j]) == abs(board[i+1][j]) &&
                    abs(board[i][j]) == abs(board[i+2][j]) &&
                    abs(board[i][j]) != 0)
                {
                    board[i][j] = -abs(board[i][j]);
                    board[i+1][j] = -abs(board[i][j]);
                    board[i+2][j] = -abs(board[i][j]);
                    needCrush = true;
                }
            }
        }

        // crush marked
        for (int j = 0; j < n; ++j)
        {
            auto newLevel = m - 1;
            for (int i = m - 1; i >= 0; --i)
            {
                if (board[i][j] > 0)
                {
                    board[newLevel][j] = board[i][j];
                    --newLevel;
                }
            }

            for (int i = 0; i < newLevel + 1; ++i)
                board[i][j] = 0;
        }
        if (needCrush)
            return candyCrush(board);
        else
            return board;
    }
};

void Print(const vector<vector<int>>& board)
{
    cout << "[ ";
    for (const auto& row : board)
    {
        cout << "[ ";
        for (const auto& col : row)
            cout << col << " ,";
        cout << " ]\n";
    }
    cout << " ]\n";
}


int main()
{
    Solution s;
    vector<vector<int>> board = { { 110, 5, 112, 113, 114},
                                   {210, 211, 5, 213, 214},
                                    {310, 311, 3, 313, 314},
                                    {410, 411, 412, 5, 414},
                                    {5, 1, 512, 3, 3},
                                    {610, 4, 1, 613, 614},
                                    {710, 1, 2, 713, 714},
                                    {810, 1, 2, 1, 1},
                                    {1, 1, 2, 2, 2},
                                    {4, 1, 4, 4, 1014} };
    auto r = s.candyCrush(board);
    Print(r);

    board =                     { { 1,3,5,5,2},
                                   {3,4,3,3,1},
                                    {3,2,4,5,2},
                                    {2,4,4,5,5},
                                    {1,4,4,1,1} };
    r = s.candyCrush(board);
    Print(r);

    return 0;
}

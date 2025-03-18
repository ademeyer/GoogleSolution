// GameOfLife.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void gameOfLife(vector<vector<int>>& board)
    {
        /*
            Original | New | State
                0       0       0 
                1       0       1
                0       1       2
                1       1       3
        */

        int row = board.size(), col = board[0].size();

        auto countNeighbors = [&](int r, int c) -> int
        {
            int nei = 0;
            for (int i = r - 1; i < r + 2; ++i)
            {
                for (int j = c - 1; j < c + 2; ++j)
                {
                    if ((i == r && j == c) || i < 0 || 
                        j < 0 || i == row || j == col)
                        continue;
                    if (board[i][j] == 1 || board[i][j] == 3)
                        ++nei;
                }
            }
            return nei;
        };

        for (int r = 0; r < row; ++r)
        {
            for (int c = 0; c < col; ++c)
            {
                int noOfNei = countNeighbors(r, c);

                // check if alive or dead, and apply rules
                if (board[r][c] == 1)
                {
                    if (noOfNei == 2 || noOfNei == 3)
                        board[r][c] = 3;
                }
                else if (noOfNei == 3)
                    board[r][c] = 2;
            }
        }

        // transform rule to life and death
        for (int r = 0; r < row; ++r)
        {
            for (int c = 0; c < col; ++c)
            {
                if (board[r][c] == 1)
                    board[r][c] = 0;
                else if (board[r][c] == 2 || board[r][c] == 3)
                    board[r][c] = 1;
            }
        }
    }
};

void printMatrix(const vector<vector<int>>& matrix)
{
    cout << "[";
    for (const auto m : matrix)
    {
        cout << "[";
        for (auto n : m)
            cout << n << ",";
        cout << "]\n";
    }
    cout << "]\n";
}

int main()
{
    Solution s;
    vector<vector<int>> board{ {0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0 } };
    s.gameOfLife(board);
    printMatrix(board);

    board = { {1, 1}, {1, 0} };
    s.gameOfLife(board);
    printMatrix(board);
}

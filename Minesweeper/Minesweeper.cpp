// Minesweeper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <functional>
#include <iostream>
#include <vector>
using namespace std;

/*
Approach
Check the Clicked Cell:

If the clicked cell is a mine ('M'), change it to 'X' and return the board immediately as the game is over.

If the clicked cell is an unrevealed empty square ('E'), we need to reveal it. The way it is revealed depends on the number of adjacent mines:

If there are no adjacent mines, reveal it as a blank ('B') and recursively reveal all adjacent unrevealed cells.

If there are adjacent mines, reveal it as a digit representing the count of adjacent mines.

Count Adjacent Mines: For any given cell, count the number of adjacent mines (in all 8 possible directions: up, down, left, right, and the four diagonals).

Recursive Reveal: If a cell is revealed as blank ('B'), recursively reveal all adjacent unrevealed cells ('E') following the same rules.
*/

class Solution 
{
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) 
    {

        int n = board.size(), m = board[0].size();
        auto countMines = [&](int x, int y) 
        {
            int count = 0;
            for (int i = -1; i <= 1; ++i)
            {
                for (int j = -1; j <= 1; ++j)
                {
                    if (i == 0 && j == 0) continue;
                    int nx = x + i, ny = y + j;
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                        board[nx][ny] == 'M')
                        ++count;
                }
            }
            return count;
        };
        
        function<void(int, int)> reveal = [&](int x, int y)
        {
            // check out-bound or board cell is empty
            if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] != 'E')
                return;

            auto mines = countMines(x, y);
            if (mines > 0)
                board[x][y] = '0' + mines; // number of discovered mins
            else
            {
                board[x][y] = 'B'; // mark as blank
                for (int i = -1; i <= 1; ++i)
                {
                    for (int j = -1; j <= 1; ++j)
                    {
                        if (i == 0 && j == 0) continue; // don't repeat self
                        reveal(x + i, y + j);
                    }
                }
            }
        };
        int x = click[0], y = click[1];
        if (board[x][y] == 'M')
        {
            board[x][y] = 'X';
            return board;
        }
        reveal(x, y);
        return board;
    }
};

int main()
{
}

// WordSearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Time: M x N x 4 ^ L: L = word len

#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        const int ROWS = board.size();
        const int COLS = board[0].size();

        function<bool(int, int, int)> BackTrack = [&](int r, int c, int iword)
        {
            if (iword == word.size())
                return true;

            if (r < 0 || c < 0 || r >= ROWS || c >= COLS ||
                word[iword] != board[r][c])
                return false;

            char temp = board[r][c];
            board[r][c] = '\0';

            if (
                BackTrack(r + 1, c, (iword + 1)) ||
                BackTrack(r - 1, c, (iword + 1)) ||
                BackTrack(r, c + 1, (iword + 1)) ||
                BackTrack(r, c - 1, (iword + 1)) )
                return true;

            board[r][c] = temp;
            return false;
        };

        for (int i = 0; i < ROWS; ++i)
            for (int j = 0; j < COLS; ++j)
                if (BackTrack(i, j, 0))
                    return true;

        return false;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> board = { {'A','B','C','E'} ,{'S','F','C','S'},{'A','D','E','E'} };
    cout << "Key word " << (s.exist(board, "ABCCED") ? "" : "does not ") << "exists in Word Board" << endl;
    cout << "Key word " << (s.exist(board, "SEE") ? "" : "does not ") << "exists in Word Board" << endl;
    cout << "Key word " << (s.exist(board, "ABCB") ? "" : "does not ") << "exists in Word Board" << endl;
    board = { {'A','A','A','A', 'A', 'A'} ,{'A','A','A','A', 'A', 'A'}, {'A','A','A','A', 'A', 'A'}, {'A','A','A','A', 'A', 'A'}, {'A','A','A','A', 'A', 'A'}, {'A','A','A','A', 'A', 'A'} };
    cout << "Key word " << (s.exist(board, "AAAAAAAAAAAAAAa") ? "" : "does not ") << "exists in Word Board" << endl;
    return 0;
}


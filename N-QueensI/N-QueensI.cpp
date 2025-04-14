// N-QueensI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <functional>
using namespace std;

class Solution 
{
public:
    vector<vector<string>> solveNQueens(int n) 
    {
        unordered_set<int> col, posDiag, negDiag; // c, r + c, r - c
        vector<vector<string>> res, board(n, vector<string>(n, "."));

        function<void(int)> backtrack = [&](int r) 
        {
            if (r == n)
            {
                vector<string>copy;
                for (const auto& n : board)
                {
                    string temp = "";
                    for (const auto& i : n)
                        temp += i;
                    copy.push_back(temp);
                }
                res.push_back(copy);
                return;
            }

            for (int c = 0; c < n; ++c)
            {
                if (col.count(c) || posDiag.count(r + c) || negDiag.count(r - c))
                    continue;

                // update the point in sets
                col.insert(c);
                posDiag.insert(r + c);
                negDiag.insert(r - c);
                board[r][c] = "Q";

                backtrack(r + 1);

                // remove the point in sets
                col.erase(c);
                posDiag.erase(r + c);
                negDiag.erase(r - c);
                board[r][c] = ".";
            }
        };

        backtrack(0);

        return res;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

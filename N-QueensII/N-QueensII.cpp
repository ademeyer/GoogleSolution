// N-QueensII.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <functional>
using namespace std;

class Solution
{
public:
    int totalNQueens(int n)
    {
        unordered_set<int> col, posDiag, negDiag; // c, r + c, r - c
        int res;

        function<void(int)> backtrack = [&](int r)
        {
            if (r == n)
            {
                ++res;
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

                backtrack(r + 1);

                // remove the point in sets
                col.erase(c);
                posDiag.erase(r + c);
                negDiag.erase(r - c);
            }
        };

        backtrack(0);

        return res;
    }
};


int main()
{
}

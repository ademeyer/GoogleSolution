// UniquePaths.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<int> row(n, 1);

        for (int i = 0; i < (m - 1); ++i)
        {
            vector<int> newRow(n, 1);
            for (int j = (n - 2); j >= 0; --j)
            {
                newRow[j] = newRow[j + 1] + row[j];
            }
            row = newRow;
        }
        return row[0];
    }
};

int main()
{
}

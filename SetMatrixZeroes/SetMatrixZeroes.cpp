// SetMatrixZeroes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();
        bool rowIsZero = false;

        // determine which rows/cols need to be zeroed
        for (int r = 0; r < ROWS; ++r)
        {
            for (int c = 0; c < COLS; ++c)
            {
                if (matrix[r][c] == 0)
                {
                    matrix[0][c] = 0;
                    if (r > 0)
                        matrix[r][0] = 0;
                    else
                        rowIsZero = true;
                }
            }
        }
        // Zero out row-column pair if needed
        for (int r = 1; r < ROWS; ++r)
        {
            for (int c = 1; c < COLS; ++c)
            {
                if (matrix[0][c] == 0 || matrix[r][0] == 0)
                {
                    matrix[r][c] = 0;
                }
            }
        }

        // zero out first column of matrix if needed
        if (matrix[0][0] == 0)
        {
            for (int r = 0; r < ROWS; ++r)
                matrix[r][0] = 0;
        }

        // zero out all first row if needed
        if (rowIsZero)
        {
            for (int c = 0; c < COLS; ++c)
                matrix[0][c] = 0;
        }
    }
};

int main()
{
}
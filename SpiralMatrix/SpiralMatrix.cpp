// SpiralMatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> res;
        int left = 0, right = matrix[0].size() - 1;
        int top = 0, bottom = matrix.size() - 1;

        while (left <= right && top <= bottom)
        {
            // get every i in the top row
            for (int i = left; i <= right; ++i)
            {
                res.push_back(matrix[top][i]);
            }
            ++top;

            // get every i in the right col
            for (int i = top; i <= bottom; ++i)
            {
                res.push_back(matrix[i][right]);
            }
            --right;


            // get every i in the bottom row
            if (top <= bottom)
            {
                for (int i = right; i >= left; --i)
                {
                    res.push_back(matrix[bottom][i]);
                }
            }
            --bottom;

            // get every i in the left col
            if (left <= right)
            {
                for (int i = bottom; i >= top; --i)
                {
                    res.push_back(matrix[i][left]);
                }
            }
            ++left;
        }
        return res;
    }
};

int main()
{
}
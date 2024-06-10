// RotateImage.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>>& matrix)
    {
        int l = 0;
        int r = matrix.size() - 1;

        while (l < r)
        {
            for (int i = 0; i < r - l; ++i)
            {
                int top = l;
                int bottom = r;

                // save the top left
                auto topLeft = matrix[top][l + i];

                // move bottom right into top left
                matrix[top][l + i] = matrix[bottom - i][l];

                // move bottom right to bottom left
                matrix[bottom - i][l] = matrix[bottom][r - i];

                // move top right into bottom right
                matrix[bottom][r - i] = matrix[top + i][r];

                // move top left into top right
                matrix[top + i][r] = topLeft;
            }

            --r;
            ++l;
        }
    }
};

int main()
{
}
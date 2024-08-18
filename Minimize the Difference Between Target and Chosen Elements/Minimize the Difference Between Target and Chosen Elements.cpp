// Minimize the Difference Between Target and Chosen Elements.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;


class Solution
{
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<bool>> dp(m + 1, vector<bool>(5000, false));
        dp[0][0] = true;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < 5000; ++j)
            {
                if (dp[i][j])
                {
                    for (int k = 0; k < n; ++k)
                    {
                        dp[i + 1][j + mat[i][k]] = true;
                    }
                }
            }
        }

        int result = INT_MAX;
        for (int i = 0; i < 5000; ++i)
        {
            if (dp[m][i])
            {
                result = min(result, abs(i - target));
            }
        }

        return result;
    }
};

int main()
{
    vector<vector<int>> mat = { {1,2,3}, {4,5,6}, {7,8,9} };
    int target = 13;
    Solution s;
    cout << s.minimizeTheDifference(mat, target) << endl; // Output: 1
    mat = { {1}, {2}, {3} };
    target = 100;
    cout << s.minimizeTheDifference(mat, target) << endl; // Output: 1
    mat = { {1,2,9,8,7} };
    target = 6;
    cout << s.minimizeTheDifference(mat, target) << endl; // Output: 1

    return 0;
}
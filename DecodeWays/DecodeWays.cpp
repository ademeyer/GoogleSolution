// DecodeWays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>
#include <vector>
using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        vector<int> dp(s.size()+1, 1);

        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (s[i] == '0')
                dp[i] = 0;
            else
                dp[i] = dp[i + 1];

            if ((i + 1) < s.size() && // if (i+1) is inbound
                (s[i] == '1') || (s[i] == '2' && // if s[i+1] is within 10 - 26
                (s[i + 1] >= '0' && s[i + 1] <= '6')))
            {
                dp[i] += dp[i + 2];
            }
        }
        return dp[0];
    }
};

int main()
{
    Solution s;
    string st = "12";
    cout << s.numDecodings(st) << endl;

    st = "226";
    cout << s.numDecodings(st) << endl;

    st = "06";
    cout << s.numDecodings(st) << endl;
}

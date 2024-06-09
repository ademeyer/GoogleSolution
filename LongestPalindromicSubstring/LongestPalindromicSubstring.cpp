// LongestPalindromicSubstring.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
    Time: O(n^2)
    Space: O(1)
*/

#include <iostream>
#include <functional>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        string result = "";
        int resLen = 0;

        function<void(int, int)> checkLongestPalindrome = [&](int l, int r)
        {
            while (l >= 0 && r < s.size() && s[l] == s[r])
            {
                if (r - l + 1 > resLen)
                {
                    result = s.substr(l, (r - l + 1));
                    resLen = r - l + 1;
                }
                l -= 1;
                r += 1;
            }
        };

        for (int i = 0; i < s.size(); ++i)
        {
            // check odd len string
            checkLongestPalindrome(i, i);
            // check even len string
            checkLongestPalindrome(i, i + 1);
        }

        return result;
    }
};

int main()
{
    Solution s;
    string st = "babad";
    cout << s.longestPalindrome(st) << endl;
    st.clear();
    st = "cbbd";
    cout << s.longestPalindrome(st) << endl;

}
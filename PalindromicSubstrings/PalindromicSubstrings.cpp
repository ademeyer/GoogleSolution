// PalindromicSubstrings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>
using namespace std;

class Solution
{
public:
    int countSubstrings(string s)
    {
        int result = 0;

        function<void(int, int)> checkForPalindrome = [&](int l, int r)
        {
            while (l >= 0 && r < s.size() && s[l] == s[r])
            {
                ++result;
                l -= 1;
                r += 1;
            }
        };

        for (int i = 0; i < s.size(); ++i)
        {
            checkForPalindrome(i, i);
            checkForPalindrome(i, (i + 1));
        }
        return result;
    }
};

int main()
{
    Solution s;
    string st = "abc";
    cout << s.countSubstrings(st) << endl;

    st = "aaa";
    cout << s.countSubstrings(st) << endl;
}

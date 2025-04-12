// ValidPalindromeII.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Solution
{
public:
    bool validPalindrome(string s)
    {
        int l = 0, r = s.size() - 1;

        auto isPalindrome = [&](int i, int j)
        {
            while (i < j)
            {
                if (s[i] != s[j])
                    return false;
                ++i;
                --j;
            }
            return true;
        };
        while (l < r)
        {
            if (s[l] != s[r])
                return isPalindrome(l + 1, r) || isPalindrome(l, r - 1);
            ++l;
            --r;
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << (s.validPalindrome("aba") ? "True" : "False") << endl;
    cout << (s.validPalindrome("abca") ? "True" : "False") << endl;
    cout << (s.validPalindrome("abc") ? "True" : "False") << endl;
    cout << (s.validPalindrome("deeee") ? "True" : "False") << endl;
    cout << (s.validPalindrome("cbbcc") ? "True" : "False") << endl;
}

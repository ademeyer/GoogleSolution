// LongestSubstringWithoutRepeatingCharacters.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
    Time: O(n)
    Space: O(n)
*/

#include <iostream>
#include <unordered_set>
using namespace std;

class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_set<char> charSet;
        int l = 0;
        int result = 0;

        for (int r = 0; r < s.size(); r++)
        {
            while (charSet.count(s[r])) // if our next char is in our charSet, we need to move left pointer
            {
                charSet.erase(s[l]);
                ++l;
            }
            charSet.insert(s[r]);
            result = max(result, r - l + 1);
        }
        return result;
    }
};

int main()
{
    Solution s;
    cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << s.lengthOfLongestSubstring("bbbbb") << endl;
    cout << s.lengthOfLongestSubstring("pwwkew") << endl;
}

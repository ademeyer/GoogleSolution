// MinimumWindowSubstring.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if(t.empty())
            return "";

        unordered_map<char, int> countT, window;
        for (auto c : t)
        {
            countT[c]++;
        }

        int need = countT.size(), have = 0;
        pair<int, int> res = { -1, -1 };
        int resLen = INT_MAX;
        int l = 0, r = 0;

        for (r = 0; r < s.size(); r++)
        {
            char c = s[r];
            window[c]++;

            if (countT.find(c) != countT.end() && window[c] == countT[c])
            {
                ++have;
            }

            while (have == need)
            {
                if ((r - l + 1) < resLen)
                {
                    res = { l, r };
                    resLen = r - l + 1;
                }

                window[s[l]]--;

                if (countT.find(s[l]) != countT.end() && window[s[l]] < countT[s[l]])
                    --have;
                ++l;
            }
        }

        l = res.first;
        r = res.second;

        if (resLen != INT_MAX) return s.substr(l, (r - l + 1));
        
        return "";
    }
};

int main()
{
    Solution s;
    cout << s.minWindow("ADOBECODEBANC", "ABC") << endl;
    cout << s.minWindow("a", "a") << endl;
    cout << s.minWindow("a", "aa") << endl;
    cout << s.minWindow("abc", "b") << endl;
}

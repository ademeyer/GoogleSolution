// ValidAnagram.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Solution
{
public:
    bool isAnagram(string s, string t)
    {

        /*
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
        */

        if (s.size() != t.size()) return false;
        unordered_map<char, int> cache_s, cache_t;
        for (int i = 0; i < s.size(); i++)
        {
            cache_s[s[i]]++;
            cache_t[t[i]]++;
        }

        for (const auto c : s)
        {
            if (cache_t.find(c) == cache_t.end()) return false;
            if (cache_s[c] != cache_t[c]) return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    string s_1 = "anagram", t_1 = "nagaram";
    cout << (s.isAnagram(s_1, t_1) ? "true" : "false") << endl;

    string s_2 = "rat", t_2 = "car";
    cout << (s.isAnagram(s_2, t_2) ? "true" : "false") << endl;

    string s_3 = "oluwatimileyin", t_3 = "yintileim";
    cout << (s.isAnagram(s_3, t_3) ? "true" : "false") << endl;

}

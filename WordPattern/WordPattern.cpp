// WordPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        string temstr = "";
        unordered_map<char, string> mp;
        unordered_set<string> sc;
        int j = 0;
        for (int i = 0; i <= s.size(); i++)
        {
            if (i < s.size())
            {
                if (s[i] != ' ')
                {
                    temstr += s[i];
                    continue;
                }
            }
            if (!temstr.empty())
            {
                if (j < pattern.size())
                {
                    auto p = pattern[j];
                    if (mp.find(p) != mp.end())
                    {
                        auto m = mp[p];
                        if (m != temstr) return false;
                    }
                    else
                    {
                        if (sc.count(temstr)) return false;
                        mp[p] = temstr;
                        sc.insert(temstr);
                    }
                }
                else return false;

                temstr.clear();
                ++j;
            }
        }
        return j == pattern.size();
    }
};

int main()
{
    Solution sol;
    string pattern = "abba", s = "dog cat cat dog";
    cout << (sol.wordPattern(pattern, s) ? "True" : "False") << endl;

    pattern = "abba"; 
    s = "dog cat cat fish";
    cout << (sol.wordPattern(pattern, s) ? "True" : "False") << endl;

    pattern = "aaaa"; s = "dog cat cat dog";
    cout << (sol.wordPattern(pattern, s) ? "True" : "False") << endl;

    pattern = "abba"; s = "dog dog dog dog";
    cout << (sol.wordPattern(pattern, s) ? "True" : "False") << endl;

    return 0;
}

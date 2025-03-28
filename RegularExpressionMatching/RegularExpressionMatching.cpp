// RegularExpressionMatching.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <functional>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        auto s_size = s.size(), p_size = p.size();

        // Top - Down Memoization DP: by caching
        vector<vector<bool>> cache(s_size + 1, vector<bool>(p_size + 1, false));

        function<bool(int, int)> dfs = [&](int i, int j)
        {
            // if i & j are out of balance
            if (i >= s_size && j >= p_size)
                return true;
            // if j is out of balance
            if(j >= p_size)
                return false;

            // if i is inbound && si == pj or '.'
            auto match = (i < s_size && (s[i] == p[j] || p[j] == '.'));

            if ((j + 1) < p_size && p[j + 1] == '*')
            {
                cache[i][j] = (dfs(i, j + 2) ||             // skip the '*'
                              (match && dfs(i + 1, j)));    // use the '*' if first character matches

                return bool(cache[i][j]);
            }
            // if just two character match: i.e s[i] == p[j]
            if (match)
            {
                cache[i][j] = dfs(i + 1, j + 1);
                return bool(cache[i][j]);
            }
            cache[i][j] = false;
            return false;
        };

        return dfs(0, 0);

    }
};

int main()
{
    Solution sol;
    string s = "aa", p = "a";
    cout << (sol.isMatch(s, p) ? "Equal" : "Not Equal") << endl;

    s = "aa", p = "a*";
    cout << (sol.isMatch(s, p) ? "Equal" : "Not Equal") << endl;

    s = "ab", p = ".*";
    cout << (sol.isMatch(s, p) ? "Equal" : "Not Equal") << endl;
}

// WildcardMatching.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
        vector<vector<bool>> cache(p_size + 1, vector<bool>(s_size + 1, false));

        function<bool(int, int)> dfs = [&](int i, int j)  // p[i], s[j]
        {
            // if i & j are out of balance
            if (i == 0 && j == 0)
                return true;
            // if i is out of balance and j is not
            if (i == 0 && j > 0)
                return false;
            // if j is out of balance and i is not
            if (j == 0 && i > 0)
            {
                for (int k = 1; k <= i; ++k)
                    if (p[k-1] != '*') return false;
                return true;
            }

            if (cache[i][j]) return bool(cache[i][j]);

            // 1 - 1 matching  or ? - 1 matching
            if (p[i-1] == s[j-1] || p[i-1] == '?')
                return bool((cache[i][j] = dfs(i - 1, j - 1)));

            // wildcard matching 
            if (p[i-1] == '*')
                return bool(cache[i][j] = (dfs(i - 1, j) || dfs(i, j - 1)));
            

            //// create tabular cache optimization
            //cache[0][0] = true;
            //for (int j = 1; j <= s_size; ++j)
            //    cache[0][j] = false;

            //for (int i = 1; i <= p_size; ++j)
            //{
            //    int fflag = true;
            //    for (int k = 1; k <= i; ++k)
            //    {
            //        if (p[k - 1] != '*')
            //        {
            //            fflag = false;
            //            break;
            //        }
            //    }
            //    cache[i][0] = fflag;
            //}

            return bool(cache[i][j] = false);
        };

        return dfs(p_size, s_size);

    }
};

int main()
{
    Solution sol;
    string s = "aa", p = "a";
    cout << (sol.isMatch(s, p) ? "Equal" : "Not Equal") << endl;

    s = "aa", p = "*";
    cout << (sol.isMatch(s, p) ? "Equal" : "Not Equal") << endl;

    s = "cb", p = "?a";
    cout << (sol.isMatch(s, p) ? "Equal" : "Not Equal") << endl;

    s = "mississippi", p = "m??*ss*?i*pi";
    cout << (sol.isMatch(s, p) ? "Equal" : "Not Equal") << endl;

    s = "bbbababbabbbbabbbbaabaaabbbbabbbababbbbababaabbbab", p = "a******b*";
    cout << (sol.isMatch(s, p) ? "Equal" : "Not Equal") << endl;

    return 0;
}

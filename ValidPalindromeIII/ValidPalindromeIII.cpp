// ValidPalindromeIII.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
* 
*/
#include <unordered_map>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Solution1
{
public:
    bool isValidPalindrome(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }

        for (int length = 2; length <= n; ++length) {
            for (int i = 0; i <= n - length; ++i) {
                int j = i + length - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = 2 + (length == 2 ? 0 : dp[i + 1][j - 1]);
                }
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        int lpsLength = dp[0][n - 1];
        return (n - lpsLength) <= k;
    }
};

class Solution
{
    struct key
    {
        int i, j, k;
        bool operator==(const key& other) const
        {
            return i == other.i && j == other.j && k == other.k;
        }
    };
    struct key_hash
    {
        size_t operator()(const key& k) const
        {
            size_t h1 = hash<int>{}(k.i);
            size_t h2 = hash<int>{}(k.j);
            size_t h3 = hash<int>{}(k.k);

            return h1 ^ (h2 << 1) ^ (h3 << 2);
        }
    };
public:
    bool isValidPalindrome(string s, int k) 
    {
        auto cmp = [](const key& a, const key& b) -> bool
        {
            if (a.i != b.i) return a.i < b.i;
            if (a.j != b.j) return a.j < b.j;
            return a.k < b.k;
        };

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

        unordered_map<key, bool, key_hash> cache;

        function<bool(int, int, int)> helper = [&](int i, int j, int k)
        {
            if (cache.find({ i,j,k }) != cache.end())
                return cache[{i, j, k}];
            else if (!k)
                cache[{i, j, k}] = isPalindrome(i, j);
            else
            {
                while (i < j)
                {
                    if (s[i] != s[j])
                    {
                        cache[{i, j, k}] = helper(i + 1, j, k - 1) || helper(i, j - 1, k - 1);
                        return cache[{i, j, k}];
                    }
                    ++i;
                    --j;
                }
                cache[{i, j, k}] = true;
            }
            return cache[{i, j, k}];
        };

        return helper(0, s.size() - 1, k);
    }
};

int main()
{
    Solution1 sol;
    string s = "abcdeca";
    int k = 2;
    cout << (sol.isValidPalindrome(s, k) ? "True" : "False") << endl;
    
    s = "aa";
    k = 2;
    cout << (sol.isValidPalindrome(s, k) ? "True" : "False") << endl;

    s = "aa";
    k = 0;
    cout << (sol.isValidPalindrome(s, k) ? "True" : "False") << endl;

    s = "kayak";
    k = 1;
    cout << (sol.isValidPalindrome(s, k) ? "True" : "False") << endl;
 
    s = "kayak";
    k = 0;
    cout << (sol.isValidPalindrome(s, k) ? "True" : "False") << endl;

    s = "rotyator";
    k = 1;
    cout << (sol.isValidPalindrome(s, k) ? "True" : "False") << endl;

    s = "Timileyin";
    k = 3;
    cout << (sol.isValidPalindrome(s, k) ? "True" : "False") << endl;

    s = "Adebayo";
    k = 3;
    cout << (sol.isValidPalindrome(s, k) ? "True" : "False") << endl;

    return 0;
}

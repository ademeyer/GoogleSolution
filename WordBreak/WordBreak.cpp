// WordBreak.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
    Time: O(n^3)
    Space: O(n)
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        unordered_set<string> words;
        
        for (int i = 0; i < wordDict.size(); i++)
            words.insert(wordDict[i]);

        int n = s.size();
        vector<bool> dp((n + 1), false);
        dp[0] = true;

        for (int i = 1; i <= n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (dp[j])
                {
                    string word = s.substr(j, i - j);
                    if (words.find(word) != words.end())
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        return dp[n];
    }
};

int main()
{
    Solution s;
    string st = "leetcode";
    vector<string> wordDict = { "leet","code" };
    cout << (s.wordBreak(st, wordDict) ? "True" : "False") << endl;

    st = "applepenapple";
    wordDict = { "apple","pen" };
    cout << (s.wordBreak(st, wordDict) ? "True" : "False") << endl;

    st = "catsandog";
    wordDict = { "cats","dog","sand","and","cat" };
    cout << (s.wordBreak(st, wordDict) ? "True" : "False") << endl;
}


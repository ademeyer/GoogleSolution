// WordBreakII.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <iostream>
#include <vector>

using namespace std; 

class Solution
{
public:
    vector<string> wordBreak(string s, vector<string>& wordDict)
    {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> memo;

        function<vector<string>(const string&)> backtrack = [&](const string& s) -> vector<string>
        {
            if (memo.find(s) != memo.end())
            {
                return memo[s];
            }
            vector<string> res;
            if (s.empty())
            {
                res.push_back("");
                return res;
            }

            for (int i = 1; i <= s.size(); ++i)
            {
                string word = s.substr(0, i);
                if (wordSet.count(word))
                {
                    vector<string> subsentence = backtrack(s.substr(i));
                    for (const auto& sub : subsentence)
                    {
                        auto space = sub.empty() ? "" : " ";
                        res.push_back(word + space + sub);
                    }
                }
            }
            memo[s] = res;
            return res;
        };

        
        return backtrack(s);
    }
};

int main()
{
}

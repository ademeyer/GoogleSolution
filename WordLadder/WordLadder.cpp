// WordLadder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution 
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        bool found = false;
        for (const auto& w : wordList)
            if (endWord == w) found = true;

        if (!found) return 0;

        unordered_map<string, vector<string>> nei;
        wordList.push_back(beginWord);

        for (const auto& word : wordList)
        {
            for (int i = 0; i < word.size(); ++i)
            {
                auto pattern = word.substr(0, i) + "*" + word.substr(i + 1, word.size());
                nei[pattern].push_back(word);
            }
        }

        unordered_set<string> visited{ beginWord };
        queue<string> q;
        q.push(beginWord);
        auto res = 1;
        while (!q.empty())
        {
            auto n = q.size();
            for (int i = 0; i < n; i++)
            {
                auto word = q.front(); q.pop();
                if (word == endWord)
                    return res;
                for (int j = 0; j < word.size(); ++j)
                {
                    auto pattern = word.substr(0, j) + "*" + word.substr(j + 1, word.size());
                    for (const auto& s : nei[pattern])
                    {
                        if (!visited.count(s))
                        {
                            visited.insert(s);
                            q.push(s);
                        }
                    }
                }
            }
            ++res;
        }
        return 0;
    }
};

int main()
{
    Solution s;
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = { "hot","dot","dog","lot","log","cog" };

    cout << s.ladderLength(beginWord, endWord, wordList) << endl;
    return 0;
}
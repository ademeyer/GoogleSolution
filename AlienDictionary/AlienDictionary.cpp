// AlienDictionary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>

using namespace std;

class Solution
{
public:
    string foreignDictionary(vector<string>& words)
    {
        unordered_map<char, char> adj;

        for (int i = 0; i < words.size() - 1; ++i)
        {
            auto w1 = words[i];
            auto w2 = words[i + 1];
            int minLen = min(w1.size(), w2.size());

            if (w1.size() > w2.size() &&
                w1.substr(minLen) == w2.substr(minLen))
            {
                return "";
            }
            for (int j = 0; j < minLen; ++j)
            {
                if (w1[j] == w2[j])
                {
                    adj[w1[j]] = w2[j];
                    break;
                }
            }
        }
        unordered_map<char, bool> visited;
        string result;

        function<bool(char)> dfs = [&](char c)
        {
            if (visited.find(c) != visited.end())
                return visited[c];
            
            visited[c] = true;
            for (auto nei : adj[c])
            {
                if (dfs[nei])
                    return true;
            }
            visited[c] = false;
        };

        return result;

    }
};

int main() 
{
}

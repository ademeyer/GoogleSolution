// GroupAnagrams.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>> cache; // sorted character as key and list of match as value

        for (auto s : strs)
        {
            //sort each str
            auto key = s;
            sort(key.begin(), key.end());
            // insert s against sorted key
            cache[key].push_back(s);
        }
        vector<vector<string>> result;
        for (const auto ls : cache)
        {
            result.push_back(ls.second);
        }
        return result;
    }
    /*
    * Time = O(n)
    * Space = O(n)
    */
};

int main()
{
    Solution s;

    vector<string> strs = { "eat","tea","tan","ate","nat","bat" };
    auto res = s.groupAnagrams(strs);
    cout << "[";
    for (const auto str : res)
    {
        cout << "[";
        for (const auto s : str)
            cout << s << ",";
        cout << "],";
    }
    cout << "]" << endl;

    vector<string> strs_1 = { "" };
    res = s.groupAnagrams(strs_1);
    cout << "[";
    for (const auto str : res)
    {
        cout << "[";
        for (const auto s : str)
            cout << s << ",";
        cout << "],";
    }
    cout << "]" << endl;

    vector<string> strs_2 = { "a" };
    res = s.groupAnagrams(strs_2);
    cout << "[";
    for (const auto str : res)
    {
        cout << "[";
        for (const auto s : str)
            cout << s << ",";
        cout << "],";
    }
    cout << "]" << endl;
}


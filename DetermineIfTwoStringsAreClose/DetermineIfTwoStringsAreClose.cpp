// DetermineIfTwoStringsAreClose.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution 
{
public:
    bool closeStrings(string word1, string word2) 
    {
        if (word1.size() != word2.size())
            return false;

        vector<int> freq1(26, 0), freq2(26, 0);
        unordered_set<char> set1, set2;

        for (const auto& c : word1)
        {
            freq1[c - 'a']++;
            set1.insert(c);
        }

        for (const auto& c : word2)
        {
            freq2[c - 'a']++;
            set2.insert(c);
        }

        if (set1 != set2)
            return false;

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return freq1 == freq2;
    }
};

int main()
{
    Solution s;
    string word1 = "abc", word2 = "bca";
    cout << (s.closeStrings(word1, word2) ? "True" : "False") << endl;

    word1 = "a", word2 = "aa";
    cout << (s.closeStrings(word1, word2) ? "True" : "False") << endl;

    word1 = "cabbba", word2 = "abbccc";
    cout << (s.closeStrings(word1, word2) ? "True" : "False") << endl;

    return 0;
}

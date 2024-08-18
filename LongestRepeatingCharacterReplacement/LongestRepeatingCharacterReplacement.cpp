// LongestRepeatingCharacterReplacement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
*     Time: O(n)
    Space: O(26)
*/
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
    int MAX(const unordered_map<char, int>& cache)
    {
        int m = 0;
        for (auto c : cache)
        {
            m = max(m, c.second);
        }
        return m;
    }
public:
    int characterReplacement(string s, int k)
    {
        int l = 0, r = 0, result = 0;
        unordered_map<char, int> cache;
        int maxf = 0;
        for (r; r < s.size(); r++)
        {
            cache[s[r]]++;
            maxf = max(maxf, cache[s[r]]);

            while ((r - l + 1) - maxf > k) // or while ((r - l + 1) - MAX(cache) > k)
            {
                cache[s[l]]--;
                ++l;
            }
            result = max(result, (r - l + 1));
        }
        return result;
    }
};

int main()
{
    Solution s;
    cout << s.characterReplacement("ABAB", 2) << endl;
    cout << s.characterReplacement("AABABBA", 1) << endl;

    return 0;
}

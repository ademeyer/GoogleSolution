// MaximumNumberOfVowelsInASubstringOfGivenLength.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int maxVowels(string s, int k)
    {
        const unordered_set<char> vowels = { 'a', 'e', 'i', 'o', 'u' };
        int l = 0, cnt = 0, res = 0;

        for (int r = 0; r < s.size(); ++r)
        {
            cnt += vowels.count(s[r]) ? 1 : 0;
            // check for a valid window
            if (r - l + 1 > k)
            {
                cnt -= vowels.count(s[l]) ? 1 : 0;
                ++l;
            }
            res = max(res, cnt);
        }
       
        return res;
    }
};

int main()
{
    Solution sol;
    string s = "abciiidef"; int k = 3;
    cout << "number of vowel in substr: " << sol.maxVowels(s, k) << endl;

    s = "aeiou"; k = 2;
    cout << "number of vowel in substr: " << sol.maxVowels(s, k) << endl;

    s = "leetcode"; k = 3;
    cout << "number of vowel in substr: " << sol.maxVowels(s, k) << endl;

    return 0;
}

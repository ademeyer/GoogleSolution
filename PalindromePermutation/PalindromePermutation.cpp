// PalindromePermutation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <unordered_map>
#include <iostream>
using namespace std;

class Solution 
{
public:
    bool canPermutePalindrome(string s)
    {
        unordered_map<char, int> wordFreq;
        for (const auto& c : s)
            wordFreq[c]++;

        auto oddCnt = 0;
        for (const auto& [ch, cnt] : wordFreq) // requires C++20
        {
            if (cnt % 2 != 0)
                oddCnt++;
            if (oddCnt > 1)
                return false;
        }
        return true;
    }

};
int main()
{
    Solution s;
    cout << (s.canPermutePalindrome("code") ? "True" : "False") << endl;
    cout << (s.canPermutePalindrome("aab") ? "True" : "False") << endl;
    cout << (s.canPermutePalindrome("carerac") ? "True" : "False") << endl;
    return 0;
}

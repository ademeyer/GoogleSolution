// ValidWordAbbreviation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Solution
{
public: 
    bool validWordAbbreviation(const string& word, const string& abbr)
    {
        int m = word.size(), n = abbr.size();
        int i = 0, j = 0, amt = 0;

        for (; i < m && j < n; ++j)
        {
            // if it's a digit
            if (isdigit(abbr[j]))
            {
                // if we found leading zero
                if (abbr[j] == '0' && amt == 0)
                    return false;
                // add value
                amt = amt * 10 + (abbr[j] - '0');
            }
            // is a char
            else
            {
                // update total length of word
                i += amt;
                amt = 0;

                // we exceeds the word length or mismatch a char
                if (i >= m || word[i] != abbr[j])
                    return false;
                ++i;
            }
        }
        return i + amt == m && j == n;
    }
};
int main()
{
    Solution s;
    string word = "substitution", abbr = "s10n";
    cout << (s.validWordAbbreviation(word, abbr) ? "True" : "False") << endl;
    abbr = "sub4u4";
    cout << (s.validWordAbbreviation(word, abbr) ? "True" : "False") << endl;
    abbr = "su3i1u2on";
    cout << (s.validWordAbbreviation(word, abbr) ? "True" : "False") << endl;
    word = "internationalization", abbr = "i12iz4n";
    cout << (s.validWordAbbreviation(word, abbr) ? "True" : "False") << endl;
    word = "apple", abbr = "a2e";
    cout << (s.validWordAbbreviation(word, abbr) ? "True" : "False") << endl;

    return 0;
}

// ValidPalindrome.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Solution
{
    bool isValid(int ch)
    {
        return ((ch >= int('a') && ch <= int('z')) || 
            (ch >= int('A') && ch <= int('Z')) 
            || (ch >= int('0') && ch <= int('0')));
    }
public:
    bool isPalindrome(string s)
    {
        //if (s.size() > 0 && s.size() <= 2) return true;

        int i = 0, j = s.size()-1;

        while (i < j)
        {
            if (!isValid(s[i]))
            {
                ++i;
                continue;
            }
            if (!isValid(s[j]))
            {
                --j;
                continue;
            }
            
            if (tolower(s[i]) != tolower(s[j])) 
                return false;
            ++i;
            --j;
        }
        return true;
    }
};

int main()
{
    Solution s;
    string s_1 = "A man, a plan, a canal: Panama";
    cout << "s_1 is " << (s.isPalindrome(s_1) ? "" : "Not ") << "Palindrome" << endl;

    string s_2 = "race a car";
    cout << "s_2 is " << (s.isPalindrome(s_2) ? "" : "Not ") << "Palindrome" << endl;

    string s_3 = " ";
    cout << "s_3 is " << (s.isPalindrome(s_3) ? "" : "Not ") << " Palindrome" << endl;

    string s_4 = "a.";
    cout << "s_4 is " << (s.isPalindrome(s_4) ? "" : "Not ") << " Palindrome" << endl;

    string s_5 = "aa";
    cout << "s_5 is " << (s.isPalindrome(s_5) ? "" : "Not ") << " Palindrome" << endl;
}
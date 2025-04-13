// ValidNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Solution 
{
public:
    bool isNumber(string s) 
    {
        int i = 0;
        int n = s.size();

        // omit leading whitespace
        while (i < n && isspace(s[i])) i++;

        // omit optional sign
        if (i < n && (s[i] == '+' || s[i] == '-')) i++;

        bool hasDigits = false;
        bool hasDot = false;
        bool hasExponent = false;

        // Check digits before decimal point or exponent
        while (i < n && isdigit(s[i]))
        {
            hasDigits = true;
            ++i;
        }

        // Check decimal point
        if (i < n && s[i] == '.')
        {
            hasDot = true;
            ++i;
            // Check digits after decimal point or exponent
            while (i < n && isdigit(s[i]))
            {
                hasDigits = true;
                ++i;
            }
        }

        // Check exponent
        if (hasDigits && i < n && (s[i] == 'e' || s[i] == 'E'))
        {
            hasExponent = true;
            ++i;
            // skip optional sign in exponent
            if (i < n && (s[i] == '+' || s[i] == '-')) i++;
            bool exponentHasDigits = false;
            while (i < n && isdigit(s[i]))
            {
                exponentHasDigits = true;
                ++i;
            }
            if (!exponentHasDigits) return false;
        }

        // Skip trailing whitespace
        while (i < n && isspace(s[i])) i++;

        // if we have gone through the entire string 
        // and we have at least some digits.
        return i == n && hasDigits;
    }
};

int main()
{
    return 0;
}

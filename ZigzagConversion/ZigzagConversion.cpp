// ZigzagConversion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Solution 
{
public:
    string convert(string s, int numRows) 
    {   
        if (numRows == 1)
            return s;

        string res = "";

        for (int r = 0; r < numRows; ++r)
        {
            auto increment = 2 * (numRows - 1);
            for (int i = r; i < s.size(); i += increment)
            {
                res += s[i];
                if (r > 0 && r < numRows - 1 && (((i + increment) - (2 * r)) < s.size()))
                {
                    res += s[i + increment - 2 * r];
                }
            }
        }

        return res;

    }
};

int main()
{
    Solution s;
    cout << "output: " << s.convert("PAYPALISHIRING", 3) << endl;
    cout << "output: " << s.convert("PAYPALISHIRING", 4) << endl;
    cout << "output: " << s.convert("A", 1) << endl;

}

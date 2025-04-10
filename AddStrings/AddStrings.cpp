// AddStrings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Solution 
{
public:
    string addStrings(string num1, string num2) 
    {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        string result;

        while (i >= 0 || j >= 0 || carry > 0)
        {
            int digit1 = i >= 0 ? num1[i--] - '0' : 0;
            int digit2 = j >= 0 ? num2[j--] - '0' : 0;
            auto sum = digit1 + digit2 + carry;
            carry = sum / 10;
            result.push_back((sum % 10) + '0');
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    Solution s;
    string num1 = "11", num2 = "123";
    cout << s.addStrings(num1, num2) << endl;

    num1 = "456", num2 = "77";
    cout << s.addStrings(num1, num2) << endl;

    num1 = "0", num2 = "0";
    cout << s.addStrings(num1, num2) << endl;

    return 0;
}

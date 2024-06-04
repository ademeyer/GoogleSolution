// ValidParentheses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            if (ch == '(' || ch == '{' || ch == '[')
            {
                st.push(ch);
            }
            else
            {
                if (st.empty())
                {
                    return false;
                }
                else
                {
                    char top = st.top();
                    if ((ch == ')' && top == '(') ||
                        (ch == '}' && top == '{') ||
                        (ch == ']' && top == '['))
                    {
                        st.pop();
                    }
                    else
                        return false;
                }
            }
        }

        if (st.empty())
            return true;

        return false;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

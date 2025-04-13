// BasicCalculator II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        stack<int> st;
        char op = '+';
        int cur = 0;

        for (int i = 0; i < s.size(); ++i) // -1 + 4 = 
        {
            auto c = s[i];

            if (isdigit(c))
                cur = cur * 10 + (c - '0');
            
            if ((!isspace(c) && !isdigit(c)) || i == s.size() - 1)
            {
                if (op == '+')
                    st.push(cur);
                else if (op == '-')
                    st.push(-cur);
                else if (op == '*')
                {
                    auto v = st.top(); st.pop();
                    st.push(v * cur);
                }
                else if (op == '/')
                {
                    auto v = st.top(); st.pop();
                    st.push(v / cur);
                }
                op = c;
                cur = 0;
            }
        }
        int res = 0;
        while (!st.empty())
        {
            res += st.top(); st.pop();
        }
        return res;
    }
};

int main()
{

}

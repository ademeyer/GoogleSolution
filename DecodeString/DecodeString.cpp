// DecodeString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    string decodeString(string s)
    {
        stack<char> st;
        for (const auto& i : s)
        {
            if (i != ']')
                st.push(i);
            else
            {
                string sstr = "";
                while (!st.empty() && st.top() != '[')
                {
                    sstr = st.top() + sstr;
                    st.pop();
                }
                st.pop(); // remove ']'

                string k = "";
                while (!st.empty() && isdigit(st.top()))
                {
                    k = st.top() + k;
                    st.pop();
                }
                auto str = sstr;
                for (int p = 1; p < stoi(k); ++p)
                    str += sstr;
                for (const auto& ss : str)
                    st.push(ss);
            }
        }
        string res = "";
        while (!st.empty())
        {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};

int main()
{
    Solution sol;
    string s = "3[a]2[bc]";
    cout << sol.decodeString(s) << endl;

    s = "3[a2[c]]";
    cout << sol.decodeString(s) << endl;

    s = "2[abc]3[cd]ef";
    cout << sol.decodeString(s) << endl;

}

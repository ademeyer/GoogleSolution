// SimplifyPath.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        int n = path.size();
        string tempstr = "";
        stack<string> st;
        for (int i = 0; i <= n; i++)
        {
            if (i < n)
            {
                if (path[i] != '/')
                {
                    tempstr += path[i];
                    continue;
                }
            }
            if (!tempstr.empty())
            {
                // check if tempstr == "..", we pop if true
                if (tempstr == "..")
                {
                    if(!st.empty())
                        st.pop();
                }
                else if (tempstr != ".")
                {
                    st.push(tempstr);
                }
            }
            tempstr.clear();
        }
        string res = "";
        while(!st.empty())
        {
            auto tmp = res;
            res = "/";
            res += st.top();
            res += tmp;
            st.pop();
        }
        return res.empty() ? "/" : res;
    }
};

int main()
{
    Solution s;
    string path = "/home/";
    cout << "outcome: " << s.simplifyPath(path) << endl;

    path = "/home//foo/";
    cout << "outcome: " << s.simplifyPath(path) << endl;

    path = "/home/user/Documents/../Pictures";
    cout << "outcome: " << s.simplifyPath(path) << endl;

    path = "/../";
    cout << "outcome: " << s.simplifyPath(path) << endl;

    path = "/.../a/../b/c/../d/./";
    cout << "outcome: " << s.simplifyPath(path) << endl;

    return 0;
}
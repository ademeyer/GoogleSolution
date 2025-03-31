// MinimumRemoveToMakeValidParentheses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Solution 
{
public:
    string minRemoveToMakeValid(string s) 
    {
        string result = "";
        int cnt = 0;
        // ())()(((
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
                ++cnt;
            else if (s[i] == ')')
                --cnt;
            
            if (s[i] == ')' && cnt < 0)
            {
                cnt = 0;
                continue;
            }

            result.push_back(s[i]);
        }

        // while we have excess '(' starting from the end
        if (cnt != 0)
        {
           
            s = result;
            result.clear();
            for (int i = s.size() - 1; i >= 0; --i)
            {
                if (s[i] == '(' && cnt > 0)
                    --cnt;
                else
                    result.push_back(s[i]);
            }
            reverse(result.begin(), result.end());
        }
        return result;
    }
};

int main()
{
    Solution sol;
    string s = "lee(t(c)o)de)";
    cout << "outcome: " << sol.minRemoveToMakeValid(s) << endl;

    s = "a)b(c)d";
    cout << "outcome: " << sol.minRemoveToMakeValid(s) << endl;

    s = "))((";
    cout << "outcome: " << sol.minRemoveToMakeValid(s) << endl;

    s = "())()(((";
    cout << "outcome: " << sol.minRemoveToMakeValid(s) << endl;
}


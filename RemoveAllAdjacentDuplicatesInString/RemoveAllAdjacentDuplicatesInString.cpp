// RemoveAllAdjacentDuplicatesInString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution 
{
public:
    string removeDuplicates(string s) 
    {
        stack<pair<char, int>>st;
        for (const auto& c : s)
        {
            if (!st.empty() && st.top().first == c)
                st.top().second += 1;
            else
                st.push({ c,1 });
            if (st.top().second == 2)
                st.pop();
        }

        string res = "";
        while (!st.empty())
        {
            res = st.top().first + res;
            st.pop();
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.removeDuplicates("abbaca") << endl;
    cout << s.removeDuplicates("azxxzy") << endl;
}

// GenerateParentheses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>
#include <vector>
#include <stack>
using namespace std;

class Solution 
{
public:
    vector<string> generateParenthesis(int n) 
    {
        // add open parenthesis if open < n
        // only add a closing parenthesis if closed < open
        // valid IF open == closed == n

        string st;
        vector<string> result;

        function<void(int, int)> backtracker = [&](int open_n, int close_n)
        {
            // handle valid condition
            if (close_n == open_n && open_n == n)
            {
                result.push_back(st);
                return;
            }

            if (open_n < n)
            {
                st += '(';
                backtracker(open_n + 1, close_n);
                st.pop_back();
            }

            if (close_n < open_n)
            {
                st += ')';
                backtracker(open_n, close_n+1);
                st.pop_back();
            }
            return;
        };

        backtracker(0, 0);
        return result;
    }
};

void print(const vector<string>& r)
{
    cout << "[";
    for (const auto& i : r)
    {
        cout << i << ",";
    }
    cout << "]\n";
}

int main()
{
    Solution s;
    auto r = s.generateParenthesis(3);
    print(r);
    
}

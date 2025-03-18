// EvaluateReversePolishNotation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <functional>

using namespace std;

typedef function<int(int, int)> operate;

class Solution
{
    unordered_map < string, operate > math_operation =
    {
        {"+", [](int a, int b) { return a + b; } },
        {"*", [](int a, int b) { return a * b; } },
        {"-", [](int a, int b) { return b - a; } },
        {"/", [](int a, int b) { return b / a; } },
    };
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> st;
        for (const auto& t : tokens)
        {
            if(math_operation.find(t) != math_operation.end())
            //if (t == "+" || t == "-" || t == "/" || t == "*")
            {
                if (st.size() >= 2)
                {
                    operate op = math_operation[t];
                    auto a = st.top(); st.pop();
                    auto b = st.top(); st.pop();

                    int res = op(a, b);
                    st.push(res);
                }
            }
            else
            {
                st.push(stoi(t));
            }
        }
        return st.empty() ? 0 : st.top();
    }
};

int main()
{
    Solution s;
    vector<string> tokens = { "2", "1", "+", "3", "*" };
    cout << "value: " << s.evalRPN(tokens) << endl;

    tokens = { "4","13","5","/","+" };
    cout << "value: " << s.evalRPN(tokens) << endl;

    tokens = { "10","6","9","3","+","-11","*","/","*","17","+","5","+" };
    cout << "value: " << s.evalRPN(tokens) << endl;
}
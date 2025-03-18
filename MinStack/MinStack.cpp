// MinStack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
    stack<int> st, minSt;
public:
    MinStack()
    {

    }

    void push(int val)
    {
        st.push(val);
        if (!minSt.empty())
        {
            val = min(val, minSt.top());
        }
        minSt.push(val);
    }

    void pop()
    {
        st.pop();
        minSt.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return minSt.top();
    }
};

int main()
{

}
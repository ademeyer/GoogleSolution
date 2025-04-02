// ImplementStackUsingQueues.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>

using namespace std;

class MyStack 
{
    queue<int> q;
public:
    MyStack() 
    {

    }

    void push(int x) 
    {
        q.push(x);
    }

    int pop() 
    {
        int n = q.size();
        int ret = -1;
        while (n > 0)
        {
            ret = q.front(); q.pop();
            --n;
            if (n != 0) q.push(ret);
        }
        return ret;
    }

    int top() 
    {
        int n = q.size();
        int ret = -1;
        while (n > 0)
        {
            ret = q.front(); q.pop();
            --n;
            q.push(ret);
        }
        return ret;
    }

    bool empty() 
    {
        return q.empty();
    }
};

int main()
{
    MyStack st;
    st.push(2);
    cout << st.top() << endl;
    cout << st.pop() << endl;
    cout << st.top() << endl;
    st.push(2);
    st.push(3);
    st.push(1);
    cout << st.top() << endl; // 1
    cout << st.pop() << endl; // 1
    cout << st.top() << endl; // 3

}


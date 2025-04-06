// AsteroidCollision.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int>& asteroids)
    {
        stack<int>st;
        for (auto& a : asteroids)
        {
            while (!st.empty() && a < 0 && st.top() > 0)
            {
                auto diff = a + st.top();
                // if incoming asteroid wins
                if (diff < 0)
                    st.pop();
                // if stack asteroid wins
                else if (diff > 0)
                    a = 0;
                else
                {
                    a = 0;
                    st.pop();
                }
            }
            if (a != 0)
                st.push(a);
        }
        auto n = st.size();
        vector<int> res(n);
        int i = n - 1;
        while (!st.empty())
        {
            auto& p = res[i--];
            p = st.top(); st.pop();
        }
        return res;
    }
};

void Print(const vector<int>& res)
{
    cout << "[";
    for (const auto& r : res)
        cout << r << ",";
    cout << "]\n";
}
int main()
{
    Solution s;
    vector<int> asteroids = { 5,10,-5 };
    auto p = s.asteroidCollision(asteroids);
    Print(p);

    asteroids = { 8,-8 };
    p = s.asteroidCollision(asteroids);
    Print(p);

    asteroids = { 10,2,-5 };
    p = s.asteroidCollision(asteroids);
    Print(p);

    return 0;
}


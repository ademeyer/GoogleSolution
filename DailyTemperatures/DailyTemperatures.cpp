// DailyTemperatures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        stack<pair<int, int>> st; // temperature, index
        int n = temperatures.size();
        vector<int> output(n, 0);

        for (int i = 0; i < n; i++)
        {
            auto t = temperatures[i];
            while (!st.empty() && t > st.top().first)
            {
                auto ts = st.top(); st.pop();
                auto days = i - ts.second;
                output[ts.second] = days;
            }
            st.push({ t, i }); // add temp, index
        }
        return output;
    }
};

void print(const vector<int>& temperatures)
{
    cout << "[";
    for (const auto i : temperatures)
        cout << i << ",";
    cout << "]\n";
}

int main()
{
    Solution s;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    auto r = s.dailyTemperatures(temperatures);
    print(r);

    temperatures = { 30,40,50,60 };
    r = s.dailyTemperatures(temperatures);
    print(r);

    temperatures = { 30,60,90 };
    r = s.dailyTemperatures(temperatures);
    print(r);
}

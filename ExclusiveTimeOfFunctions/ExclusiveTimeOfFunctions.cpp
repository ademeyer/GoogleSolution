// ExclusiveTimeOfFunctions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution 
{
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) 
    {
        vector<int> exclusiveTimes(n, 0); // time, id
        stack<int> st;
        int prev_time = 0;
        
        for (const auto& log : logs)
        {
            // extract logs || parse logs
            auto firstColon = log.find(':');
            auto secondColon = log.find(':', firstColon + 1);

            auto id = stoi(log.substr(0, firstColon)); // parse the id
            auto action = log.substr(firstColon + 1, secondColon - firstColon - 1); // parse the action
            auto time = stoi(log.substr(secondColon + 1)); // parse the time

            // Check what action the function call is on
            if (action == "start")
            {
                if (!st.empty())
                {
                    size_t index = st.top();
                    exclusiveTimes[index] += time - prev_time;
                }
                st.push(id);
                prev_time = time;
            }
            else // action is end
            {
                exclusiveTimes[st.top()] += time - prev_time + 1;
                st.pop(); 
                prev_time = time + 1;
            }
        }

        return exclusiveTimes;
    }
};

void Print(const vector<int>& time)
{
    cout << "[";
    for (const auto& t : time)
        cout << t << ",";
    cout << "]\n";
}

int main()
{
    Solution s;
    int n = 2;
    vector<string> logs = { "0:start:0","1:start:2","1:end:5","0:end:6" };
    auto res = s.exclusiveTime(n, logs);
    Print(res);

    n = 1;
    logs = { "0:start:0","0:start:2","0:end:5","0:start:6","0:end:6","0:end:7" };
    res = s.exclusiveTime(n, logs);
    Print(res);


    return 0;
}

// GasStation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        if (gas.size() != cost.size())
            return -1;
        if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0))
            return -1;
        int result = 0;
        int total = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            total += (gas[i] - cost[i]);

            if (total < 0)
            {
                total = 0;
                result = i + 1;
            }
        }
        return result;
    }
};



int main()
{
}


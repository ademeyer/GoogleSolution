// SubarraySumEqualsK.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int res = 0;
        int curSum = 0;
        unordered_map<int,int> prefixSum{ {0,1} };
        
        for (const auto& n : nums)
        {
            curSum += n;
            auto diff = curSum - k;
            if (prefixSum.find(diff) != prefixSum.end())
                res += prefixSum[diff];
            prefixSum[curSum]++;
        }
        return res;
    }
};

int main()
{
}

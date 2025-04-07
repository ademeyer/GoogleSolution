// MaximumSubsequenceScore.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution 
{
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        using LL = long long;
        vector<pair<int, int>> pairs;
        for (int i = 0; i < nums1.size(); ++i)
            pairs.emplace_back(nums2[i], nums1[i]);

        sort(pairs.rbegin(), pairs.rend());

        priority_queue<int, vector<int>, greater<int>> minHeap;

        LL sum = 0;
        LL res = 0;

        for (const auto& [num2, num1] : pairs)
        {
            if (minHeap.size() < k) 
            {
                minHeap.push(num1);
                sum += num1;
            }
            else
            {
                if (num1 > minHeap.top()) // backtracking here
                {
                    sum -= minHeap.top();
                    minHeap.pop();
                    minHeap.push(num1);
                    sum += num1;
                }
            }

            if (minHeap.size() == k)
                res = max(res, sum * num2);
        }
        return res;
    }
};

int main()
{
}

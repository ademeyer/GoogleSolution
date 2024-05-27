// TopKFrequentElements.cpp : This file contains the 'main' function. Program execution begins and ends there.
// BucketSort

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> count;
        vector<vector<int>> freq(n + 1);
        // elist 1 - n in freq
        for (const auto num : nums)
        {
            count[num]++;
        }
        for (const auto c : count)
        {
            freq[c.second].push_back(c.first);
        }
        vector<int> result;
        for (int i = n; (i >= 0 && result.size() < k); i--)
        {
            for (auto num : freq[i])
            {
                if (!result.empty())
                {
                    if (result.back() == num || result.size() >= k) continue;
                }                
                result.push_back(num);
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums_1 = { 1,1,1,2,2,3 };
    int k_1 = 2;
    auto res = s.topKFrequent(nums_1, k_1);
    for (auto t : res)
        cout << t << ",";
    cout << endl;

    vector<int> nums_2 = { 1 };
    int k_2 = 1;
    res = s.topKFrequent(nums_2, k_2);
    for (auto t : res)
        cout << t << ",";
    cout << endl;

    vector<int> nums_3 = { 1,1,1,2,2,2,3,3,3 };
    int k_3 = 3;
    res = s.topKFrequent(nums_3, k_3);
    for (auto t : res)
        cout << t << ",";
    cout << endl;

    vector<int> nums_4 = { 3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6 };
    int k_4 = 10;
    res = s.topKFrequent(nums_4, k_4);
    for (auto t : res)
        cout << t << ",";
    cout << endl;
}


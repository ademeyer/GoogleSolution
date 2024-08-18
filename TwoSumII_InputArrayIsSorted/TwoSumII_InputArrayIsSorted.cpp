// TwoSumII_InputArrayIsSorted.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> tracker;
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (tracker.find(complement) != tracker.end())
            {
                return { tracker[complement] + 1, i + 1 };
            }
            tracker[nums[i]] = i;
        }
        return { -1, -1 };
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

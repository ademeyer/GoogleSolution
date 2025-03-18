// RemoveElement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int n = 0;
        unordered_map<int, int> mp;
        for (int k = 0; k < nums.size(); k++)
        {
            mp[nums[k]]++;
        }
        for (auto& m : mp)
        {
            if (m.first != val)
            {
                for (int i = 0; i < m.second; i++)
                {
                    nums[n++] = m.first;
                }
            }
        }
        return n;
    }
};

void printVector(vector<int>& n)
{
    cout << "[";
    for (auto& i : n)
        cout << i << ", ";
    cout << "]" << endl;
}


int main()
{
    Solution s;
    vector<int>nums = { 0, 1, 2, 2, 3, 0, 4, 2 }; int val = 2;
    cout << "i: " << s.removeElement(nums, val) << endl;
    printVector(nums);
}


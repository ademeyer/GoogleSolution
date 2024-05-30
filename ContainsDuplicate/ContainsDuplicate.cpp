// ContainsDuplicate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        unordered_map<int, int> cache;

        for (const auto n : nums)
        {
            if (cache.find(n) != cache.end()) // meaning there is a duplicate
            {
                return true;
            }
            cache[n]++;
        }
        return false;
    }

    /*
    Time: O(n)
    Space: O(n)
    */
};

int main()
{
    Solution s;
    vector<int>nums_1 = { 1,2,3,1 };
    cout << (s.containsDuplicate(nums_1) ? "true" : "false") << endl;

    vector<int>nums_2 = { 1,2,3,4 };
    cout << (s.containsDuplicate(nums_2) ? "true" : "false") << endl;

    vector<int>nums_3 = { 1,1,1,3,3,4,3,2,4,2 };
    cout << (s.containsDuplicate(nums_3) ? "true" : "false") << endl;
}

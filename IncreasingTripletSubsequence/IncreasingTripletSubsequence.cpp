// IncreasingTripletSubsequence.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums)  // i < j < k == nums[i] < nums[j] < nums[k]
    {
        if (nums.size() < 3) return false;
        int first = INT_MAX; // nums[j]
        int second = INT_MAX; // nums[k]
        for (const auto& n : nums)
        {
            if (n <= first)
                first = n;
            else if (n <= second)
                second = n;
            else
                return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1, 2, 3, 4, 5 };
    cout << (s.increasingTriplet(nums) ? "True" : "False") << endl;

    nums = { 5,4,3,2,1 };
    cout << (s.increasingTriplet(nums) ? "True" : "False") << endl;

    nums = { 2,1,5,0,4,6 };
    cout << (s.increasingTriplet(nums) ? "True" : "False") << endl;

    return 0;
}

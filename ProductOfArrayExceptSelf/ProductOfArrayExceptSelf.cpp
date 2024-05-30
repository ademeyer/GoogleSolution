// ProductOfArrayExceptSelf.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int prefix = 1;
        vector<int>result(nums.size(), 1);

        for (int i = 0; i < nums.size(); i++)
        {
            result[i] = prefix;
            prefix *= nums[i];
        }
        prefix = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            //int temp = result[i];
            result[i] *= prefix;
            prefix *= nums[i];
        }

        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums_1 = { 1,2,3,4 };
    auto res = s.productExceptSelf(nums_1);
    cout << "[";
    for (auto i : res)
        cout << i << ",";
    cout << "]" << endl;

    vector<int> nums_2 = { -1,1,0,-3,3 };
    res = s.productExceptSelf(nums_2);
    cout << "[";
    for (auto i : res)
        cout << i << ",";
    cout << "]" << endl;

}

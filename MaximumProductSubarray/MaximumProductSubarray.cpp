// MaximumProductSubarray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
using ul = long long int;
class Solution
{
public:
    int maxProduct(vector<int>& nums)
    {
        ul result = INT_MIN; 
        for (ul i : nums)
            result = max(result, i);

        ul curMin = 1;
        ul curMax = 1;

        for (ul n : nums)
        {
            if (n == 0)
            {
                curMax = 1;
                curMin = 1;
                continue;
            }
            ul temp = curMax * n;
            curMax = max(max(n * curMax, n * curMin), n); 
            curMin = min(min(temp, n * curMin), n); 

            result = max(result, curMax); 
        }
        return (int)result;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 2,3,-2,4 };
    cout << s.maxProduct(nums) << endl;

    nums = { -2,0,-1 };
    cout << s.maxProduct(nums) << endl;

    nums = { 0,10,10,10,10,10,10,10,10,10,-10,10,10,10,10,10,10,10,10,10,0 };
    cout << s.maxProduct(nums) << endl;
}

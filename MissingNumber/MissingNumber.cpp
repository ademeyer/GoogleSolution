// MissingNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int missingNumber(vector<int>& nums)
    {
        int res = nums.size();
        
        for (int i = 0; i < nums.size(); ++i)
            res += (i - nums[i]);
        return res;  
    }
};

int main()
{
}
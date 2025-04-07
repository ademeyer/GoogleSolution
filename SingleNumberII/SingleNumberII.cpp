// SingleNumberII.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

/***
* 1001
* 1101
* 1110
* ----
* 
*/
class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            int sum = 0;
            for (int num : nums) {
                sum += (num >> i) & 1;
            }
            if (sum % 3) {
                result |= (1 << i);
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 2,2,3,2 };
    cout << s.singleNumber(nums) <<  endl;
}

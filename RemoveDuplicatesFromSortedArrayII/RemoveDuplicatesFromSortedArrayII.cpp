// RemoveDuplicatesFromSortedArrayII.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        const int mark = INT16_MAX;
        int preVal = mark;
        int freq = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != preVal) // get unique cpy
            {
                preVal = nums[i];
                freq = 1;
            }
            else if (nums[i] == preVal)
            {
                freq++;
                if (freq > 2)
                {
                    nums[i] = mark;
                }
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == mark)
            {
                nums.erase(nums.begin() + i);
                i--;
            }
        }
        return nums.size();
    }
};

void printVector(vector<int>& n)
{
    cout << "[ ";
    for (auto& i : n)
        cout << i << ", ";
    cout << "]" << endl;
}

int main()
{
    Solution s;
    vector<int>nums = { 1,1,1,2,2,3 };
    cout << "size: " << s.removeDuplicates(nums) << endl;
    printVector(nums);

    nums = vector<int>{ 0,0,1,1,1,1,2,3,3 };
    cout << "size: " << s.removeDuplicates(nums) << endl;
    printVector(nums);
}


// NextPermutation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    void nextPermutation(vector<int>& nums) 
    {
        auto swap = [&](int i, int j) 
        {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        };
        auto reverse = [&](int start) 
        {
            int j = nums.size() - 1;
            while (start < j)
            {
                swap(start, j);
                ++start;
                --j;
            }
        };
        
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
            --i;

        if (i >= 0)
        {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j])
                --j;
            swap(i, j);
        }
        reverse(i + 1);
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

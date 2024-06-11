// JumpGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        int goal = nums.size() - 1;

        for (int i = nums.size() - 1; i >= 0; --i)
        {
            if (i + nums[i] >= goal)
                goal = i;
        }
        return (goal == 0);
    }
};

int main()
{
}

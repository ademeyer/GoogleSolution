// JumpGameII.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;


class Solution 
{
public:
    int jump(vector<int>& nums) 
    {
        int res = 0;
        int l = 0, r = 0;
        while (r < nums.size() - 1)
        {
            int farthest = 0;
            for (int i = l; i < r + 1; i++)
            {
                farthest = max(farthest, i + nums[i]);
            }
            l = r + 1;
            r = farthest;
            res++;
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums{ 2, 3, 1, 1, 4 };
    cout << s.jump(nums) << endl;

    nums = vector<int>{ 2,3,0,1,4 };
    cout << s.jump(nums) << endl;
}

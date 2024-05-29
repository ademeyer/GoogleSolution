// ContainerWithMostWater.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        int l = 0, r = height.size()-1; 
        int maxProduct = 0;
        while (l < r)
        {
            maxProduct = max(maxProduct, (min(height[r], height[l]) * (r-l)));
            if (height[l] <= height[r])
                ++l;
            else
                --r;
        }
        return maxProduct;
    }
};

int main()
{
    Solution s;
    vector<int> height = { 1,8,6,2,5,4,8,3,7 };
    cout << "Max Area = " << s.maxArea(height) << endl;

    height = { 1,1 };
    cout << "Max Area = " << s.maxArea(height) << endl;
}

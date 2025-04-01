// KthLargestElementInAnArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int> q;
        for (const auto& n : nums)
            q.push(n);
        int n = k - 1;
        while (n > 0)
        {
            q.pop();
            --n;
        }

        return q.top();
    }
};

int main()
{
    Solution s;
    vector<int>nums{ 3, 2, 1, 5, 6, 4 };
    int k = 2;
    cout << "kth: " << s.findKthLargest(nums, k) << endl;

    nums = { 3,2,3,1,2,4,5,5,6 };
    k = 4;
    cout << "kth: " << s.findKthLargest(nums, k) << endl;
}
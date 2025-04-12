// SlidingWindowMaximum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution 
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        vector<int> result(nums.size() - k + 1);
        deque<int> q;
        int l = 0;
        int r = 0;
        while (r < nums.size())
        {
            // pop smaller values from q
            while (!q.empty() && nums[q.back()] < nums[r])
                q.pop_back();

            q.push_back(r);

            // move left pointer in the window if necessary
            if (l > q.front())
                q.pop_front();

            if ((r + 1) >= k)
                result[l++] = nums[q.front()];

            ++r;
        }
        return result;
    }
};

void Print(const vector<int>& vec)
{
    cout << "[";
    for (const auto& v : vec)
        cout << v << ",";
    cout << "]\n";
}

int main()
{
    Solution s;
    vector<int> nums = { 1,3,-1,-3,5,3,6,7 };
    int k = 3;
    auto r = s.maxSlidingWindow(nums, k);
    Print(r);

    nums = { 1 };
    k = 1;
    r = s.maxSlidingWindow(nums, k);
    Print(r);

    nums = { 1,-1 };
    k = 1;
    r = s.maxSlidingWindow(nums, k);
    Print(r);

    nums = { 7,2,4 };
    k = 2;
    r = s.maxSlidingWindow(nums, k);
    Print(r);

    return 0;
}


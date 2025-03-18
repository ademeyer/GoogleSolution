// MergeSortedArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int s = m + n - 1;
        m--;
        n--;
        // base conditions
        if (m < 0 && n >= 0)
        {
            for (int k = 0; k <= n; k++)
                nums1[k] = nums2[k];
        }
        while (m >= 0 && n >= 0)
        {
            if (nums2[n] >= nums1[m])
            {
                nums1[s] = nums2[n];
                n--;
            }
            else
            {
                nums1[s] = nums1[m];
                m--;
            }
            s--;
        }
        // edge conditions
        for (n; n >= 0; n--)
            nums1[s--] = nums2[n];
    }
};

void printVector(vector<int>& n)
{
    cout << "[";
    for (auto& i : n)
        cout << i << ", ";
    cout << "]" << endl;
}

int main()
{
    Solution s;
    vector<int> nums1{ 1, 2, 3, 0, 0, 0 }; int m = 3;
    vector<int> nums2{ 2, 5, 6 }; int n = 3;
    s.merge(nums1, m, nums2, n);
    printVector(nums1);

    nums1 = vector<int>{ 1 }; m = 1;
    nums2 = vector<int>{}; n = 0;
    s.merge(nums1, m, nums2, n);
    printVector(nums1);

    nums1 = vector<int>{ 0 }; m = 0;
    nums2 = vector<int>{ 1 }; n = 1;
    s.merge(nums1, m, nums2, n);
    printVector(nums1);

    nums1 = vector<int>{ 2, 0 }; m = 1;
    nums2 = vector<int>{ 1 }; n = 1;
    s.merge(nums1, m, nums2, n);
    printVector(nums1);
}


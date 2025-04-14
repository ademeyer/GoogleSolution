// MedianOfTwoSortedArrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        auto total = nums1.size() + nums2.size();
        auto half = total / 2;

        vector<int> A = nums1, B = nums2;

        if (B.size() < A.size()) // if nums2 is shorter
        {
            A = nums2;
            B = nums1;
        }

        int l = 0, r = A.size() - 1;

        while (true)
        {
            auto i = (l + r) / 2; // A midpoint
            auto j = half - i - 2; // B midpoint

            // padding array that goes out of band
            auto aLeft = i >= 0 ? A[i] : -LLONG_MAX;
            auto aRight = i + 1 < A.size() ? A[i + 1] : LLONG_MAX;
            auto bLeft = j >= 0 ? B[i] : -LLONG_MAX;
            auto bRight = j + 1 < B.size() ? B[j + 1] : LLONG_MAX;

            // if we got median
            if (aLeft <= bRight && bLeft <= aRight)
            {
                // odd length
                if (total % 2)
                    return min(aRight, bRight);
                // even length
                return (max(aLeft, bLeft) + min(aRight, bRight)) / 2.0;
            }
            else if (aLeft > bRight)
                r = i - 1;
            else
                l = i + 1;
        }
    }
};

int main()
{
}

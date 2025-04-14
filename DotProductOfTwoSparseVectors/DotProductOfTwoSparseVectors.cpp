// DotProductOfTwoSparseVectors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class SparseVector
{
public:
    vector<pair<int,int>> nums; // index, value
    SparseVector(const vector<int>& n)
    {
        for (int i = 0; i < n.size(); ++i)
            nums.push_back({ i, n[i] });
    }

    int dotProduct(const SparseVector& other)
    {
        auto result = 0;
        auto i = 0;
        auto j = 0;
        while (i < nums.size() && j < other.nums.size())
        {
            auto [i_idx, i_num] = nums[i];
            auto [j_idx, j_num] = other.nums[i];

            if (i_idx == j_idx)
            {
                result += (i_num * j_num);
                ++i;
                ++j;
            }
            else if (i_idx > j_idx)
                ++j;
            else
                ++i;
        }
        return result;
    }
};

int main()
{
    {
        SparseVector v1({ 1, 0, 0, 2, 3 });
        SparseVector v2({ 0, 3, 0, 4, 0 });
        cout << v1.dotProduct(v2) << endl;
    }

    {
        SparseVector v1({ 0, 1, 0, 0, 0 });
        SparseVector v2({ 0, 0, 0, 0, 2 });
        cout << v1.dotProduct(v2) << endl;
    }
    return 0;
}

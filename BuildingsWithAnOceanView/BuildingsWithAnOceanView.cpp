// BuildingsWithAnOceanView.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findBuidings(vector<int>& A)
    {
        int n = A.size();
        vector<int> result = { n - 1 };
        for (int i = n - 2; i >= 0; --i)
        {
            if (A[i] > A[result.back()])
                result.push_back(i);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

void Print(const vector<int>& vec)
{
    cout << '[';
    for (const auto& v : vec)
        cout << v << ",";
    cout << "]\n";
}

int main()
{
    Solution s;
    vector<int> A = { 4,2,3,1 };
    auto r = s.findBuidings(A);
    Print(r);

    A = { 4,3,2,1 };
    r = s.findBuidings(A);
    Print(r);

    A = { 1,3,2,4 };
    r = s.findBuidings(A);
    Print(r);

    A = { 2,2,2,2 };
    r = s.findBuidings(A);
    Print(r);

    return 0;
}
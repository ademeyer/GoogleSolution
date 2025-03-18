// HIndex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int hIndex(vector<int>& citations)
    {
        int h = 0;
        sort(citations.begin(), citations.end(), greater<int>());

        for (int i = 0; i < citations.size(); i++)
        {
            if (citations[i] >= i + 1)
            {
                h++;
            }
        }
        return h;
    }
};
// [6,5,3,1,0]
int main()
{
    Solution s;
    vector<int> citations{3, 0, 6, 1, 5};
    cout << "h-index = " << s.hIndex(citations) << endl;
    citations = vector<int>{ 1, 3, 1 };
    cout << "h-index = " << s.hIndex(citations) << endl;
}
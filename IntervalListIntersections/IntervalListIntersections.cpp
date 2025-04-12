// IntervalListIntersections.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) 
    {
        int i = 0, j = 0;
        int n = firstList.size();
        int m = secondList.size();
        vector<vector<int>>result;

        while (i < n && j < m)
        {
            int start = max(firstList[i][0], secondList[j][0]);
            int end = min(firstList[i][1], secondList[j][1]);

            if (start <= end)
                result.push_back({start, end});
            
            if (firstList[i][1] < secondList[j][1])
                ++i;
            else
                ++j;
        }
        return result;
    }
};

int main()
{

}

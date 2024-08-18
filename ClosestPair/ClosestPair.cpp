// ClosestPair.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Custom comparator to sort pairs based on their values
bool compareValues(const pair<int, int>& a, const pair<int, int>& b) 
{
    return a.second < b.second;
}

vector<pair<int, int>> findClosestPairs(vector<pair<int, int>>& arr1, vector<pair<int, int>>& arr2, int target) 
{
    // Sort both arrays based on values
    sort(arr1.begin(), arr1.end(), compareValues);
    sort(arr2.begin(), arr2.end(), compareValues);

    int closestSum = INT_MAX;
    pair<int, int> closestPair;

    int ptr1 = 0, ptr2 = arr2.size() - 1;

    while (ptr1 < arr1.size() && ptr2 >= 0) 
    {
        int sum = arr1[ptr1].second + arr2[ptr2].second;
        if (sum < target) {
            if (target - sum < closestSum) 
            {
                closestSum = target - sum;
                closestPair = { arr1[ptr1].first, arr2[ptr2].first };
            }
            ptr1++;
        }
        else {
            ptr2--;
        }
    }

    return { closestPair };
}

int main() {
    vector<pair<int, int>> arr1 = { {1, 2000}, {2, 3000}, {3, 4000} };
    vector<pair<int, int>> arr2 = { {1, 5000}, {2, 3000} };
    int target = 5000;

    vector<pair<int, int>> result = findClosestPairs(arr1, arr2, target);

    cout << "{ {" << result[0].first << ", " << result[0].second << "} }" << endl;

    return 0;
}
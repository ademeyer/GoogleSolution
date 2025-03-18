// InsertionSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>

using namespace std;

// Definition for a Pair
 class Pair {
 public:
     int key;
     string value;

     Pair(int key, string value) : key(key), value(value) {}
 };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) 
    {
        int n = pairs.size();
        vector<vector<Pair>> res;

        for (int i = 0; i < n; i++)
        {
            int j = i - 1;

            while (j >= 0 && pairs[j + 1].key < pairs[j].key)
            {
                swap(pairs[j + 1], pairs[j]);
                j--;
            }
            res.push_back(pairs);
        }

        return res;
    }
};

void printPairs(const vector<vector<Pair>>& pairs)
{
    cout << "{\n";
    for (auto pair : pairs)
    {
        cout << "[";
        for(auto i : pair)
            cout << "(" << i.key << ',' << i.value << "), ";
        cout << "]\n";
    }
    cout << "}\n";
}
int main()
{
    Solution s;
    vector<Pair> pairs1 = { Pair(5, "apple"), Pair(2, "banana"), Pair(9, "cherry") };
    printPairs(s.insertionSort(pairs1));

    vector<Pair> pairs2 = { Pair(3, "cat"), Pair(3, "bird"), Pair(2, "dog") };
    printPairs(s.insertionSort(pairs2));
}


// CustomSortString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <unordered_map>
#include <iostream>
using namespace std;

class Solution 
{
public:
    string customSortString(string order, string s) 
    {
        unordered_map<char, int> m; // char, pos
        for (const auto& c : s)
            m[c]++;
        
        string res;
        // custom insertion
        for (const auto& c : order)
        {
            if (m.find(c) != m.end())
            {
                res.append(m[c], c);
                m.erase(c);
            }
        }

        // complete the remaining insertion
        for (const auto& [pos, c] : m)
            res.append(pos, c);

        return res;
    }
};

int main()
{
    Solution sol;
    string order = "cba", s = "abcd";
    cout << sol.customSortString(order, s) << endl;

    order = "bcafg", s = "abcd";
    cout << sol.customSortString(order, s) << endl;

    order = "kqep", s = "pekeq";
    cout << sol.customSortString(order, s) << endl;

    return 0;
}

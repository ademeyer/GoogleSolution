// PartitionLabels.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); ++i)
            mp[s[i]] = i;

        vector<int> res;
        int size = 0, end = 0;
        
        for (int i = 0; i < s.size(); ++i)
        {
            ++size;
            end = max(end, mp[s[i]]);

            if (i == end)
            {
                res.push_back(size);
                size = 0;
            }
        }
        return res;
    }
};

template<typename T>
void Print(const vector<T> vec)
{
    cout << '[';
    for (const auto& v : vec)
        cout << v << ',';
    cout << "]\n";
}

int main()
{
    Solution sol;
    string s = "ababcbacadefegdehijhklij";
    auto res = sol.partitionLabels(s);
    Print(res);

    s = "eccbbbbdec";
    res = sol.partitionLabels(s);
    Print(res);

    return 0;
}

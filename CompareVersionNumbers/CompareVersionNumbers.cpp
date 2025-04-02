// CompareVersionNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution 
{
public:
    int compareVersion(string version1, string version2) 
    {
        vector<int> ver1, ver2;
        string temp = "";
        version1 += '.';
        version2 += '.';
        for (const auto& v : version1)
        {
            if (v != '.')
            {
                temp += v;
                continue;
            }
            ver1.push_back(stoi(temp));
            temp.clear();
        }

        for (const auto& v : version2)
        {
            if (v != '.')
            {
                temp += v;
                continue;
            }
            ver2.push_back(stoi(temp));
            temp.clear();
        }
        auto combinedValue = [](const vector<int>& ver) // 1, 2 4 = 100 + 20 + 4
        {
            unsigned long val = 0;
            auto n = ver.size();
            for (size_t i = 0; i < n; ++i)
                val += ver[i] * pow(10, n - i - 1); 
            return val;
        };
        auto max_n = max(ver1.size(), ver2.size()); 
        ver1.resize(max_n, 0);
        ver2.resize(max_n, 0);

        for (int i = 0; i < max_n; ++i)
        {
            if (ver1[i] < ver2[i]) return -1;
            if (ver1[i] > ver2[i]) return 1;
        }

        //auto val1 = combinedValue(ver1);
        //auto val2 = combinedValue(ver2);

        //if (val1 < val2) return -1;
        //if (val1 > val2) return 1;
        return 0;
    }
};

int main()
{
    Solution s;
    string version1 = "1.2", version2 = "1.10";
    cout << s.compareVersion(version1, version2) << endl;

    version1 = "1.01", version2 = "1.001";
    cout << s.compareVersion(version1, version2) << endl;

    version1 = "1.0", version2 = "1.0.0.0";
    cout << s.compareVersion(version1, version2) << endl;

    version1 = "19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.00.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000";
    version2 = "19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000";
    cout << s.compareVersion(version1, version2) << endl;

    return 0;

}

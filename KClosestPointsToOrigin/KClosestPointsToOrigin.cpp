// KClosestPointsToOrigin.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        // { {0,1}, {1,0} };
        vector<vector<int>> result;
        priority_queue<int, vector<int>, greater<int>> closesPoint;
        unordered_map<int, vector<vector<int>>> mp;
        auto dist = [&](const vector<int>& p) -> int
        {
            return (abs(p[0] * p[0]) + abs(p[1] * p[1]));
        };

        for (const auto& p : points)
        {
            auto distance = dist(p);
            closesPoint.push(distance);
            mp[distance].push_back(p);
        }

        while(k > 0)
        {
            auto p = closesPoint.top(); closesPoint.pop();
            auto lp = mp[p];
            for (const auto& i : lp)
            {
                if(k > 0)
                    result.push_back(i);
                --k;
            }
        }
        return result;
    }
};

void Print(const vector<vector<int>>& vec)
{
    cout << "[\n";
    for (const auto& v : vec)
    {
        cout << "[";
        for (const auto i : v)
            cout << i << ",";
        cout << "]\n";
    }
    cout << "]\n\n";
}


int main()
{
    Solution s;
    vector<vector<int>> points{ {1,3}, {-2,2} };
    int k = 1;
    auto res = s.kClosest(points, k);
    Print(res);

    points = { {3,3}, {5,-1}, {-2,4} };
    k = 2;
    res = s.kClosest(points, k);
    Print(res);

    points = { {0,1}, {1,0} };
    k = 2;
    res = s.kClosest(points, k);
    Print(res);

    return 0;
}

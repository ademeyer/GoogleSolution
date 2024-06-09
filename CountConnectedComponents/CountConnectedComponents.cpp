// CountConnectedComponents.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>
#include <vector>

using namespace std;
class Solution
{
public:
    int countComponents(int n, vector<vector<int>>& edges)
    {
        vector<int> par;
        for (int i = 0; i < n; ++i)
            par.push_back(i);

        vector<int> rank(n, 1);

        function<int(int)> find = [&](int n1)
        {
            int res = n1;

            while (res != par[res])
            {
                par[res] = par[par[res]];
                res = par[res];
            }
            return res;
        };

        function<int(int, int)> Union = [&](int n1, int n2)
        {
            int p1 = find(n1);
            int p2 = find(n2);

            if (p1 == p2)
                return 0;

            if (rank[p2] > rank[p1])
            {
                par[p1] = p2;
                rank[p2] += rank[p1];
            }
            else
            {
                par[p2] = p1;
                rank[p1] += rank[p2];
            }
            return 1;
        };

        int res = n;
        for (auto n : edges)
        {
            res -= Union(n[0], n[1]);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> edges = { {0,1}, {0,2} };
    cout << s.countComponents(3, edges) << endl;

    edges = { {0,1}, {1,2},{2,3}, {4,5} };
    cout << s.countComponents(6, edges) << endl;
    
    edges = { {0,1}, {0,2},{1,2} };
    cout << s.countComponents(3, edges) << endl;
}

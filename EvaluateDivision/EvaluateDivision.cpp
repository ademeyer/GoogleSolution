// EvaluateDivision.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
    {
        unordered_map<string, vector<pair<string, double>>> adj;
        for (int i = 0; i < equations.size(); ++i)
        {
            auto eq = equations[i];
            adj[eq[0]].push_back(pair<string, double>{ eq[1], values[i] });
            adj[eq[1]].push_back(pair<string, double>{ eq[0], 1.0 / values[i] });
        }

        function<double(string, string)> bfs = [&](string src, string target)
        {
            if (adj.find(src) == adj.end() || adj.find(target) == adj.end())
                return -1.0;

            queue<pair<string, double>> q;
            set<string> visited;

            q.push({ src, 1 });
            visited.insert(src);

            while (!q.empty())
            {
                auto p = q.front(); q.pop();
                if (p.first == target)
                    return p.second;

                    for (const auto& [nei, wei] : adj[p.first]) // required C++20
                    {
                        if (visited.count(nei) == 0)
                        {
                            q.push({ nei, p.second * wei });
                            visited.insert(nei);
                        }
                    }
            }

            return -1.0;
        };

        vector<double> result;
        for (const auto& q : queries)
        {
            result.push_back(bfs(q[0], q[1]));
        }

        return result;
    }
};

void Print(const vector<double>& result)
{
    cout << "[";
    for (const auto& r : result)
    {
        cout << r << ",";
    }
    cout << "]\n";
}

int main()
{
    Solution s;
    vector<vector<string>> equations = { {"a", "b"},{"b", "c" } };
    vector<double> values = { 2.0, 3.0 };
    vector<vector<string>> queries = { {"a", "c"},{"b", "a"},{"a", "e"},{"a", "a"},{"x", "x"} };
    auto r = s.calcEquation(equations, values, queries);
    Print(r);

    equations = { {"a", "b"},{"c", "d" } };
    values = { 1.0, 1.0 };
    queries = { {"a", "c"},{"b", "d"},{"b", "a"},{"d", "c"} };
    r = s.calcEquation(equations, values, queries);
    Print(r);
}

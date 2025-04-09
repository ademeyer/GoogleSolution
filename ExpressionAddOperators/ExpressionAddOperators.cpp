// ExpressionAddOperators.cpp : This file contains the 'main' function. Program execution begins and ends there.
// O(4^n * n)

#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution 
{
public:
    vector<string> addOperators(string num, int target) 
    {
        if (num.empty()) return { };

        vector<string> result;

        function<void(int, string, long, long)> dfs =
            [&](int index, string path, long curVal, long preVal)
        {
            if (index == num.size())
            {
                if (curVal == target)
                    result.push_back(path);
                return;
            }

            for (int i = index; i < num.size(); ++i)
            {
                if (i != index && num[index] == '0') break; // skip trailing zeros

                auto curStr = num.substr(index, i - index + 1);
                auto curNum = stol(curStr);

                if (index == 0) // if it's the first
                    dfs(i + 1, curStr, curNum, curNum);
                else
                {
                    // for '+' possibility
                    dfs(i + 1, path + "+" + curStr, curVal + curNum, curNum);
                    // for '-' possibility
                    dfs(i + 1, path + "-" + curStr, curVal - curNum, -curNum);
                    // for '*' possibility
                    dfs(i + 1, path + "*" + curStr, (curVal - preVal) + (preVal * curNum), preVal * curNum);
                }
            }
        };

        dfs(0, "", 0, 0);

        return result;
    }
};

template <typename T>
void Print(const T& val)
{
    cout << "[";
    for (const auto c : val)
        cout << c << ", ";
    cout << "]\n";
}

int main()
{
    Solution s;
    auto r = s.addOperators("123", 6);
    Print(r);

    r = s.addOperators("232", 8);
    Print(r);

    r = s.addOperators("3456237490", 9191);
    Print(r);

    return 0;
}

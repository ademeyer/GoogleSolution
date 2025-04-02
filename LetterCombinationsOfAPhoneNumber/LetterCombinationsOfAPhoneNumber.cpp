// LetterCombinationsOfAPhoneNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        const unordered_map<char, string> keypad = 
        {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
            {'5', "jkl"}, {'6', "mno"}, {'7', "qprs"},
            {'8', "tuv"}, {'9', "wxyz"},
        };

        function<void(int, string)> dfs = [&](int i, string curStr) 
        {
            if (curStr.size() == digits.size())
            {
                res.push_back(curStr);
                return;
            }

            if (keypad.find(digits[i]) == keypad.end()) return;

            for (const auto& c : keypad.at(digits[i]))
                dfs(i + 1, curStr + c);
        };

        if (!digits.empty())
            dfs(0, "");

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
    string digits = "23";
    auto res = sol.letterCombinations(digits);
    Print(res);

    digits = "2";
    res = sol.letterCombinations(digits);
    Print(res);
}
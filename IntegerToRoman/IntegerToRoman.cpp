// IntegerToRoman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <ranges>

using namespace std;

class Solution 
{
    const vector<pair<string, int>> symList
    {
        {"I", 1},       {"IV", 4},      {"V", 5},       {"IX", 9},
        {"X", 10},      {"XL", 40},     {"L", 50},      {"XC", 90},
        {"C", 100},     {"CD", 400},    {"D", 500},     {"CM", 900},
        {"M", 1000}
    };
public:
    string intToRoman(int num) 
    {
        string res = "";
        for (const auto& s : symList | std::views::reverse)
        {
            auto sym = s.first;
            auto val = s.second;
            int count = 0;
            if ((count = num / val)) // if non - zero
            {
                for (int i = 0; i < count; i++)
                    res += sym;
                num %= val;
            }
        }

        return res;
    }
};

int main()
{
    Solution s;
    cout << "roman: " << s.intToRoman(3749) << endl;
    cout << "roman: " << s.intToRoman(58) << endl;
    cout << "roman: " << s.intToRoman(1994) << endl;
}


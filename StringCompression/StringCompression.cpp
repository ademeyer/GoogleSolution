// StringCompression.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int compress(vector<char>& chars)
    {
        int n = chars.size();
        if (n == 0) return 0;

        int write = 0;
        int read = 0;

        while (read < n)
        {
            auto ch = chars[read]; // current character
            int count = 0;

            // while we have the current character, count
            while (read < n && chars[read] == ch)
            {
                ++read;
                ++count;
            }

            // write the current char
            chars[write++] = ch;

            if (count > 1)
            {
                auto cntstr = to_string(count);
                for (const auto c : cntstr)
                    chars[write++] = c;
            }
        }

        chars.resize(write);
        return write;
    }
};

void PrintResult(const vector<char>& chars, int val)
{
    cout << "size: " << val << "[";
    for (const auto& c : chars)
        cout << c << ",";
    cout << "]\n";
}

int main()
{
    Solution s;
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c'};
    auto v = s.compress(chars);
    PrintResult(chars, v);

    chars = { 'a' };
    v = s.compress(chars);
    PrintResult(chars, v);

    chars = { 'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b' };
    v = s.compress(chars);
    PrintResult(chars, v);

    return 0;
}
#include <iostream>
#include <string>

#include <vector>
using namespace std;

class Solution
{
    const string dataDelimiter = "#";
public:

    string encode(vector<string>& strs)
    {
        string result;
        for (const auto str : strs)
        {
            int len = str.size();
            result += to_string(len) + dataDelimiter + str + dataDelimiter;
        }
        return result;
    }

    vector<string> decode(string s)
    {
        vector<string> result;
        string temp = "";
        int expect_str_len = 0;
        int i = 0;
        while (i < s.size())// 4#neet#4#code#4#love#3#you#
        {
            char ch = s[i];
            if (ch == dataDelimiter[0])
            {
                // what we have is not a number string
                if (temp.empty())
                {
                    i++;
                    continue;
                }

                if (expect_str_len == 0)
                {
                    expect_str_len = stoi(temp.c_str());
                    temp.clear();
                    while (expect_str_len > 0 && i < s.size())
                    {
                        expect_str_len--;
                        i++;
                        temp += s[i];
                    }
                    result.push_back(temp);
                    temp.clear();
                }
            }
            else
            {
                temp += ch;
            }
            i++;
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<string> Input_1 = { "neet","code","love","you" };
    auto encodestr = s.encode(Input_1);
    cout << "Encoding result: " << encodestr << endl;
    auto decodestr = s.decode(encodestr);
    for (const auto& str : decodestr)
        cout << str << ", ";
    cout << endl;

    vector<string> Input_2 = { "we","say",":","yes" };
    encodestr = s.encode(Input_2);
    cout << "Encoding result: " << encodestr << endl;
    decodestr = s.decode(encodestr);
    cout << "Decoded string = [";
    for (const auto& str : decodestr)
        cout << str << ", ";
    cout << "]" << endl;

    return 0;
}
// CountAndSay.cpp : This file contains the 'main' function. Program execution begins and ends there.
// time complexity of O(n * m), where m is the average length of the terms, which grows exponentially in the worst case

#include <iostream>
#include <string>
using namespace std;

class Solution 
{
public:
    string countAndSay(int n) 
    {
        if (n == 1) return "1";

        string cur = "1";
        for (int i = 2; i <= n; ++i)
        {
            string next;
            int cnt = 1;
            for (int j = 1; j < cur.size(); ++j)
            {
                if (cur[j] == cur[j - 1])
                    ++cnt;
                else
                {
                    next += to_string(cnt) + cur[j - 1];
                    cnt = 1;
                }
            }
            next += to_string(cnt) + cur.back();
            cur = next;
        }
        return cur;
    }
};

int main()
{

}


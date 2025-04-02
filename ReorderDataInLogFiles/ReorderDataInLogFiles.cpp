// ReorderDataInLogFiles.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Comparator
{
public:
    bool operator()(const string& a, const string& b)
    {
        int spacePosA = a.find(' ');
        int spacePosB = b.find(' ');
        auto contentA = a.substr(spacePosA + 1);
        auto contentB = b.substr(spacePosB + 1);

        if (contentA == contentB)
            return a.substr(0, spacePosA) > b.substr(0, spacePosB);

        return contentA > contentB;
    }
};

class Solution
{
public:
    vector<string> reorderLogFiles(vector<string>& logs)
    {
        vector<string> result;
        priority_queue<string, vector<string>, Comparator> letterLogs;
        queue<string> digitLogs;

        for (const auto& log : logs)
        {
            int spacePos = log.find(' ');
            if (isalpha(log[spacePos + 1]))
                letterLogs.push(log);
            else // we assume it's a digit logs
                digitLogs.push(log);
        }

        // add letterLogs and digitLogs in result
        while (!letterLogs.empty())
        {
            auto l = letterLogs.top(); letterLogs.pop();
            result.push_back(l);
        }
        while (!digitLogs.empty())
        {
            auto l = digitLogs.front(); digitLogs.pop();
            result.push_back(l);
        }

        return result;
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
    Solution s;
    vector<string> logs{ "dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero" };
    auto res = s.reorderLogFiles(logs);
    Print(res);

    logs = { "a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo" };
    res = s.reorderLogFiles(logs);
    Print(res);

    return 0;
}

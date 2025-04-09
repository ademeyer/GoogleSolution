// MaximumSwap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int maximumSwap(int num)
    {
        if (num == 0) return num;
        auto numStr = to_string(num);
        auto n = numStr.size();
        vector<int>lastPos(10, -1);

        for (int i = 0; i < n; ++i)
            lastPos[numStr[i] - '0'] = i;
        
        for (int i = 0; i < n; ++i)
        {
            auto curDigit = numStr[i] - '0';
            for (int d = 9; d > curDigit; --d)
            {
                if (lastPos[d] > i)
                {
                    swap(numStr[i], numStr[lastPos[d]]);
                    return stoi(numStr);
                }
            }
        }
        return num;
    }
};

int main()
{
    Solution s;
    cout << s.maximumSwap(2736) << endl;
    cout << s.maximumSwap(9973) << endl;

}

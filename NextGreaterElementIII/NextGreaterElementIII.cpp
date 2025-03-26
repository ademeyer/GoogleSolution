// NextGreaterElementIII.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include<queue>

using namespace std;

class Solution 
{
public:
    int nextGreaterElement(int m)
    {
        long n = m;
        vector<int> count(10, 0);
        int curRem = -1;
        int prevRem = -1;

        while (n > 0)
        {
            curRem = n % 10;
            n /= 10;
            count[curRem]++;
            if (prevRem > curRem)
            {
                int num = curRem + 1;
                while (count[num] == 0) num++;
                count[num]--;
                n = n * 10 + num;

                for (int i = 0; i < 10; ++i)
                {
                    while (count[i]-- > 0)
                        n = n * 10 + i;
                }

                return n > INT_MAX ? -1 : n;
            }
            prevRem = curRem;
        }    
        return  -1;
    }
};

int main()
{
    Solution s;
    cout << "next greater element III: " << s.nextGreaterElement(12) << endl;
    cout << "next greater element III: " << s.nextGreaterElement(21) << endl;
    cout << "next greater element III: " << s.nextGreaterElement(13) << endl;
}

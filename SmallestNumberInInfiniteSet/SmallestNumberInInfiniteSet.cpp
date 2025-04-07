// SmallestNumberInInfiniteSet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <unordered_set>
#include <iostream>
#include <queue>

using namespace std;

class SmallestInfiniteSet 
{
    int curSmallestNumer;
    priority_queue<int, vector<int>, greater<int>> addedBack;
    unordered_set<int> cache;
public:
    SmallestInfiniteSet() : curSmallestNumer(1) {}

    int popSmallest() 
    {
        int res;
        if (!addedBack.empty())
        {
            res = addedBack.top(); addedBack.pop();
            cache.erase(res);
        }
        else
            res = curSmallestNumer++;
        return res;
    }

    void addBack(int num) 
    {
        if (num < curSmallestNumer && !cache.count(num))
        {
            addedBack.push(num);
            cache.insert(num);
        }
    }
};


int main()
{
    return 0;
}

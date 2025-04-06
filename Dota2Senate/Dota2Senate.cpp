// Dota2Senate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
using namespace std;

class Solution 
{
public:
    string predictPartyVictory(string senate) 
    {
        queue<int> Rq, Dq;

        for (int i = 0; i < senate.size(); ++i)
        {
            if (senate[i] == 'R')
                Rq.push(i);
            else
                Dq.push(i);
        }

        while (!Rq.empty() and !Dq.empty())
        {
            auto dTurn = Dq.front(); Dq.pop();
            auto rTurn = Rq.front(); Rq.pop();

            if (rTurn < dTurn)
                Rq.push(dTurn + senate.size());
            else
                Dq.push(rTurn + senate.size());
        }

        return !Rq.empty() ? "Radiant" : "Dire";
    }
};

int main()
{
    Solution s;
    string senate = "RD";
    cout << s.predictPartyVictory(senate) << endl;

    senate = "RDD";
    cout << s.predictPartyVictory(senate) << endl;

    return 0;
}
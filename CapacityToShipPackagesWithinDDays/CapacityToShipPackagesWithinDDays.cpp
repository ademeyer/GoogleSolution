// CapacityToShipPackagesWithinDDays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution 
{
public:
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        auto res = r;

        auto canShip = [&](int cap) -> bool 
        {
            auto ships = 1;
            auto curCap = cap;
            for (const auto& w : weights)
            {
                if (curCap - w < 0)
                {
                    ++ships;
                    curCap = cap;
                }
                curCap -= w;
            }
            return ships <= days;
        };
        
        // binary search
        while (l <= r)
        {
            auto cap = (l + r) / 2;
            if (canShip(cap))
            {
                res = min(res, cap);
                r = cap - 1;
            }
            else
                l = cap + 1;
        }
        return res;
    }
};

int main()
{

}


// BestTimeToBuyAndSellStock.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int l = 0, r = 1; // l - buy, r - sell

        int maxProfit = 0;
        while (r < prices.size())
        {
            // is it profitable?
            if (prices[l] < prices[r])
            {
                maxProfit = max(maxProfit, (prices[r] - prices[l]));
            }
            else
            {
                l = r;
            }
            ++r;
        }
        return maxProfit;
    }
};
int main()
{
    Solution s;
    vector<int> prices = { 7,1,5,3,6,4 };
    cout << "Max Profix = " << s.maxProfit(prices) << endl;

    prices = { 7,6,4,3,1 };
    cout << "Max Profix = " << s.maxProfit(prices) << endl;

    return 0;
}
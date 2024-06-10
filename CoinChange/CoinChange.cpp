// CoinChange.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Time: O(amount * coins.size()) Space: O(amount)

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
        vector<int> dp((amount + 1), (amount + 1));
        dp[0] = 0;

        for (int a = 1; a < (amount + 1); a++)
        {
            for (auto c : coins)
            {
                if (a - c >= 0)
                {
                    dp[a] = min(dp[a], (1 + dp[a - c])); // recurrent relation
                }
            }
        }
        if (dp[amount] != amount + 1)
            return dp[amount];
        
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> coins = { 1,2,5 };
    cout << s.coinChange(coins, 11) << endl;
    coins = {2};
    cout << s.coinChange(coins, 3) << endl;
    coins = { 1 };
    cout << s.coinChange(coins, 0) << endl;
}


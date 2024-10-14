#include <bits/stdc++.h>
using namespace std;
// leetcode

// buy as many times and sell as many times as u want
// But   we first buy a stock and then sell it. After selling  only we can buy and sell again. But we can’t sell before buying and can’t buy before selling any previously bought stock.

// MEmoisation

class Solution
{
public:
    int helper(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (ind == prices.size())
            return 0;
        if (dp[ind][buy] != -1)
            return dp[ind][buy];
        int profit;
        if (buy == 1)
        {
            // profit=SP-CP
            int buy = -prices[ind] + helper(ind + 1, 0, prices, dp);
            int notBuy = 0 + helper(ind + 1, 1, prices, dp); // let prices is too high so buy on next day
            profit = max(buy, notBuy);
        }
        else
        { // selling
            int sell = prices[ind] + helper(ind + 1, 1, prices, dp);
            int notSell = 0 + helper(ind + 1, 0, prices, dp);
            profit = max(sell, notSell);
        }
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int> &prices)
    {
        int buy = 1; // 1 means buy ,0 mean not buy
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return helper(0, buy, prices, dp);
    }
};

// Tabulation

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // 1 means buy ,0 mean not buy
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        dp[n][0] = 0;
        dp[n][1] = 0;
        int profit;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int b = 1; b >= 0; b--)
            {
                if (b == 1)
                { // we can buy the stock
                    profit = max(dp[i + 1][0] - prices[i], dp[i + 1][1]);
                }
                if (b == 0)
                {
                    profit = max(prices[i] + dp[i + 1][1], dp[i + 1][0]);
                }
                dp[i][b] = profit;
            }
        }

        return dp[0][1]; // Return maximum profit when starting with the ability to buy
    }
};

// or Simply
/*

int maxProfit(vector<int> &prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int i = n - 1; i >= 0; i--) {
        dp[i][0] = max(dp[i + 1][0], prices[i] + dp[i + 1][1]);  // Not holding stock
        dp[i][1] = max(dp[i + 1][1], -prices[i] + dp[i + 1][0]); // Holding stock
    }

    return dp[0][0]; // Maximum profit when not holding any stock at the end
}*/

// Space Optimised mehotd

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> curr(2, 0), ahead(2, 0);
        ahead[0] = ahead[1] = 0;
        int profit;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int b = 1; b >= 0; b--)
            {
                if (b == 1)
                { // we can buy the stock
                    profit = max(ahead[0] - prices[i], ahead[1]);
                }
                if (b == 0)
                {
                    profit = max(prices[i] + ahead[1], ahead[0]);
                }
                curr[b] = profit;
            }
            ahead = curr;
        }

        return curr[1]; // Return maximum profit when starting with the ability to buy
    }
};

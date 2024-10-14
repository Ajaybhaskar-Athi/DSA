#include<bits/stdc++.h>
using namespace std;
//leetcode

//u allowed to buy once and sell once 

class Solution {
public:
    //if u r selling on ith day 
    //You buy on the minimum price from 1st day to (i-1)th day 

    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int profit=0;//buy on 1st day and sell on 1st day
        for(int i=1;i<prices.size();i++){
          int  cost=prices[i]-mini;
            profit=max(profit,cost);
            mini=min(mini,prices[i]);
        }
        return profit;
    }
};

#include<bits/stdc++.h>
using namespace std;
//leetcode


class Solution {
public:
    int helper(int ind  ,int buy,vector<int>&prices, vector<vector<vector<int>>>& dp,int cap){
            if(ind==prices.size() )return 0;
            if(cap==0)return 0;
            if(dp[ind][buy][cap]!=-1)return dp[ind][buy][cap];
        int profit=0;
        if(buy==1){
            //profit=SP-CP
            int buy= -prices[ind]+ helper(ind+1,0,prices,dp,cap);
            int notBuy=0+helper(ind+1,1,prices,dp,cap);//let prices is too high so buy on next day
            profit=max(buy,notBuy);
        }else{ //selling
            int sell= prices[ind]+helper(ind+1,1,prices,dp,cap-1); //one transaction (buy -sell) ccompleted so cap--
            int notSell=0+helper(ind+1,0,prices,dp,cap);
            profit=max(sell,notSell);
        }
        return dp[ind][buy][cap]= profit;

    }
    int maxProfit(vector<int>& prices) {
        int  buy=1;//1 means buy ,0 mean not buy
        int cap=2;//cappacity give is max 2 transactions
        int n=prices.size();
         // Creating a 3D DP array of size [n][2][3]
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

        return helper(0,buy,prices,dp,cap);
    }
};
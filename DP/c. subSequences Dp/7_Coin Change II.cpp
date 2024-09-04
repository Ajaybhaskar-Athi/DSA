//No of possibe ways of giving targeted amount


#include<bits/stdc++.h>
using namespace std;


//Recursion
//TC= Exponential [ o(2**n) ]

/*class Solution {
public:

    void helper(int idx,int T,int &ans,vector<int>&coins){
        if(idx==0){
            if(T % coins[idx]==0)ans++;
            return;
        }
        if(T==0){
            ans++;
            return;
        }
        helper(idx-1,T,ans,coins);//not take
       if(coins[idx]<=T) helper(idx,T-coins[idx],ans,coins);//take
    }

    int change(int amount, vector<int>& coins) {
        int ans=0;
        int n=coins.size();
        helper(n-1,amount,ans,coins);
        return ans;
    }
};
*/
//Above is also same but here we r returning so that it can useful in memoisation

class Solution {
public:
    int helper(int idx,int T,vector<int>&coins){
        if(idx==0){
            if(T % coins[idx]==0)return 1;
            else return 0;
        }
        if(T==0){
           return 1;
        }
       int notTake= helper(idx-1,T,coins);//not take
       int Take=0;
       if(coins[idx]<=T)Take= helper(idx,T-coins[idx],coins);//take
       return notTake+Take;
    }

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
       return helper(n-1,amount,coins);
    
    }
};



//Memoisation

class Solution {
public:
    int helper(int idx,int T,int &ans,vector<int>&coins,vector<vector<int>>&dp){
        if(idx==0){
            if(T % coins[idx]==0)return 1;
            else return 0;
        }
        if(T==0){
           return 1;
        }
        if(dp[idx][T]!=-1)return dp[idx][T];
       int notTake= helper(idx-1,T,ans,coins,dp);//not take
       int Take=0;
       if(coins[idx]<=T)Take= helper(idx,T-coins[idx],ans,coins,dp);//take

       return dp[idx][T]= notTake+Take;
    }

    int change(int amount, vector<int>& coins) {
        int ans=0;
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
       return helper(n-1,amount,ans,coins,dp);
        // return ans;
    }
};


///Tabulation


    class Solution {
    public:
    

        int change(int amount, vector<int>& coins) {
            int n=coins.size();
            vector<vector<int>>dp(n,vector<int>(amount+1,-1));

            for(int T=0;T<=amount;T++){
                if(T % coins[0]==0)dp[0][T]=1;
                else dp[0][T]=0;
            }

            for(int i=0;i<n;i++){
                dp[i][0]=1;
            }

            for(int idx=1;idx<n;idx++){
                for(int T=1;T<=amount;T++){
            int notTake= dp[idx-1][T];
             int Take=0;
            if(coins[idx]<=T)Take= dp[idx][T-coins[idx]];
             dp[idx][T]= notTake+Take;
                }
            }

        int ans=dp[n-1][amount];
        return ans;
          
        }
    };


    
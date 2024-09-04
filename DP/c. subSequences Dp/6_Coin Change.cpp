///Minimum no of coins problem



#include<bits/stdc++.h>
using namespace std;

//ReCURSIOn
// TC=O(2^n)

class Solution {
public:
    int helper(int idx,vector<int>&coins,int T){
        if(idx==0){
            if(T % coins[idx]==0)return T/coins[idx];
            else return 1e9; //or INT_MAX

        }
        int notTake=helper(idx-1,coins,T);
        int Take=INT_MAX;
        if(coins[idx]<=T)Take= 1+ helper(idx,coins,T-coins[idx]);
        
        return min(Take,notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int ans= helper(coins.size()-1,coins,amount);
        if(ans>=1e9) return -1; //if somewhere it goes maximum when not possible to give money
        return ans;
    }
};



//Memoisation (TOp down)
//TC=O(N X Target) and SC=O(N X T)+O(T)


class Solution {
public:
    int helper(int idx,vector<int>&coins,int T,vector<vector<int>>&dp){
        if(idx==0){
            if(T % coins[idx]==0)return T/coins[idx];
            else return 1e9; //or INT_MAX
        }
        if(dp[idx][T]!=-1)return dp[idx][T];//its already calculated 
        int notTake=helper(idx-1,coins,T,dp);
        int Take=INT_MAX;
        if(coins[idx]<=T)Take= 1+ helper(idx,coins,T-coins[idx],dp);
        
        return dp[idx][T]= min(Take,notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size() , vector<int>(amount+1,-1));
        int ans= helper(coins.size()-1,coins,amount,dp);
        if(ans>=1e9) return -1; //if somewhere it goes maximum when not possible to give money
        return ans;
    }
};



//Tabulation(Bottom UP => means go from Base case to last)

// 1=> Write Base case first 

        /*//BaseCase :if index=0 target may be anyhtong from 0 to Target;
        for(int T=0;T<=amount;T++){
            if(T % coins[0] ==0)dp[0][T]=T/coins[0];
            else dp[0][T]=INT_MAX;
            */

  //2=>      
//now in memoisationwe r traversing from n-1 to 0 , so reversing it 0 to n-1 
//and also target acived by 0 to target and not Target to 0 unlike Memoisation


// and paste the Recursion 

/*

        for(int idx=1;idx<n;idx++){
            for(int T=0 ;T<=amount;T++){

                int notTake=helper(idx-1,coins,T,dp);
        int Take=INT_MAX;
        if(coins[idx]<=T)Take= 1+ helper(idx,coins,T-coins[idx],dp);
        
        return dp[idx][T]= min(Take,notTake);

            }
        }


*/


 int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1,-1));

        //BaseCase :if index=0 target may be anyhtong from 0 to Target;
        for(int T=0;T<=amount;T++){
            if(T % coins[0] ==0)dp[0][T]=T/coins[0];
            else dp[0][T]=INT_MAX;
        }

        for(int idx=1;idx<n;idx++){
            for(int T=0 ;T<=amount;T++){

                 int notTake=dp[idx-1][T];
            int Take=INT_MAX;
        if(coins[idx]<=T)Take= 1+ dp[idx][T-coins[idx]];
        
        dp[idx][T]= min(Take,notTake);

            }
        }

        int ans=dp[n-1][amount];
        if(ans>=1e9) return -1; //if somewhere it goes maximum when not possible to give money
        return ans;
    }

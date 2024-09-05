#include<bits/stdc++.h>
using namespace std;

//fixed to varible

class Solution {
public:
    int helper(int i,int j,vector<vector<int>>&v,vector<vector<int>>&dp){
        int n=v.size();
        if(i==n-1)return v[i][j];
        if(dp[i][j]!=-1)return dp[i][j];

        int down=v[i][j]+helper(i+1,j,v,dp);
        int diag=v[i][j]+helper(i+1,j+1,v,dp);

        return dp[i][j]= min(down,diag);

    }

    int minimumTotal(vector<vector<int>>& v) {
        int n=v.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return helper(0,0,v,dp);
        //in this sum its not tpossible to start from last index like we always do since it takes evry element of last row and figure out which one is best
        //so we process this right angle traingle from 1st row itself
    }
};



//Tabulation


class Solution {
public:
  

    int minimumTotal(vector<vector<int>>& v) {
        int n=v.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int j=0;j<n;j++){
            dp[n-1][j]=v[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down=v[i][j]+dp[i+1][j];
                int diag=v[i][j]+dp[i+1][j+1];
                dp[i][j]=min(down,diag);
            }
        }
        return dp[0][0];
    }
};



//Space Optimised 



class Solution {
public:
  

    int minimumTotal(vector<vector<int>>& v) {
        int n=v.size();
        vector<int>prev(n,0),curr(n,0);
        for(int i=0;i<n;i++){
            prev[i]=v[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down=v[i][j]+prev[j];
                int diag=v[i][j]+prev[j+1];
                curr[j]=min(down,diag);
            }
            prev=curr;
        }
        return prev[0];
    }
};
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    int helper(int i,int j,int m,int n,vector<vector<int>>&v,vector<vector<int>>&dp){

            if(i>=m || j>=n)return 0;
            if(v[i][j]==1)return 0;
            if(i==m-1 && j==n-1)return 1;
        if(dp[i][j]!=-1)return dp[i][j];

             int right=helper(i,j+1,m,n,v,dp);
            int down=helper(i+1,j,m,n,v,dp);

        return dp[i][j]= right+down;

    }

    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int m=v.size();
        int n=v[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));

          return helper(0,0,m,n,v,dp);
    }
};
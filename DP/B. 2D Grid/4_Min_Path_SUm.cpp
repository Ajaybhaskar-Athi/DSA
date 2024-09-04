


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    int helper(int i,int j,int m,int n,vector<vector<int>>&v,vector<vector<int>>&dp){

            if(i>=m || j>=n)return 1e9;
            if(i==m-1 && j==n-1)return v[i][j];
           if(dp[i][j]!=-1)return dp[i][j];

             int right=helper(i,j+1,m,n,v,dp)+v[i][j];
            int down=helper(i+1,j,m,n,v,dp)+v[i][j];

        return dp[i][j]= min(right,down);

    }

    int minPathSum(vector<vector<int>>& v) {
        int m=v.size();
        int n=v[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        // int sum=0;
          return helper(0,0,m,n,v,dp);
    }
};



//tab ulation




    int minPathSum(vector<vector<int>>& v) {
        int m=v.size();
        int n=v[0].size();
   

        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
            dp[m-1][n-1]=v[m-1][n-1];
            for(int i=0;i<=n;i++){
                dp[m][i]=1e9; 
            }
            for(int i=0;i<=m;i++){
                dp[i][n]=1e9; 
            }


            for(int i=m-1;i>=0;i--){
                for(int j=n-1;j>=0;j--){
                    if(i==m-1 && j==n-1)continue; //skip base case
            
             int right=dp[i][j+1]+v[i][j];
            int down=dp[i+1][j]+v[i][j];
            dp[i][j]=min(right,down);
                }
            }
            return dp[0][0];
        

    }

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

        int solve(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&grid){
                    
                int row=0;
                int urd=0;
                int lrd=0;
                int m=grid.size();
                int n=grid[0].size();
                if(dp[i][j]!=-1)return dp[i][j];
            //go in same row
            if( i<m && j+1<n && grid[i][j+1]>grid[i][j]){
                row=1+solve(i,j+1,dp,grid);
            }
            //go in upper right diagonal
         if( i-1>=0 &&j+1<n && grid[i-1][j+1]>grid[i][j]){
                     urd=1+solve(i-1,j+1,dp,grid);
            }
            //go in lower right diagonal
        if( i+1<m &&j+1<n && grid[i+1][j+1]>grid[i][j]){
                lrd=1+solve(i+1,j+1,dp,grid);
            }

            return dp[i][j]= max({row,lrd,urd});



        }

    int maxMoves(vector<vector<int>>& grid) {
                int moves=0,maxMoves=INT_MIN;
                vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));

            for(int i=0;i<grid.size();i++){
              int moves= solve(i,0,dp,grid);
              maxMoves=max(maxMoves,moves);
            }
            return maxMoves;

    }
};



//Tabulation

//in memoisation we started from 1st column and move toward last column for evry Row
//Now  we start from last column and move towrds left (i.e,, first column) of evryy row

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int maxMoves = 0;

        // Fill the dp table from the last column to the first column
        for (int j = n -1; j >= 0; j--) {
            for (int i = 1; i <=m; i++) {
                // Move in the same row
                    int row=0,urd=0,lrd=0;
                if ( j+1<n && grid[i-1][j + 1] > grid[i-1][j]) {
                  row = 1 + dp[i][j + 1];
                }
                // Move in upper diagonal right
                if (i - 2>= 0  && j + 1 < n &&grid[i - 2][j + 1] > grid[i-1][j]) {
                    urd= 1 + dp[i - 1][j + 1];
                }
                // Move in lower diagonal right
                if (i  < m && j + 1 < n && grid[i ][j + 1] > grid[i-1][j]) {
                 lrd =  1 + dp[i + 1][j + 1];
                }
                // Update the maximum moves found
                dp[i][j]=max({row,lrd,urd});


                
                   if (j == 0) {
                    maxMoves = max(maxMoves, dp[i][j]);
                }
            }
        }

        return maxMoves;
    }
};
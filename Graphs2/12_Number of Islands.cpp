#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void helper(vector<vector<char>>&grid,int i,int j,int m,int n){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]=='0' )return;

        grid[i][j]='0'; //make 1 as 0
        //left
        helper(grid,i,j-1,m,n);
        //right
        helper(grid,i,j+1,m,n);
        //down  
        helper(grid,i+1,j,m,n);
        //up
        helper(grid,i-1,j,m,n);
    }

    int numIslands(vector<vector<char>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
    int ans=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    helper(grid,i,j,m,n); //mark all its connected 1's to zeroes
                }
            }
        }
        return ans;

    }
};
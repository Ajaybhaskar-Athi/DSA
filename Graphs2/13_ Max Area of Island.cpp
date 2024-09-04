#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void helper(vector<vector<int>>&grid,int i,int j,int m,int n,int &curr_area){
        if(i<0 || j<0 || i>=m||j>=n|| grid[i][j]==0)return;
        grid[i][j]=0;
        curr_area++;
         //left
        helper(grid,i,j-1,m,n,curr_area);
        //right
        helper(grid,i,j+1,m,n,curr_area);
        //down  
        helper(grid,i+1,j,m,n,curr_area);
        //up
        helper(grid,i-1,j,m,n,curr_area);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int numIslands=0;
        int area=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    numIslands++;
                    int curr_area=0;
                    helper(grid,i,j,m,n,curr_area);
                    area=max(area,curr_area);
                }
            }
        }
        return area;
    }
};
//leetcode 2192
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
     
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>g(n);//adjacency list
           vector<vector<int>>ans(n);
        for(auto v:edges){
            int a=v[0];
            int b=v[1];
        g[a].push_back(b);
        }
          for(int i=0;i<n;i++){
          vector<int>vis(n,0);
            dfs_helper(g,vis,ans,i,i);
          }

          for(int i=0;i<n;i++){
            sort(ans[i].begin(),ans[i].end());
          }
            return ans;
    }
    void dfs_helper(vector<vector<int>>&g,vector<int>&vis,vector<vector<int>>&ans,int parent,int curr){
        vis[curr]=1;
        for(int dest:g[curr]){
            if(!vis[dest]){
                ans[dest].push_back(parent);
                dfs_helper(g,vis,ans,parent,dest);
            }
        }
    }
};



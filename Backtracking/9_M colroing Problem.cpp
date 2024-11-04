#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
        
        bool isPossible(vector<vector<int>>&g,vector<int>&color,int src,int col){
            
            for(int ele:g[src]){
                if(color[ele]==col)return false;
            }
            return true;
        }
    
    bool helper(int src,vector<vector<int>>&g,vector<int>&color,int m){
        if(g.size()==src)return true;
        for(int i=1;i<=m;i++){
            if(isPossible(g,color,src,i)){
                    color[src]=i;
                    if(helper(src+1,g,color,m))return true;
                    color[src]=0;
            }
        }
        return false;
    }
  
    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        // code here
        
            vector<vector<int>>g(v);
            for(auto arr:edges){
                int a=arr.first;
                int b=arr.second;
                g[a].push_back(b);
                g[b].push_back(a);
            }
            vector<int>color(v,0);
            return helper(0,g,color,m);
            
        
    }
};

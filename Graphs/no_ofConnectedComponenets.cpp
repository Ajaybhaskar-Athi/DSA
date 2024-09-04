#include<bits/stdc++.h>
// in unidirected graph

using namespace std;
    void dfs(vector<vector<int>>&g,vector<int>&vis,int src){
        vis[src]=1;
        for(int ele:g[src]){
            if(!vis[ele]){
                dfs(g,vis,ele);
            }
        }
        return;
    }

int connected_components(vector<vector<int>>&g){
    vector<int>vis(g.size(),0);
    int count=0;
    for(int i=0;i<g.size();i++){
        if(!vis[i]){
            count++;
            dfs(g,vis,i);
        }
    }
    return count;
}
#include<bits/stdc++.h>
using namespace std;
bool helper_dfs(vector<vector<int>>&graph,vector<int>&vis,int src,int parent){

    vis[src]=1;
    for(int nbr: graph[src]){
        if(nbr!=parent && vis[nbr])return true;
        if(!vis[nbr]){
            if(helper_dfs(graph,vis,nbr,src))return true;
        }

    }
return false;
}

bool have_cycle(vector<vector<int>>&graph){
    vector<int>vis(graph.size(),0);
    for(int i=0;i<vis.size();i++){
        if(!vis[i]){
            if(helper_dfs(graph,vis,i,-1));return 1;
        }
    }
    return false;
}
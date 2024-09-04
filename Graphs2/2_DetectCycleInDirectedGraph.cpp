#include<bits/stdc++.h>
using namespace std;
//gfraph with verticess from 0 to n-1;

bool dfs_helper(vector<vector<int>>&g,vector<int>&vis,vector<int>&rec_stack,int node){
    vis[node]=1;
    rec_stack[node]=1;//add current node to path

    for(int i=0;i<g[node].size();i++){//use for each loop for code readbality instead this 
        if(!vis[g[node][i]]){ //traverse if node not visited
            if(dfs_helper(g,vis,rec_stack,g[node][i]))return true;
        }
        else if(rec_stack[node]){ //if visited check if its already in the stack
        return true;
    }
    }
    //suppose if node has no neighbours we dont go further in that path remove that node from path and return false
    rec_stack[node]=0;
    return false;

}

bool hasCycle(vector<vector<int>>&g){
    vector<int>vis(g.size(),0);
    vector<int>rec_stack(g.size(),0); //maintaining nodes in current path
    for(int i=0;i<vis.size();i++){
        if(!vis[i]){
            if(dfs_helper(g,vis,rec_stack,i))return true;
        }
    }
    return false;
}
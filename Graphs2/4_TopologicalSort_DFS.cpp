#include<bits/stdc++.h>
using namespace std;

//DFS
//DIRECTED Acyclic GRAPH
class Solution {
public:
        void helper_dfs(vector<vector<int>>&g,vector<int>&vis,stack<int>&stk,int node){
            vis[node]=1;
            for(int nbr:g[node]){
             if(!vis[node])helper_dfs(g,vis,stk,nbr);
            }
            stk.push(node);
        }

    vector<int> toposort(vector<vector<int>>& g) {
        vector<int>vis(g.size(),0);
                stack<int>stk;
       for(int i=0;i<vis.size();i++){
        if(!vis[i])helper_dfs(g,vis,stk,i);
       }
        vector<int>res;
    while(!stk.empty()){
        res.push_back(stk.top());
        stk.pop();
    }
    return res;


    }   
};




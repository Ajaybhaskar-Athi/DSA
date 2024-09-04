/*
Given a directed acyclic graph ,return all paths from 0 to node n-1;
*/
#include<bits/stdc++.h>
using namespace std;
    void helper(vector<vector<int>>&g,vector<vector<int>>&res,vector<int>&vis,vector<int>currPath,int node){
        int n=g.size();
        if(node==n){
            res.push_back(currPath);
            return;
        }
        if(vis[node])return;
        vis[node]=1;
        for(int nbr:g[node]){
            currPath.push_back(nbr);
            helper(g,res,vis,currPath,nbr);
            currPath.pop_back();
        }
        vis[node]=0;

    }

vector<vector<int>> FindAllpaths(vector<vector<int>>&g){
    vector<int>vis(g.size(),0);
    vector<int>currPath;
    vector<vector<int>>ans;

    currPath.push_back(0);//traversing from 0 node
        helper(g,ans,vis,currPath,0);
        return ans;   
}
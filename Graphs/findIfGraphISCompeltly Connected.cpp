#include<bits/stdc++.h>
using namespace std;

    void dfs(vector<vector<int>>g,vector<int>&vis,int src,int &c){
        vis[src]=1;
        c++;
        for(int nbr:g[src]){
            if(!vis[nbr])dfs(g,vis,nbr,c);
        }
        return;
    }

bool isConnected(vector<vector<int>>g){
    vector<int>vis(g.size(),0);
    int c=0;
    dfs(g,vis,0,c);
    return c==g.size();//if no of elemets in a graph is equals to given size then all vertices are conencted to each other and they are completly connected
    //if not equal then some where there is no edge between two vertices

}
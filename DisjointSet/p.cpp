#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    public:
    vector<int>rank,parent,size;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
    }

    int findUParent(int u){

        if(u==parent[u])return u;
        return parent[u]=findUParent(parent[u]);
    }

    void unionByRank(int u,int v){

        int ulPu=findUParent(u);
        int ulPv=findUParent(v);

        if(ulPu==ulPv)return;

        if(rank[ulPu]<rank[ulPv]){
            parent[ulPu]=parent[ulPv];
        }
        else if(rank[ulPv]<rank[ulPu]){
            parent[ulPv]=ulPu;
        }
        else{
            parent[ulPu]=ulPv;
            rank[ulPv]++;
        }
    }


    void unionBySize(int u,int v){
        int ulPu=findUParent(u);
        int ulPv=findUParent(v);

        if(ulPu==ulPv)return;

        if(size[ulPu]<size[ulPv]){
            parent[ulPu]=parent[ulPv];
            size[ulPv]+=size[ulPu];
        }
        else {
            parent[ulPv]=ulPu;
            size[ulPu]+=size[ulPv];
        }
    }
};
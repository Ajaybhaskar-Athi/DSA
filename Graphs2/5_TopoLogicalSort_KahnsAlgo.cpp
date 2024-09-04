#include<bits/stdc++.h>
using namespace std;

vector<int> kahnsAlgo_TopoSort(vector<vector<int>>&g){

        queue<int>q;
        vector<int>indeg(g.size(),0);
        for(int i=0;i<g.size();i++){
            for(int nbr:g[i]){
                indeg[nbr]++;
            }
        }

        for(int ele:indeg){
            if(ele==0)q.push(ele);
        }
        vector<int>topo;
        while(!q.empty()){ //There is Atleast One node with indegree 0 since it is a DAG
            int node=q.front();
            q.pop();
             topo.push_back(node);   //add these node to result topo
             //node is in ur topo Sso Remove it from indeg 
            for(int nbr:g[node]){
                indeg[nbr]--;
                if(indeg[nbr]==0)q.push(nbr);
            }
        }
        return topo;

}

T
/*There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.

 

Example 1:


Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
Output: true
Explanation: There are two paths from vertex 0 to vertex 2:
- 0 → 1 → 2
- 0 → 2
Example 2:


Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
Output: false
Explanation: There is no path from vertex 0 to vertex 5.
 

Constraints:

1 <= n <= 2 * 105
0 <= edges.length <= 2 * 105
edges[i].length == 2
0 <= ui, vi <= n - 1
ui != vi
0 <= source, destination <= n - 1
There are no duplicate edges.
There are no self edges.


*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool helper_dfs(vector<vector<int>>&g,vector<int>&vis,int src,int des){
        if(src==des)return true;
        vis[src]=1;
        for(int i=0;i<g[src].size();i++){
            if(!vis[g[src][i]]){
             if(helper_dfs(g,vis,g[src][i],des))return true;
        }
        }
        return false;
    }

    //just doing bfs also
    bool helper_bfs(vector<vector<int>>&g,vector<int>&vis,int src,int des){
        queue<int>q;
        q.push(src);
        vis[src]=1;
        while(!q.empty()){
            int now=q.front();
            q.pop();
            if(now==des)return true;
            for(int i=0;i<g[now].size();i++){
                if(!vis[g[now][i]]){
                    q.push(g[now][i]);
                    vis[g[now][i]]=1;
                }
            }
        }
        return false;
    }


    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>vis(n,0);
        vector<vector<int>>g(n); //build a graph with given edges
        //  edges = [[0,1],[0,2],[3,5],[5,4],[4,3]],

        for(auto v:edges){
                g[v[0]].push_back(v[1]);
                g[v[1]].push_back(v[0]);
            
        }
        return helper_dfs(g,vis,source,destination);   
    }
};




/*
Yes, an undirected graph can be considered a bidirectional graph. 

In graph theory, an undirected graph is a graph in which edges have no orientation; 
the edges do not have a direction, meaning if there is an edge between two vertices \( u \) and \( v \),
 you can traverse it in both directions (from \( u \) to \( v \) and from \( v \) to \( u \)). 
 This is equivalent to saying that the graph is bidirectional, as each edge inherently allows movement in both directions 
 between the connected vertices.*/

 
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> make_list(){
    int n,e;
    cout<<"Enter the no of nodes and edges the graph have: ";
    cin>>n>>e;
    vector<vector<int>>g(n);
    for(int i=0;i<e;i++){
        cout<<"Enter Nodes With direct Edges: ";
        int a,b;
        cin>>a>>b;
        if( a<n && b<n){
            g[a].push_back(b);
            g[b].push_back(a);
        }
    }
    return g;
}
//Traversal

void helper_dfs(vector<vector<int>>&g,int src,vector<int>&vis){
    vis[src]=1;
    cout<<src<<endl;
    for(int i=0;i<g[src].size();i++){
        if(!vis[g[src][i]])helper_dfs(g,g[src][i],vis);
    }
    return;
}
void print_dfs(vector<vector<int>>&g){
    vector<int>vis(g.size(),0);
    helper_dfs(g,0,vis);
    return;
}

void   helper_bfs(vector<vector<int>>&g,int src,vector<int>&vis){
    queue<int>q;
    q.push(src);
    vis[src]=1;
    while(!q.empty()){
        int f=q.front();
        q.pop();
        cout<<f<<endl;
        for(int i=0;i<g[f].size();i++){
            if(!vis[g[f][i]]){
                q.push(g[f][i]);
                vis[g[f][i]]=1;
            }
        }
    }
    return;

}
void print_bfs(vector<vector<int>>&g){
    vector<int>vis(g.size(),0);
    helper_bfs(g,0,vis);
}





int main(){
    vector<vector<int>>g=make_list();
    print_dfs(g);
    cout<<"Next BFS"<<endl;
    print_bfs(g);
}



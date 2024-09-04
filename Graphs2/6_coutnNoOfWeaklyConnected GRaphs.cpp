/*
Steps to Find Weakly Connected Components
Convert the Directed Graph to an Undirected Graph: Create an undirected version of the directed graph by ignoring the direction of edges.
Perform DFS or BFS on the Undirected Graph: Use Depth-First Search (DFS) or Breadth-First Search (BFS) to explore the graph and count the number of connected components.*/



/*A weakly connected component of a directed graph is a subgraph in which all nodes are connected when the direction 
of edges is ignored. In other words, if you replace all directed edges with undirected edges, you can traverse between 
any pair of nodes in the component.*/



#include <bits/stdc++.h>
using namespace std;

// Function to perform DFS on the graph
void dfs(vector<vector<int>>& g, vector<int>& visited, int node) {
    visited[node] = 1;
    for (int neighbor : g[node]) {
        if (!visited[neighbor]) {
            dfs(g, visited, neighbor);
        }
    }
}

// Function to convert the directed graph to an undirected graph
vector<vector<int>> convertToUndirected(vector<vector<int>>& g) {
    int n = g.size();
    vector<vector<int>> undirectedGraph(n);
    for (int i = 0; i < n; ++i) {
        for (int neighbor : g[i]) {
            undirectedGraph[i].push_back(neighbor);
            undirectedGraph[neighbor].push_back(i);
        }
    }
    return undirectedGraph;
}

// Function to count the number of weakly connected components in the directed graph
int countConnectedComponents(vector<vector<int>>& g) {
    int n = g.size();
    vector<int> visited(n, 0);
    vector<vector<int>> undirectedGraph = convertToUndirected(g);
    int count = 0;
    
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            ++count;
            dfs(undirectedGraph, visited, i);
        }
    }
    return count;
}

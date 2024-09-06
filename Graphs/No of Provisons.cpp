/*There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.



Example 1:


Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Example 2:


Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
 */

#include <bits/stdc++.h>
using namespace std;

// SIMPLY THEY ARE ASKING NO OF CONNECTED COMPONENTS

class Solution
{
public:
    void make_adjacencyList(vector<int> adj[], vector<vector<int>> isConnected, int n)
    {
        for (int i = 0; i < n; i++)
        { // nodes are always taken from 0 to n-1 if they are given from 1 to n
            // untill and unless they ask to print the elements we take from o to n-1 as nodes
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] && i != j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        // if we want to make changes in adj list and not refelcted in original then we write vector<vecto<int>>adj for the same list no problem
    }

    void dfs(vector<int> adj[], vector<int> &vis, int node)
    {
        vis[node] = 1;
        for (int ele : adj[node])
        {
            if (!vis[ele])
            {
                dfs(adj, vis, ele);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<int> adj[n]; // making array of vectors i.e,, adjacency list from given adjacency matrix
        // same as vector<vector<int>> g

        make_adjacencyList(adj, isConnected, n);

        vector<int> vis(n, 0);
        int count = 0; // no of connected components

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(adj, vis, i); // after iterating this graph and making visited nodes true and count
                count++;
            }
        }
        return count;
    }
};
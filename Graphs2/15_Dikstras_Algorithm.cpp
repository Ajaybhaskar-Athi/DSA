/*

Given a weighted, undirected and connected graph of V vertices and an adjacency list adj
where adj[i] is a list of lists containing two integers where the first integer of each list j denotes
there is edge between i and j , second integers corresponds to the weight of that  edge . You are given the source vertex S
and You to Find the shortest distance of all the vertex's from the source vertex S. You have to return a list of integers denoting shortest distance between each node and Source vertex S.


Note: The Graph doesn't contain any negative weight cycle.



Example 1:

Input:
V = 2
adj [] = {{{1, 9}}, {{0, 9}}}
S = 0
Output:
0 9
Explanation:

The source vertex is 0. Hence, the shortest
distance of node 0 is 0 and the shortest
distance from node 1 is 9.


Example 2:

Input:
V = 3, E = 3
adj = {
 {{1, 1}, {2, 6}},
 {{2, 3}, {0, 1}},
 {{1, 3}, {0, 6}}

 }
S = 2
Output:
4 3 0
Explanation:

For nodes 2 to 0, we can follow the path-
2-1-0. This has a distance of 1+3 = 4,
whereas the path 2-0 has a distance of 6. So,
the Shortest path from 2 to 0 is 4.
The shortest distance from 0 to 1 is 1 .


Your Task:
You don't need to read input or print anything. Your task is to complete the function dijkstra()  which takes the number of vertices V and an adjacency list adj as input parameters and Source vertex S returns a list of integers, where ith integer denotes the shortest distance of the ith node from the Source node. Here adj[i] contains a list of lists containing two integers where the first integer j denotes that there is an edge between i and j and the second integer w denotes that the weight between edge i and j is w.



Expected Time Complexity: O(V2).
Expected Auxiliary Space: O(V2).


 */

#include <bits/stdc++.h>
using namespace std;

// array of 2d matrices


vector<int> SingleSourseShortestPath(vector<vector<int>> adj[], int n, int src)
{
    vector<int> dis(n, INT_MAX);
    vector<int> vis(n, 0); // even if we dont use this not a problem BUT wheneber it gets a visited node again it will do operations again
                           // But already we marked that visited node with smallest distance so not chnaged .
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dis[src] = 0; // distance from src to src is 0
    vis[src] = 1;
    pq.push(make_pair(0, src)); //{cost,node}
    while (!pq.empty())
    {
        auto f = pq.top();
        pq.pop();
        int curr_cost = f.first;
        int node = f.second;

        for (auto it : adj[node])
        {
            int nbr = it[0];
            int cost = it[1];
            int d = curr_cost + cost;
            if(!vis[nbr]){
                if(d<dis[nbr]){
                    dis[nbr]=d;
                }
                pq.push({dis[nbr],nbr});
                vis[nbr]=1;
            }
            else if(d<dis[nbr]){ //not visited but smaller distance we get
                dis[nbr]=d;
                pq.push({d,nbr});
                }
        }
    }

    return dis;
}


int main(){


   vector<vector<int>> adj[3] = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}};
       vector<int>res= SingleSourseShortestPath(adj,3,2);
    for(int ele:res){
        cout<<ele<<" ";
    }

}


/*
if you use a visited vector, you ensure that once a node's shortest distance is determined, it doesn't need to be revisited. This guarantees that the node's shortest path weight is fixed and won't be updated again, which is correct and efficient for Dijkstra's algorithm.*/
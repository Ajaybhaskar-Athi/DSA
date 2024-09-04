#include <bits/stdc++.h>
using namespace std;

//no need of visited vector also 

vector<int> SingleSourceShortestPath(vector<vector<pair<int, int>>> &adj, int n, int src) {
    vector<int> dis(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dis[src] = 0; // Distance from src to src is 0
    pq.push({0, src}); // {cost, node}

    while (!pq.empty()) {
        int curr_cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto &it : adj[node]) {
            int nbr = it.first;
            int cost = it.second;
            int d = curr_cost + cost;
            if (d < dis[nbr]) {
                dis[nbr] = d;
                pq.push({d, nbr});
            }
        }
    }

    return dis;
}

int main() {
    vector<vector<pair<int, int>>> adj = {
        {{1, 1}, {2, 6}},
        {{2, 3}, {0, 1}},
        {{1, 3}, {0, 6}}
    };
    
    vector<int> res = SingleSourceShortestPath(adj, 3, 0);
    for (int ele : res) {
        cout << ele << " ";
    }

    return 0;
}

#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    void createGraph(vector<vector<int>>& times, vector<vector<pair<int, int>>>& g) {
        for (vector<int> v : times) {
            int a = v[0];
            int b = v[1];
            int w = v[2]; //weight of a->b edge
            g[a].push_back({b, w}); // a->b edge
        }
        return;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> g(n + 1); // 1-based indexing
        createGraph(times, g);
        return minTime(g, n, k);
    }

    int minTime(vector<vector<pair<int, int>>>& g, int n, int src) {
        vector<int> dis(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dis[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto f = pq.top();
            pq.pop();
            int node = f.second;
            int curr_cost = f.first;
            
            if (curr_cost > dis[node]) continue; // skip if this cost is not the latest for this node

            for (auto it : g[node]) {
                int nbr = it.first;
                int cost = it.second;
                int d = curr_cost + cost;
                if (d < dis[nbr]) {
                    dis[nbr] = d;
                    pq.push({d, nbr});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (dis[i] == INT_MAX) return -1;
            ans = max(ans, dis[i]);
        }
        return ans;
    }
};

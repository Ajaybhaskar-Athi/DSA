/*
As we already know kashns algo is used for topo sort . it proceess all the nodes and making indeg to zero since thers no cycle in DAG.
so i can say if that processed nodes count is not equal to grapgh size then there is a CYCLE exists

*/


#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    bool hasCycle(const vector<vector<int>>& g) {
        int n = g.size();
        vector<int> indegree(n, 0);

        // Calculate in-degrees for each node
        for (int i = 0; i < n; ++i) {
            for (int nbr : g[i]) {
                indegree[nbr]++;
            }
        }

        // Queue for nodes with no incoming edges
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Number of nodes processed
        int count = 0;

        // Process nodes in topological order
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            for (int nbr : g[node]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        // If count of processed nodes is not equal to n, there is a cycle
        return count != n;
    }
};

// Example usage:
int main() {
    Solution sol;
    vector<vector<int>> graph = {
        {1},    // 0 -> 1
        {2},    // 1 -> 2
        {3},    // 2 -> 3
        {0}     // 3 -> 0, this creates a cycle
    };
    bool result = sol.hasCycle(graph);
    cout << (result ? "Graph has a cycle" : "Graph doesn't have a cycle") << endl;
    return 0;
}

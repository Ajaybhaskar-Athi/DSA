#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<int> res;

        // Build the graph and calculate in-degrees
        for (auto& v : prerequisites) {
            int a = v[0];
            int b = v[1];
            g[b].push_back(a); // Directed edge from b to a
            indegree[a]++;
        }

        // Queue for nodes with no incoming edges
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Process nodes in topological order
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for (int nbr : g[node]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        // If we processed all nodes, return the result; otherwise, there's a cycle
        if (res.size() == numCourses) {
            return res;
        } else {
            return {};
        }
    }
    
};

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> make_list() {
    int n, e;
    cout << "Enter the number of nodes and edges the graph has: ";
    cin >> n >> e;
    vector<vector<int>> g(n);
    for (int i = 0; i < e; i++) {
        cout << "Enter Nodes With directed Edges (from -> to): ";
        int a, b;
        cin >> a >> b;
        if (a < n && b < n) {
            g[a].push_back(b);
        } else {
            cout << "Invalid edge. Node indices should be less than " << n << ".\n";
        }
    }
    return g;
}

int main() {
    vector<vector<int>> graph = make_list();

    // Display the adjacency list of the directed graph
    cout << "Adjacency List of the Directed Graph:\n";
    for (int i = 0; i < graph.size(); i++) {
        cout << i << ": ";
        for (int j : graph[i]) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}

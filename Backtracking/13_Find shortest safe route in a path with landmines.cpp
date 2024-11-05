#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int checkSafe(int i, int j, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int up = 1, down = 1, left = 1, right = 1;
        
        if (i - 1 >= 0) up = mat[i - 1][j];
        if (i + 1 < n) down = mat[i + 1][j];
        if (j - 1 >= 0) left = mat[i][j - 1];
        if (j + 1 < m) right = mat[i][j + 1];
        
        return (mat[i][j] && up && down && left && right);
    }
    
    void solve(int row, int col, int curr_dist, int &dist, vector<vector<int>>& isSafe, vector<vector<bool>>& visited) {
        int n = isSafe.size();
        int m = isSafe[0].size();
        
        if (col == m ) {  // Reached the last column
            dist = min(curr_dist, dist);
            return;
        }
        
        if (row < 0 || row >= n || col < 0 || col >= m || !isSafe[row][col] || visited[row][col]) return;

        // Mark the cell as visited in this path
        visited[row][col] = true;
        
        // Explore four directions
        solve(row + 1, col, curr_dist + 1, dist, isSafe, visited);  // Down
        solve(row - 1, col, curr_dist + 1, dist, isSafe, visited);  // Up
        solve(row, col - 1, curr_dist + 1, dist, isSafe, visited);  // Left
        solve(row, col + 1, curr_dist + 1, dist, isSafe, visited);  // Right
        
        // Unmark the cell as visited for other paths
        visited[row][col] = false;
    }

    int findShortestPath(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> isSafe(n, vector<int>(m, 0));  // Initialize isSafe with dimensions
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                isSafe[i][j] = checkSafe(i, j, mat);
            }
        }
        
        int ans = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            int dist = INT_MAX;
            if (isSafe[i][0]) {
                vector<vector<bool>> visited(n, vector<bool>(m, false));  // Track visited cells for each path
                solve(i, 0, 0, dist, isSafe, visited);
                if (dist != INT_MAX) ans = min(ans, dist);
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};



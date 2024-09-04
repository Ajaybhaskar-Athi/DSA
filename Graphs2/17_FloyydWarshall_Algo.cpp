/*
The problem is to find the shortest distances between every pair of vertices in a given edge-weighted directed graph. The graph is represented as an adjacency matrix of size n*n. Matrix[i][j] denotes the weight of the edge from i to j. If Matrix[i][j]=-1, it means there is no edge from i to j.
Do it in-place.

Example 1:

Input: matrix = {{0,25},{-1,0}}

Output: {{0,25},{-1,0}}

Explanation: The shortest distance between
every pair is already given(if it exists).
Example 2:

Input: matrix = {{0,1,43},{1,0,6},{-1,-1,0}}

Output: {{0,1,7},{1,0,6},{-1,-1,0}}

Explanation: We can reach 2 from 0 as 0->1->2
and the cost will be 1+6=7 which is less than 
43.
Your Task:
You don't need to read, return or print anything. Your task is to complete the function shortest_distance() which takes the matrix as input parameter and modifies the distances for every pair in-place.

Expected Time Complexity: O(n3)
Expected Space Complexity: O(1)

Constraints:
1 <= n <= 100
-1 <= matrix[ i ][ j ] <= 1000
*/




#include<bits/stdc++.h>
using namespace std;

//TC=O(n*3);



class Solution {
  public:
void All_Nodes_Shortest_path(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Initialize the distance matrix
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j] == -1) {
                    matrix[i][j] = INT_MAX; // Treat -1 as infinity
                }
                if(i == j) {
                    matrix[i][j] = 0; // Distance to self is zero
                }
            }
        }
        
        // Floyd-Warshall algorithm
        for(int k = 0; k < n; ++k) {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(matrix[i][k] != INT_MAX && matrix[k][j] != INT_MAX) {
                        if(matrix[i][j] > matrix[i][k] + matrix[k][j]) {
                            matrix[i][j] = matrix[i][k] + matrix[k][j];
                        }
                    }
                }
            }
        }
        
        // Convert back INT_MAX to -1 for no path
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j] == INT_MAX) {
                    matrix[i][j] = -1;
                }
            }
        }
    }

};

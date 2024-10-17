#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N) {
        // Sort the horizontal costs in reverse order
        sort(X.rbegin(), X.rend());
        // Sort the vertical costs in reverse order
        sort(Y.rbegin(), Y.rend());

        int res = 0;
        int hzntl = 1, vert = 1; // Start with one horizontal and one vertical piece

        // Initialize indices for horizontal and vertical cuts
        int i = 0, j = 0;

        // Process the cuts while both arrays have elements
        while (i < M && j < N) {
            if (X[i] > Y[j]) {
                res += X[i] * vert; // Add cost of horizontal cut
                hzntl++; // Increment the number of horizontal pieces
                i++; // Move to the next horizontal cut
            } else {
                res += Y[j] * hzntl; // Add cost of vertical cut
                vert++; // Increment the number of vertical pieces
                j++; // Move to the next vertical cut
            }
        }

        // Add remaining horizontal cuts
        while (i < M) {
            res += X[i] * vert; // Each remaining horizontal cut affects all vertical pieces
            i++;
        }

        // Add remaining vertical cuts
        while (j < N) {
            res += Y[j] * hzntl; // Each remaining vertical cut affects all horizontal pieces
            j++;
        }

        return res; // Return the total minimum cost
    }
};

int main() {
    // Input
    int m = 5, n = 9;
    vector<int> X = {6, 11, 18, 15}; // Horizontal cut costs
    vector<int> Y = {5, 18, 6, 3, 6, 1, 2, 2}; // Vertical cut costs

    // Create an instance of the Solution class
    Solution sol;
    
    // Call the function and print the result
    int result = sol.minimumCostOfBreaking(X, Y, m - 1, n - 1);
    cout << "Minimum Cost of Breaking: " << result << endl; // Expected output: 243

    return 0;
}

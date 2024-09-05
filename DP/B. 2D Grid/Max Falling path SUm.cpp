// leetcode

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int helper(int i, int j, vector<vector<int>> &g, vector<vector<int>> &dp)
    {
        int n = g.size(), m = g[0].size();
        if (j < 0 || j >= n)
            return INT_MAX;
        if (i == n - 1)
            return g[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        int down = helper(i + 1, j, g, dp);
        int dRight = helper(i + 1, j + 1, g, dp);
        int dLeft = helper(i + 1, j - 1, g, dp);
        return g[i][j] + min({down, dRight, dLeft});
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int ans = INT_MAX;
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int i = 0; i < matrix.size(); i++)
        {
            ans = min(ans, helper(0, i, matrix, dp));
        }
        return ans;
    }
};

// tabuilation
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int j = 0; j < n; j++)
        {
            dp[n - 1][j] = matrix[n - 1][j];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            { // u can write j=0->n-1 also
                int down = dp[i + 1][j];
                int dl = j > 0 ? dp[i + 1][j - 1] : INT_MAX;
                int dr = j < n - 1 ? dp[i + 1][j + 1] : INT_MAX;
                dp[i][j] = matrix[i][j] + min({down, dl, dr});
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            ans = min(ans, dp[0][i]);
        }
        return ans;
    }
};

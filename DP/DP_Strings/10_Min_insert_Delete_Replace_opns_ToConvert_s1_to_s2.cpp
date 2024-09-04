//Edit Distance Leetcode 72
#include<bits/stdc++.h>
using namespace std;

//Memoisation
class Solution {
public:
    int helper(int i,int j,string s1,string s2,vector<vector<int>>&dp){
        if(i<0)return j+1;
        if(j<0)return i+1;
        if(s1[i]==s2[j])return dp[i][j]= helper(i-1,j-1,s1,s2,dp);
        //else condition
        int insert=1+helper(i,j-1,s1,s2,dp);
        int dlt=1+helper(i-1,j,s1,s2,dp);
        int replace=1+helper(i-1,j-1,s1,s2,dp);
        return dp[i][j]= min({insert,dlt,replace});

    }

    int minDistance(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        return helper(n-1,m-1,s1,s2,dp);
    }
};
// cur[j] = 1 + min(prev[j - 1], min(prev[j], cur[j - 1]));


//Tabulation


class Solution {
public:


    int minDistance(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
            for(int i=0;i<=n;i++)dp[i][0]=i;// Cost of converting word1[0..i] to an empty word2 is i deletions
            for(int j=0;j<=m;j++)dp[0][j]=j;// Cost of converting an empty word1 to word2[0..j] is j insertions
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(s1[i-1]==s2[j-1]) dp[i][j]= dp[i-1][j-1];
             else{
        int insert=1+dp[i][j-1];
        int dlt=1+dp[i-1][j];
        int replace=1+dp[i-1][j-1];
         dp[i][j]= min({insert,dlt,replace});
        }
                }
            }
        return dp[n][m];
    }
};



//SPACE OPTIMISATION

//Refer Striver page for explanation



#include <bits/stdc++.h>
using namespace std;

// Function to calculate the edit distance between two strings
int editDistance(string& S1, string& S2) {
    int n = S1.size();
    int m = S2.size();

    // Create two arrays to store previous and current row of edit distances
    vector<int> prev(m + 1, 0);
    vector<int> cur(m + 1, 0);

    // Initialize the first row
    for (int j = 0; j <= m; j++) {
        prev[j] = j;
    }

    // Calculate edit distances row by row
    for (int i = 1; i <= n; i++) {
        cur[0] = i; // Initialize the first column of the current row
        for (int j = 1; j <= m; j++) {
            if (S1[i - 1] == S2[j - 1]) {
                // If the characters match, no additional cost
                cur[j] = prev[j - 1];
            } else {
                // Minimum of three choices:
                // 1. Replace the character at S1[i-1] with S2[j-1]
                // 2. Delete the character at S1[i-1]
                // 3. Insert the character at S2[j-1] into S1
                cur[j] = 1 + min(prev[j - 1], min(prev[j], cur[j - 1]));
            }
        }
        prev = cur; // Update the previous row with the current row
    }

    // The value at cur[m] contains the edit distance
    return cur[m];
}

int main() {
    string s1 = "horse";
    string s2 = "ros";

    // Call the editDistance function and print the result
    cout << "The minimum number of operations required is: " << editDistance(s1, s2);
    return 0;
}




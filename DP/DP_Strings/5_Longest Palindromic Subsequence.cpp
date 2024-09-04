#include<bits/stdc++.h>
using namespace std;
        //longest palindrome subsequnce is nothing BUT longest common subsequce b/w s and reverse(s)

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        //longest palindrome subsequnce is nothing BUT longest common subsequce b/w s and reverse(s)
        string s1=s;
        string s2=s;
        reverse(s2.begin(),s2.end());
        int n=s1.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

        for(int i=0;i<=n;i++){
            dp[i][0]=0;
            dp[0][i]=0;
        }
        //why we need to use for loop write directly this  vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=0+max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];

    }
};


/*
But the same longest coomon SUBSTRING b/w s and reverse(S) cant be a palindrome 
*/
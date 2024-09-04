#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
//Leetcode 1312


    int minInsertions(string s) {

        int n=s.size();
        int len=longestPalindromeSubseq(s);//length of longest palindrome subsequence
        return n-len;//if we copy paste reverse or any arrangement of charaters that are  not part of LPS then it became a palindrome;
   
    }



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


//this is the same answer even for MINIMUM NO OF DELETIONS TO make a string PALINDROME
#include<bits/stdc++.h>
using namespace std;


///this single problem will be used in evry DP_String problems i wrote in this folder

// /Recursion  TC=o(2^(n1+n2));
class Solution {
public:
    int helper(int idx1,int idx2,string s1,string s2){
        if(idx1<0 || idx2<0)return 0;
        if(s1[idx1]==s2[idx2])return 1+helper(idx1-1,idx2-1,s1,s2);
        else{
            return 0+max(helper(idx1-1,idx2,s1,s2), helper(idx1,idx2-1,s1,s2));
        }

    }
    int longestCommonSubsequence(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        return helper(n1-1,n2-1,s1,s2);
    }
};



//Memoisation
//TC=O(n1*n2); SC=Space Complexity: O(N*M) + O(N+M)

class Solution {
public:
    int helper(int idx1,int idx2,string s1,string s2,vector<vector<int>>&dp){
        if(idx1<0 || idx2<0)return  0;
        if(dp[idx1][idx2]!=-1)return dp[idx1][idx2];
        if(s1[idx1]==s2[idx2]) return dp[idx1][idx2]= 1+helper(idx1-1,idx2-1,s1,s2,dp);
        else{
         return dp[idx1][idx2]= 0+max(helper(idx1-1,idx2,s1,s2,dp), helper(idx1,idx2-1,s1,s2,dp));
        }

    }
    int longestCommonSubsequence(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return helper(n1-1,n2-1,s1,s2,dp);
    }
};

//Tabulation
//TC=O(n*m)  Space Complexity: O(N*M)


class Solution {
public:
 
    int longestCommonSubsequence(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        //base case if if(idx1<0 || idx2<0) return 0 but in arrays we cant set it. so move indexes by 1 to right. so -1 is 0 now and 0 is 1;
        for(int i=0;i<=n1;i++)dp[i][0]=0;
        for(int j=0;j<=n2;j++)dp[0][j]=0;
//without for loops assign all values initialyy to 0  vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s1[i-1]==s2[j-1])dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=0+max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return dp[n1][n2];
    }
};





#include<bits/stdc++.h>
using namespace std;


// METHOD 1: Recursion 
// TC=O(2^n) and sc=o(1)
class Solution {
public:
    int fib(int n) {
        if(n<=1)return n;
        return fib(n-1)+fib(n-2);
    }
};


// Method 2: DP memoriization (Top-down dp)
// TC=O(n) and sc=O(n) ;2
class Solution {
public:
    int fibb(int n,vector<int>&dp) {
        if(n<=1)return n;
    if(dp[n]!=-1)return dp[n];
return dp[n]=fibb(n-1,dp)+fibb(n-2,dp);  
  }
};



// Method 3: DP Tabular (Bottom-up)
// TC=O(n) and sc=O(1);
class Solution {
public:
    int fib(int n) {
       
        int prev=1;
        int prev2=0;
        if(n<=1)return n;
        for(int i=2;i<=n;i++){
            int curr=prev+prev2;
            prev2=prev;
            prev=curr;
        }
      return prev;
    }
};


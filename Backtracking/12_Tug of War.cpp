#include<bits/stdc++.h>
using namespace std;



    int helper(int idx,int added,int curr_s,int sum,vector<int>&arr){
        int n=arr.size();

        if(added==n/2) {
                int remSum=abs(sum-curr_s);
                return abs(curr_s-remSum);
        }
          if (idx >= n) {  
        return INT_MAX;
    }
        int take=helper(idx+1,added+1,curr_s+arr[idx],sum,arr);
        int notTake=helper(idx+1,added,curr_s,sum,arr);
        return min(take,notTake);
    }



    int tugOfWar(vector<int> &arr,int n)
    {
    // write your code here
    int sum = accumulate(arr.begin(), arr.end(), 0);
        return helper(0,0,0,sum,arr);
    }



    //memoisation:

    #include <bits/stdc++.h> 

    int helper(int idx,int added,int curr_s,int sum,vector<int>&arr,vector<vector<int>>&dp){
        int n=arr.size();

        if(added==n/2) {
                int remSum=abs(sum-curr_s);
                return abs(curr_s-remSum);
        }
          if (idx >= n) {  
        return INT_MAX;
    }
    if(dp[added][curr_s]!=-1)return dp[added][curr_s];


        int take=helper(idx+1,added+1,curr_s+arr[idx],sum,arr,dp);
        int notTake=helper(idx+1,added,curr_s,sum,arr,dp);

        return dp[added][curr_s]= min(take,notTake);

    }


   int tugOfWar(vector<int>& arr, int n) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        vector<vector<int>> dp(n + 1, vector<int>(sum / 2 + 1, -1)); // Correctly initialized dp
        return helper(0, 0, 0, sum, arr, dp);
    }

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int idx,int prev,vector<int>&nums){
        int n=nums.size();
        if(idx==n)return 0;
        int notTake=0+helper(idx+1,prev,nums);
        int take=INT_MIN;
        if(prev==-1 || nums[idx]>nums[prev])take=1+helper(idx+1,idx,nums);
        return max(take,notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        return helper(0,-1,nums);
    }
};

class Solution {
public:
    int helper(int idx,int prev,vector<int>&nums){
        int n=nums.size();
        if(idx==n)return 0;
        int len=0+helper(idx+1,prev,nums); //notTake
        if(prev==-1 || nums[idx]>nums[prev])len=max(len,1+helper(idx+1,idx,nums)); //Take
        return  len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        return helper(0,-1,nums);
    }
};



//MEMOISATION

class Solution {
public:
    int helper(int idx,int prev,vector<int>&nums,vector<vector<int>>&dp){
        int n=nums.size();
        if(idx==n)return 0;
        if(dp[idx][prev+1]!=-1)return dp[idx][prev+1];
        int len=0+helper(idx+1,prev,nums,dp); //NotTake
        if(prev==-1 || nums[idx]>nums[prev])len=max(len,1+helper(idx+1,idx,nums,dp));//NotTake
        return dp[idx][prev+1]=len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return helper(0,-1,nums,dp);
    }
};
//Tabulation
//ip=[0,1,0,3,2,3]
class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=0;i<=n;i++)dp[n][i]=0;
        for(int ind=n-1;ind>=0;ind--){
            for(int prev=ind-1;prev>=-1;prev--){ //Using n-1 for prev would mean considering elements that come after the current ind, which doesn't make sense in the context of building an increasing subsequence because the subsequence must be built in a forward direction.
                int notTake=dp[ind+1][prev+1];
                int take=0;
                if( prev==-1 || nums[ind]>nums[prev]) take=1+dp[ind+1][ind+1]; //hee index+1 column since that was the previous when we taversing from last to front
                dp[ind][prev+1]=max(take,notTake);
            }
        }
        return dp[0][-1+1];
    }
};



//Space Optimisation


class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>next(n+1,0),curr(n+1,0);

        for(int ind=n-1;ind>=0;ind--){
            for(int prev=n-1;prev>=-1;prev--){
                int notTake=next[prev+1];
                int take=0;
                if( prev==-1 || nums[ind]>nums[prev]) take=1+next[ind+1];
                curr[prev+1]=max(take,notTake);
            }
            next=curr;
        }
        return curr[0];
    }
};




//Tabulation 2:

class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        for(int i=1;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[i]>nums[prev]){
                    dp[i]=max(dp[i],1+dp[prev]);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};

// TC=o(n*n)
// and sc=o(n) 

//same as tabulation BUT its Useful for Printing the LIS (backtracking The LIS)
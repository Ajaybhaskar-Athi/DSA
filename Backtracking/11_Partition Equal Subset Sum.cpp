#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
        bool helper(int idx,int t,int curr_s,vector<int>&nums,vector<vector<int>>&dp){
            if(t==curr_s)return true;
            if(idx==nums.size())return false;
            
            if(dp[idx][curr_s]!=-1)return dp[idx][curr_s];



           bool take= helper(idx+1,t,curr_s+nums[idx],nums,dp);
           bool notTake= helper(idx+1,t,curr_s,nums,dp);
           return dp[idx][curr_s]= take||notTake;
        }

    bool canPartition(vector<int>& nums) {

        int sum=0;
        for(int ele:nums)sum+=ele;
        if(sum%2!=0)return false;
        vector<vector<int>>dp(nums.size(),vector<int>(sum+1,-1));
        return helper(0,sum/2,0,nums,dp);



    }
};
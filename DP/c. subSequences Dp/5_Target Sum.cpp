#include<bits/stdc++.h>
using namespace std;


//Recursion 

class Solution {
public:

    int helper(int idx,vector<int>&nums,int T,int sum ){
        if(idx==-1){ //when zero elemnt added and go behind 0 
            if(sum==T)return 1;
            else return 0;
        }
    
        int positive=helper(idx-1,nums,T,sum+nums[idx]);
        int negative=helper(idx-1,nums,T,sum-nums[idx]);
        return positive+negative;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
         int n=nums.size();
         return helper(n-1,nums,target,0);
    }
};


//Memoisation 
class Solution {
public:
    int helper(int idx, vector<int>& nums, int T, int sum, unordered_map<string, int>& memo) {
        if (idx == -1) { // when zero element added and go behind 0 
            return sum == T ? 1 : 0;
        }
        
        // Create a unique key for memoization
        string key = to_string(idx) + "," + to_string(sum);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }
        int positive = helper(idx - 1, nums, T, sum + nums[idx], memo);
        int negative = helper(idx - 1, nums, T, sum - nums[idx], memo);
         return memo[key] = positive + negative;
    
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> memo;
        return helper(nums.size() - 1, nums, target, 0, memo);
    }
};






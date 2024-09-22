#include<bits/stdc++.h>
using namespace std;

//DP approcach (Not convenient : TC=O(n*n))
class Solution {
public:
    int helper(int idx, vector<int>& nums, vector<int>& dp) {
        if (idx >= nums.size() - 1) return 0;  // If reached the last index, return 0 (no more jumps needed)
        if (nums[idx] == 0) return INT_MAX;    // If stuck at index with no further jumps, return INT_MAX
        if (dp[idx] != -1) return dp[idx];     // If result already computed for this index, return it

        int ans = INT_MAX;
        for (int j = 1; j <= nums[idx]; j++) {
            int jump = helper(idx + j, nums, dp);
            if (jump != INT_MAX) {
                ans = min(ans, jump + 1);  // Increment the jump count
            }
        }
        return dp[idx] = ans;  // Store and return the result
    }

    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);  // 1D dp array, initialized with -1
        return helper(0, nums, dp);       // Call helper starting from index 0
    }
};




    //Greedy Algo (TC=o(n))

class Solution {
public:
    int jump(vector<int>& nums) {
        
        int jumps=0,l=0,r=0;
        
        while(r<nums.size()-1){
            int farthest=0;
            for(int i=l;i<=r;i++){
                farthest=max(farthest,i+nums[i]);
            }

            l=r+1;//move ahead of fathest
            r=farthest;//update the r
            jumps++;

        }
        return jumps;//when r reaches the last index;
    }
};



// #LeetCode 
/*
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100

*/



// same previous problem subset sum equlas target 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

bool f(int n,int target,vector<int>&arr){
    vector<vector<bool>>dp(n,vector<bool>(target+1,false));
    for(int i=0;i<n;i++) dp[i][0]=true;
    if(target>=arr[0]) dp[0][arr[0]]=true;

    for(int i=1;i<n;i++){

        for(int t=1;t<=target;t++){
            bool notTaken=dp[i-1][t];
            bool taken=false;
            if(t>=arr[i]){
                taken=dp[i-1][t-arr[i]];
            }
            dp[i][t]=taken||notTaken;
        }
    }

    return dp[n-1][target];
    

}


    bool canPartition(vector<int>& nums) {
        int totalSum=0;
        for(int ele:nums)totalSum+=ele;
        if(totalSum % 2)return false; //odd
        int target=totalSum/2;
    
        return f(nums.size(),target,nums);

    }
};
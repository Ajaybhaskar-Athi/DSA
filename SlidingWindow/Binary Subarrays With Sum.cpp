/*Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15
 */


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
     int helper(vector<int>nums,int k){
            if(k<0)return 0;
            int l=0,r=0,n=nums.size(),sum=0,count=0;
            while(r<n){
                sum+=nums[r];
                while(sum>k){
                    sum-=nums[l];
                    l++;
                }
                count=count+(r-l+1);
                r++;
            }
            return count;
        }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int x=helper(nums,goal); // NoOfSubArraysLessThanEqualsGoal
        int y=helper(nums,goal-1); //NoOfSubArraysLessThanGoalMinus1
        return x-y;
    }
};
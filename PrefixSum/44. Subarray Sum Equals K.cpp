Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 ////////////////////////////////

// Available in notes  explanation

////////////////////////////////////

 class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      // this is prefix sum method also written in notes
      int n=nums.size();
      int count=0,preSum=0;
      unordered_map<int,int>mp;//1st part is preSum and 2nd part is no of times it repeated
      mp[0]=1;//marking there is 1 subarray whose sum=0 which is {}

      for(int i=0;i<n;i++){
        preSum+=nums[i];
        int remove=preSum-k;
        count+=mp[remove];
        mp[preSum]+=1;
      }
      return count;

    }
};



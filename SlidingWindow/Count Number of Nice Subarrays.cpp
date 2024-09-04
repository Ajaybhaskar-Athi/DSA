//SIMILAR to Binary SUbArrays WIth Sum


/*Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There is no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

        //Similar to Binary subarrays with sum
        int helper(vector<int>nums,int k){
            if(k<0)return 0;
            int l=0,r=0,n=nums.size(),s=0,count=0;
            while(r<n){
                // sum+=nums[r];
                if(nums[r]%2==1)s++;
                while(s>k){
                  if(nums[l]%2==1)s--;
                    l++;
                }
                count=count+(r-l+1);
                r++;
            }
            return count;
        }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int x=helper(nums,k); // NoOfSubArraysLessThanEqualsKOddNumbers
        int y=helper(nums,k-1); //NoOfSubArraysLessThenKOddNumbers
        return x-y;
    }
};

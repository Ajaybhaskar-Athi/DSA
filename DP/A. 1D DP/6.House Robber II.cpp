/*You are a professional robber planning to rob houses along a street.
 Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. 
 That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, 
return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [1,2,3]
Output: 3
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000

*/

// same maximum sum of non adjacent elements but here extra is 1st ,last are also adjacent

// ans1=consider 1st house and dont robber last
// ans2=consider  last and dont robber 1st 
// return max(those two);


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

int f(int ind,vector<int>&arr){
        int prev=arr[0];
        int prev2=0;
        for(int i=1;i<ind;i++){
            int pick=arr[i];
            if(i>1) pick+=prev2;
        int notPick=prev;
        int curr_i=max(pick,notPick);
        prev2=prev;
        prev=curr_i;
        }

return  prev;
}
    int rob(vector<int>& arr) {
           int n=arr.size();
            if(n==1)return arr[0];

            vector<int>arr1; //considering 1st house to be robbed and not last
            vector<int>arr2;//last house to be robbed and  not 1st house
            for(int i=0;i<n;i++){
                if(i!=n-1)arr1.push_back(arr[i]);
                if(i!=0)arr2.push_back(arr[i]);
            }

            int res1=f(arr1.size(),arr1);
            int res2=f(arr2.size(),arr2);
            return max(res1,res2);
    }
};

//Same code 
class Solution {
public:
        int helper(vector<int>&nums){
        vector<int>dp(nums.size(),-1);
        int n=nums.size();
                dp[0]=nums[0];
                for(int i=1;i<n;i++){
                    int notTake=dp[i-1];
                    int take=nums[i];
                    if(i>1)take+=dp[i-2];
                    dp[i]=max(take,notTake);
                }
                return dp[n-1];
        }
    int rob(vector<int>& nums) {
            vector<int>v1,v2;//v1 is 1st included and v2 is 2nd included
            int n=nums.size();
            if(n==1)return nums[0];
            for(int i=0;i<n;i++){
                if(i!=0)v2.push_back(nums[i]);
                if(i!=n-1)v1.push_back(nums[i]);
            }
            return max(helper(v1),helper(v2));
    }
};

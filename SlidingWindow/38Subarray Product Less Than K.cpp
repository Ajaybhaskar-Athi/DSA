Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

 

Example 1:

Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
Example 2:

Input: nums = [1,2,3], k = 0
Output: 0
 


//  SLIDING WINDOW METHOD  || Two pointer method

#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& arr, int k) {
        int left=0,right=0;
        int n=arr.size();
        int p=1,count=0;
        if(k<=1)return 0;
        while(right<n){
            p*=arr[right];
            while(p>=k){
                p/=arr[left];
                left++;
            }
            count+=right-left+1;
            right++;
        }
        return count;
    }
};
// auto init = []()

// { 
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     return 'c';
// }();


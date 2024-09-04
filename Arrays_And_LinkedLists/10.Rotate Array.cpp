/*Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
*/



#include<bits/stdc++.h>
using namespace std;

 void rev(vector<int>&arr,int s,int e){
       while(s<e){
        swap(arr[s],arr[e]);
        s++;e--;
       }
    }
    void rotate(vector<int>& nums, int k) {
        int m=k%nums.size();
        if(m==0) return;
       rev(nums,0,nums.size()-1);//revrse the entire array
       rev(nums,0,m-1);//reverse first k elemnts
       rev(nums,m,nums.size()-1);
    }
   
    int main(){
        vector<int>v={1,2,3,4,5,6,7};
        rotate(v,9);
        for(int e:v)cout<<e<<" ";
    }

// tc=O(n)

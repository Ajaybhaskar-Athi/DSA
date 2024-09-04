// Not a leetcode one

Test Case 1:

Input: v = [1, 2, 3, 4, 5], k = 9
Expected Output: 2
Explanation: The subarray [4, 5] has a sum of 9, which is the longest subarray with a sum equal to 'k'.
Test Case 2:

Input: v = [1, 4, 20, 3, 10, 5], k = 33
Expected Output: 3
Explanation: The subarray [20, 3, 10] has a sum of 33, which is the longest subarray with a sum equal to 'k'.
Test Case 3:

Input: v = [5, 10, 15, 20], k = 15
Expected Output: 1
Explanation: The subarray [15] has a sum of 15, which is the longest subarray with a sum equal to 'k'.




#include<bits/stdc++.h>
using namespace std;
int SubArrayLen(vector<int>&v,int k){
    int left=0,right=0,maxlen=0,n=v.size();
int sum=0;
    while(right<n){
        
        while( left<=right && sum>k){
        sum-=v[left++];
        }
        if(sum==k){
            maxlen=max(maxlen,right-left+1);
        }
        sum+=v[right];
        right++;
    }
    return maxlen;
}




/*Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 

*/


/*
As array consists only 0's,1's . we need to find the subarray with max length that has zeroes equal to k so thta we can replace them 
with 1's 

*/


#include<bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>&v,int k){
    int n=v.size();
    int i=0,j=0,z=0;
    int len=0;
    while(j<n){
        if(v[j]==0)z++;
        while(z>k){
            if(v[i]==0)z--;
            i++;
        }
        len=max(len,j-i+1);
        j++;
    }
    return len;
    
}
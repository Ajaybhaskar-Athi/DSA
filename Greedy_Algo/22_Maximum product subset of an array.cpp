//GFG

#include<bits/stdc++.h>
using namespace std;

//using DP 
//But it take O(2^n) even after memoisation bcoz there no overlapping problems occur here 
//theres no repetition of product at same index agian
//so solving this in DP not make Sense

class Solution {
  public:
        
        void helper(int idx,int prod,int & max_prod,vector<int>&arr){
                if(idx<0)return;
                helper(idx-1,prod,max_prod,arr);    
            max_prod=max(max_prod,prod*arr[idx]);
           helper(idx-1,prod*arr[idx],max_prod,arr);
        
        }
  
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        int prod=1;
        int max_prod=INT_MIN;
         helper(arr.size()-1,prod,max_prod,arr);
         return max_prod;
    }
};


//using Greedy
//TC=O(n)

/*


The idea is to count the occurrence of positive and negative elements 
If there are even number of negative numbers and no zeros, the result is simply the product of all
If there are odd number of negative numbers and no zeros,then the result is the product of all except the negative integer with the least absolute value.
If there are zeros, the result is the product of all except these zeros with one exceptional case.
 The exceptional case is when there is one negative number and all other elements are 0. In this case, the result is 0.*/

class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];

        int max_neg = INT_MIN;
        int count_neg = 0, count_zero = 0;
        long long prod = 1;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                count_zero++;
                continue;
            }
            if (arr[i] < 0) {
                count_neg++;
                max_neg = max(max_neg, arr[i]);
            }
            prod *= arr[i];
        }

        if (count_zero == n) return 0;

        if (count_neg & 1) {
            if (count_neg == 1 && count_zero > 0 && count_zero + count_neg == n)
                return 0;

            prod /= max_neg;
        }

        return prod;
    }
};
#include<bits/stdc++.h>
using namespace std;
/**
 * this is based on LIS
 * if we sort the array and do the same LIS with Divisbility Logic , it is perfect
 * tc=o(n**2)
 *  */   
   
    class Solution {
    public:
            //longest increase subsequnce logic
        vector<int> largestDivisibleSubset(vector<int>& nums) {
                sort(nums.begin(),nums.end());
                int n=nums.size();
                vector<int>dp(n,1),hash(n);
                hash[0]=0;
                int lastIndex=0;
                int maxi=1;//every elemnt is dvided by itself
                for(int i=1;i<n;i++){
                    hash[i]=i;
                    for(int prev=0;prev<i;prev++){
                        if(nums[i]%nums[prev]==0){
                            if(1+dp[prev]>dp[i]){
                                dp[i]=1+dp[prev];
                                hash[i]=prev;
                            }
                        }
                    }
                    if(dp[i]>maxi){
                        maxi=dp[i];
                        lastIndex=i;
                    }
                }


                vector<int>LDS;
            LDS.push_back(nums[lastIndex]);
            while(hash[lastIndex]!=lastIndex){
                lastIndex=hash[lastIndex];
                LDS.push_back(nums[lastIndex]);

            }
            reverse(LDS.begin(),LDS.end());
            return LDS;
        }
    };
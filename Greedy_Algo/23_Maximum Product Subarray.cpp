#include<bits/stdc++.h>
using namespace std;
//leetcode
//Refer striver sheet 


/*
whenever there are odd negative eles in array then by removing single negative will make our entire array into two sub arrays

And we find max among them 
thats why we r using suffix and prefix ;


*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre=1,suff=1,n=nums.size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            if(pre==0)pre=1;//if prefix product=0 means its prev ele=0 so make product=1
            if(suff==0)suff=1;//same if in suff prod=0 means its prev=0
            pre*=nums[i];
            suff*=nums[n-i-1];
            ans=max(ans,max(pre,suff));
        }
        return ans;
    }
};



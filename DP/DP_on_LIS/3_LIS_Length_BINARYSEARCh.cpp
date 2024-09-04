#include<bits/stdc++.h>
using namespace std;
int LIS(vector<int>&nums){

    vector<int>v(nums.size());
    v[0]=nums[0];
    for(int i=1;i<nums.size();i++){
        if(nums[i]>v[i-1]){
                v[i]=nums[i];
        }
        else{
            int idx=lower_bound(v.begin(),v.end(),nums[i])-v.begin();
            v[idx]=nums[i];
        }
    }
    return v.size();

}

//TC=O(n log n) the BEST TimeComplexity .Even using tabulation we get n*n tc in previous
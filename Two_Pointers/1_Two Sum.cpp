//Leetcode 1

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(target-nums[i])!=mp.end()){
                return { mp[target-nums[i]],i};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};


//Two Pointer Approach is not valid for this one ,its valid for twosum II

#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target=0;
            sort(nums.begin(),nums.end());
            set<vector<int>>s;
            for(int i=0;i<nums.size();i++){
                int j=i+1;
                int k=nums.size()-1;
                while(j<k){
                    int sum=nums[i]+nums[j]+nums[k];
                    if(sum==target){
                        s.insert({nums[i],nums[j],nums[k]});
                        j++;
                        k--;
                    }
                    else if(sum>target)k--;
                    else j++;
                }
            }
            vector<vector<int>>ans;
            for(auto v:s) {
                ans.push_back(v);
            }
            return ans;
    }
};



//Without using set 



#include <iostream>
#include <vector>
#include <algorithm> // For sort

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            // Skip the same element to avoid duplicate triplets
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    ++left;
                    --right;

                    // Skip duplicates for the left pointer
                    while (left < right && nums[left] == nums[left - 1]) {
                        ++left;
                    }

                    // Skip duplicates for the right pointer
                    while (left < right && nums[right] == nums[right + 1]) {
                        --right;
                    }
                } else if (sum < 0) {
                    ++left;
                } else {
                    --right;
                }
            }
        }

        return result;
    }
};

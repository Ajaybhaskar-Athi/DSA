class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    //     int c=0;
    //     int n=nums.size();
    // vector<int>v;
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         if(nums[i]+nums[j]==target){
    //             v.push_back(i);
    //             v.push_back(j);
    //         }
    //     }
    // }
    // return v;
    
    unordered_map<int,int>mp;
    for(int i=0;i<nums.size();i++){
        int num=nums[i];
        if(mp.find(target-num)!=mp.end()){
            return {i,mp[target-num]};
        }
        mp[num]=i;
    }
    return {};
    }
};
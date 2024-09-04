#include<bits/stdc++.h>
using namespace std;

/*class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int maxi=1;
        vector<int>dp(n,1);
        for(int i=1;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[i]>nums[prev]){
                    dp[i]=max(dp[i],1+dp[prev]);
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};*/


//printing 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1),hash(n);
        hash[0]=0;
        for(int i=1;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(nums[i]>nums[prev]){
                    if(1+dp[prev]>dp[i]){
                        dp[i]=1+dp[prev];
                        hash[i]=prev;
                    }
                }
            }
           
        }

         int ans = -1;
    int lastIndex =-1;
    
    for(int i=0; i<=n-1; i++){
        if(dp[i]> ans){
            ans = dp[i];
            lastIndex = i;
        }
    }

        vector<int>LIS;
        LIS.push_back(nums[lastIndex]);
        while(hash[lastIndex]!=lastIndex){
            lastIndex=hash[lastIndex];
            LIS.push_back(nums[lastIndex]);

        }
        reverse(LIS.begin(),LIS.end());
        for(int ele:LIS)cout<<ele<<" ";

        return ans;
    }
};

int main(){
        vector<int>nums = {10,9,2,5,3,7,101,18};
        Solution obj;
     obj.lengthOfLIS(nums);
}
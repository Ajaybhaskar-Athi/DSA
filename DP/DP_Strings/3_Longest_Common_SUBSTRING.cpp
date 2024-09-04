//printing longest common subsequence

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
 
    int longestCommonSubstring(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
            int maxLen=INT_MIN;
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s1[i-1]==s2[j-1])dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=0;//simply zero no match
                maxLen=max(maxLen,dp[i][j]);
            }
        }

        return maxLen;
        
        
            
    }
};

int main(){
    Solution obj;
    cout<<obj.longestCommonSubstring("aacabdkacaa","aacakdbacaa");
}

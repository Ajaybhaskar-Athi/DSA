//printing longest common subsequence

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
 
    string longestCommonSubsequence(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        //base case if if(idx1<0 || idx2<0) return 0 but in arrays we cant set it. so move indexes by 1 to right. so -1 is 0 now and 0 is 1;
        for(int i=0;i<=n1;i++)dp[i][0]=0;
        for(int j=0;j<=n2;j++)dp[0][j]=0;

 //instead of above 3 code lines just declare in this way  vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,0));
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s1[i-1]==s2[j-1])dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=0+max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        // return dp[n1][n2];
        string res="";
        //printing
        
            int i=n1,j=n2;
            while(i>0 && j>0){
                if(s1[i-1]==s2[j-1]){
                    res+=s1[i-1];
                    i=i-1;
                    j=j-1;
                }
                else {
                    if(dp[i][j-1]>dp[i-1][j])j=j-1;
                    else i=i-1;
                }
            }
             reverse(res.begin(),res.end());
             return res;
    }
};

int main(){
    Solution obj;
    cout<<obj.longestCommonSubsequence("abcde","bdgek");
}

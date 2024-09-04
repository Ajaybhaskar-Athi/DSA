#include<bits/stdc++.h>
using namespace std;

//Leetcode 583

class solution{
    public:

    int minOperations(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        int len=longestCommonSubsequence(s1,s2);
        int deletions=n-len;
        int insertions=m-len;
        return insertions+deletions;    
    }
      



      int longestCommonSubsequence(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        //base case if if(idx1<0 || idx2<0) return 0 but in arrays we cant set it. so move indexes by 1 to right. so -1 is 0 now and 0 is 1;
        for(int i=0;i<=n1;i++)dp[i][0]=0;
        for(int j=0;j<=n2;j++)dp[0][j]=0;

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s1[i-1]==s2[j-1])dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=0+max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return dp[n1][n2];
    }
 
};

int main(){
    solution obj;
    cout<<obj.minOperations("horse","ros");
}
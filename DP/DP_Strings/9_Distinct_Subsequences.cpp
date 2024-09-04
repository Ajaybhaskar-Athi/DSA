#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
        int f(int i,int j,string s,string t){
                if(j<0)return  1;//t chars completed seaching means target found 
                if(i<0)return 0;//s chars completed and j still positive means t not found;
                if(s[i]==t[j]){
                    return f(i-1,j-1,s,t)+f(i-1,j,s,t);//take , not take  =>search if theres any j in s1
                }
                return f(i-1,j,s,t);// if not matched search j in s1 again
        }

    int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        return f(n-1,m-1,s,t);
    }
};


//Memoisation


class Solution {
public:
        int f(int i,int j,string s,string t,vector<vector<int>>&dp){
                if(j<0)return  1;//t chars completed seaching means target found 
                if(i<0)return 0;//s chars completed and j still positive means t not found;
                if(dp[i][j]!=-1)return dp[i][j];
                if(s[i]==t[j]){
                    return dp[i][j]= f(i-1,j-1,s,t,dp)+f(i-1,j,s,t,dp);//take , not take  =>search if theres any j in s1
                }
                return dp[i][j]= f(i-1,j,s,t,dp);// if not matched search j in s1 again
        }

    int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));


        return f(n-1,m-1,s,t,dp);
    }
};


//Tabulation


class Solution {
public:

    int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        vector<vector<double>>dp(n+1,vector<double>(m+1,-1));
        //1 based indexing
            for(int i=0;i<=n;i++)dp[i][0]=1;
            for(int i=1;i<=m;i++)dp[0][i]=0;// if i=0 and j=0 (means i=-ve abd j=-ve in recursion) then s2 found in s1 so 1 thats why dp[0][0]=1;
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=m;j++){
                        if(s[i-1]==t[j-1])dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                        else dp[i][j]=dp[i-1][j];
                    }
                }
                return (int)dp[n][m];
    }
};

//I wrote double since in leetcode even after writing long long it gives run time error
//so just make it double and make sure return int by type casting it 


//Space Optimised 


class Solution {
public:

    int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        vector<double>prev(m+1,0),curr(m+1,0);
        prev[0]=1;
                for(int i=1;i<=n;i++){
                    curr[0]=1;
                    for(int j=1;j<=m;j++){
                        if(s[i-1]==t[j-1])curr[j]=prev[j-1]+prev[j];
                        else curr[j]=prev[j];
                    }
                    prev=curr;
                }
                return (int) prev[m];
    }
};


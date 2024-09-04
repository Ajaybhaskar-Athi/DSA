/*You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45







*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        /*
        if(n==0)return 1;
        if(n==1)return 1;//suppose only one stair we can clicmb in only one way same apply for 0 stairss

        int left=climbStairs(n-1); //climbing 1 step at a time
        int right=climbStairs(n-2); //climbing 2 stpes at a time
        return left+right;
But its taking so much tc of O(2^n) .when n is so big  we cam get TIme Limit Exceeded
        */
        if(n<=1)return n;
        vector<int>dp(n+1,-1);
        dp[0]=1; dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};


//APPLY tabulation also to remove these extra space
// #coding ninjas
/*Problem statement
You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. Your task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.

Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise, return false.

For Example :
If ‘ARR’ is {1,2,3,4} and ‘K’ = 4, then there exists 2 subsets with sum = 4. These are {1,3} and {4}. Hence, return true.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 5
1 <= N <= 10^3
0 <= ARR[i] <= 10^9
0 <= K <= 10^3

Time Limit: 1 sec
Sample Input 1:
2
4 5
4 3 2 1
5 4
2 5 1 6 7
Sample Output 1:
true
false
Explanation For Sample Input 1:
In example 1, ‘ARR’ is {4,3,2,1} and ‘K’ = 5. There exist 2 subsets with sum = 5. These are {4,1} and {3,2}. Hence, return true.
In example 2, ‘ARR’ is {2,5,1,6,7} and ‘K’ = 4. There are no subsets with sum = 4. Hence, return false.
Sample Input 2:
2
4 4
6 1 2 1`
5 6
1 7 2 9 10
Sample Output 2:
true
false
Explanation For Sample Input 2:
In example 1, ‘ARR’ is {6,1,2,1} and ‘K’ = 4. There exist 1 subset with sum = 4. That is {1,2,1}. Hence, return true.
In example 2, ‘ARR’ is {1,7,2,9,10} and ‘K’ = 6. There are no subsets with sum = 6. Hence, return false.


Hints:
1. Can you find every possible subset of ‘ARR’ and check if its sum is equal to ‘K’?
2. Can you use dynamic programming and use the previously calculated result to calculate the new result?
3. Try to use a recursive approach followed by memoization by including both index and sum we can form. 

*/

#include <bits/stdc++.h> 
using namespace std;

//METHOD recurison Tc=O(2^n) 
bool f(int ind, int target, vector<int>& arr) {
    if (target == 0) return true;
    if (ind == 0) return arr[0] == target;
    bool notTaken = f(ind - 1, target, arr);
    bool taken = false;
    if (target >= arr[ind]) {
        taken = f(ind - 1, target - arr[ind], arr);
    }
    return taken || notTaken;
}


bool subsetSumToTarget(int n, int target, vector<int>& arr) {
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(target, -1));
    return f(n - 1, target, arr);
}

/*

bool subsetEqualsTarget(int idx,int t,vector<int>&v){
    if(t==0)return true;
    if(t<0)return false;
    if(idx==0)return v[0]==t;

    bool take=subsetEqualsTarget(idx-1,t-v[idx],v);
    bool notTake=subsetEqualsTarget(idx-1,t,v);
        return take || notTake;
}

*/



//METHOD MEmorisation Tc=o(n x target) and sc=o(n X target )+o(n) { last o(n) is for recursion stack space remove by TAbulation}
//We are using a recursion stack space(O(N)) and a 2D array ( O(N*K)).

#include <bits/stdc++.h> 

bool f(int ind, int target, vector<int>& arr,vector<vector<int>>&dp) {
    if (target == 0) return true;
    if (ind == 0) return arr[0] == target;
    if(dp[ind][target]!=-1)return dp[ind][target];

    bool notTaken = f(ind - 1, target, arr,dp);
    bool taken = false;
    if (target >= arr[ind]) {
        taken = f(ind - 1, target - arr[ind], arr,dp);
    }
    return  dp[ind][target]=taken || notTaken;
}

bool subsetSumToTarget(int n, int target, vector<int>& arr) {
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(target+1, -1));
    return f(n - 1, target, arr,dp);
}



//METHOD Tabulation tc=o(n) and sc=o(n x target)


bool subsetSumToK(int n, int target, vector<int>& arr) {
    vector<vector<bool>> dp(n, vector<bool>(target+1, false));
     // Base case: If the target sum is 0, we can always achieve it by taking no elements
     //target =0 can be done for any index so 2d array of 0th column target and ith row to true
   for(int i=0;i<n;i++)dp[i][0]=true;
    //at index =0 target can be anything what at target 0;
if(target>=arr[0]) dp[0][arr[0]]=true;
    
for(int ind=1;ind<n;ind++){
    for(int t=1;t<=target;t++){
        bool notTaken=dp[ind-1][t];
        bool taken=false;
        if(t>=arr[ind]){
            taken=dp[ind-1][t-arr[ind]];
        }
        dp[ind][t]=taken||notTaken;
    }

}
return dp[n-1][target];

}
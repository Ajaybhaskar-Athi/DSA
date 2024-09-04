// #coding ninjas  HOUSE ROBBER PROBLEM IN LEETCODE

/*Problem statement
You are given an array/list of ‘N’ integers.
 You are supposed to return the maximum sum of the subsequence with the constraint that no two elements are
  adjacent in the given array/list.

Note:
A subsequence of an array/list is obtained by deleting some number of elements (can be zero) from the array/list,
 leaving the remaining elements in their original order.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 500
1 <= N <= 1000
0 <= ARR[i] <= 10^5

Where 'ARR[i]' denotes the 'i-th' element in the array/list.

Time Limit: 1 sec.
Sample Input 1:
2
3
1 2 4
4
2 1 4 9
Sample Output 1:
5
11
Explanation to Sample Output 1:
In test case 1, the sum of 'ARR[0]' & 'ARR[2]' is 5 which is greater than 'ARR[1]' which is 2 so the answer is 5.

In test case 2, the sum of 'ARR[0]' and 'ARR[2]' is 6, the sum of 'ARR[1]' and 'ARR[3]' is 10, and the sum of 'ARR[0]' and 'ARR[3]' is 11. So if we take the sum of 'ARR[0]' and 'ARR[3]', it will give the maximum sum of sequence in which no elements are adjacent in the given array/list.
Sample Input 2:
2
5
1 2 3 5 4
9
1 2 3 1 3 5 8 1 9
Sample Output 2:
8
24
Explanation to Sample Output 2:
In test case 1, out of all the possibilities, if we take the sum of 'ARR[0]', 'ARR[2]' and 'ARR[4]', i.e. 8, it will give the maximum sum of sequence in which no elements are adjacent in the given array/list.

In test case 2, out of all the possibilities, if we take the sum of 'ARR[0]', 'ARR[2]', 'ARR[4]', 'ARR[6]' and 'ARR[8]', i.e. 24 so, it will give the maximum sum of sequence in which no elements are adjacent in the given array/list.
*/

#include <bits/stdc++.h> 
using namespace std;


//METHOD 1: Recursion

int f(int ind,vector<int>&arr){
if(ind==0)return arr[ind];
if(ind<0)return 0;

int  pick = arr[ind] + f(ind - 2, arr);

int notPick=0+f(ind-1,arr);
return max(pick,notPick);


}


int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    return f(n-1,nums);
}


///Method 2 Memeorization TOp down tc=O(n) and sc=o(n)+o(n)

int f(int ind,vector<int>&arr,vector<int>&dp){
if(ind==0)return arr[ind];
if(ind<0)return 0;
if(dp[ind]!=-1)return dp[ind];
int  pick = arr[ind] + f(ind - 2, arr,dp);

int notPick=0+f(ind-1,arr,dp);
return  dp[ind]=max(pick,notPick);


}


int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    vector<int>dp(n,-1);
    return f(n-1,nums,dp);
}



//MEthod 3: Tabulation tc =O(n) and sc=o(n)




int f(int ind,vector<int>&arr,vector<int>&dp){
dp[0]=arr[0];
// int maxSum=
for(int i=1;i<=ind;i++){
    int pick=arr[i];
    if(i>1) pick+=dp[i-2];
int notPick=dp[i-1];
dp[i]=max(pick,notPick);
}

return  dp[ind];


}



int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    vector<int>dp(n,-1);
    return f(n-1,nums,dp);
}

/*


int houseRobber(int n,vector<int>&v){
    vector<int>dp(n+1,-1);
    dp[0]=0;
    dp[1]=v[0];
    for(int idx=2;idx<=n;idx++){
        int take=v[idx-1]+dp[idx-2];
        int notTake=0+dp[idx-1];
        dp[idx]=max(take,notTake);
    }
    return dp[n];

}
*/

//space optimasation approach


int f(int ind,vector<int>&arr){
int prev=arr[0];
int prev2=0;
for(int i=1;i<=ind;i++){
    int pick=arr[i];
    if(i>1) pick+=prev2;
int notPick=prev;
int curr_i=max(pick,notPick);
prev2=prev;
prev=curr_i;
}

return  prev;


}
/*
int spaceOptimised(int n,vector<int>&v){
    int prev=v[0];
    int prev2=0;
    for(int i=1;i<n;i++){
        int take=v[i]+prev2;
        int notTake=0+prev;
        prev2=prev;
        prev=max(take,notTake);
    }
    return prev;
}

*/


int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    return f(n-1,nums);
}
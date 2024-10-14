// #coding Ninjas


/*There is a frog on the '1st' step of an 'N' stairs long staircase. The frog wants to reach the 'Nth' stair. 'HEIGHT[i]' is the height of the '(i+1)th' stair.If Frog jumps from 'ith' to 'jth' stair, the energy lost in the jump is given by absolute value of ( HEIGHT[i-1] - HEIGHT[j-1] ).
 If the Frog is on 'ith' staircase, he can jump either to '(i+1)th' stair or to '(i+2)th' stair. Your task is to find the minimum total energy used by the frog to reach from '1st' stair to 'Nth' stair.

For Example
If the given ‘HEIGHT’ array is [10,20,30,10], the answer 20 as the frog can jump from 1st stair to 2nd stair (|20-10| = 10 energy lost) and then a jump from 2nd stair to last stair (|10-20| = 10 energy lost). So, the total energy lost is 20.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 100000.
1 <= HEIGHTS[i] <= 1000 .

Time limit: 1 sec
Sample Input 1:
2
4
10 20 30 10
3
10 50 10
Sample Output 1:
20
0
Explanation of sample input 1:
For the first test case,
The frog can jump from 1st stair to 2nd stair (|20-10| = 10 energy lost).
Then a jump from the 2nd stair to the last stair (|10-20| = 10 energy lost).
So, the total energy lost is 20 which is the minimum. 
Hence, the answer is 20.

For the second test case:
The frog can jump from 1st stair to 3rd stair (|10-10| = 0 energy lost).
So, the total energy lost is 0 which is the minimum. 
Hence, the answer is 0.
Sample Input 2:
2
8
7 4 4 2 6 6 3 4 
6
4 8 3 10 4 4 
Sample Output 2:
7
2


Hints:
1. Think about all the possibilities at each stair.
2. Using recursion, try to divide the problem into subproblems and calculate the answer for each subproblem only once - store it for reusing in the future.
3. The above can also be done iteratively.
*/

//RECURSIOn  TC=O(2^n )and sc=O(n)

#include <bits/stdc++.h>  

int f(int ind,vector<int>&arr){
    if(ind==0)return 0;
    int left=f(ind-1,arr)+abs(arr[ind]-arr[ind-1]);
    int right=INT_MAX;//we intialised this to MAX coz ind>1 not always perform
    if(ind>1){
         right=f(ind-2,arr)+abs(arr[ind]-arr[ind-2]);
    }
    return  min(left,right);
}
int frogJump(int n, vector<int> &heights)
{
 return f(n-1,heights);
  
}


/*
This one also ACCEPTED

int f(int idx,vector<int>&h){
     if(idx==1)return abs(h[idx]-h[idx-1]);
     if(idx==0)return 0;
    int one=f(idx-1,h)+abs(h[idx]-h[idx-1]);
    int two=f(idx-2,h)+abs(h[idx-2]-h[idx]);
    return min(one,two);
}
int frogJump(int n, vector<int> &heights)
{
 return f(n-1,heights);
  
}


// ----TABULATION

int frogJump(int n, vector<int> &h)
{
    vector<int>dp(n,-1);
    dp[0]=0;
    dp[1]=abs(h[1]-h[0]);
       for(int i=2;i<h.size();i++){
        int one=abs(h[i-1]-h[i])+dp[i-1];
        int two=abs(h[i-2]-h[i])+dp[i-2];
        dp[i]=min(one,two);
    }
 return dp[n-1];
  
}


*/






//METHOD  Memorization tc=O(n) and sc=O(n)+O(n) [stackspace+extra array]

#include <bits/stdc++.h>  
using namespace std;
int f(int ind,vector<int>&arr,vector<int>&dp){
    if(ind==0)return 0;
    if(dp[ind]!=-1)return dp[ind];
    int left=f(ind-1,arr,dp)+abs(arr[ind]-arr[ind-1]);
    int right=INT_MAX;//we intialised this to MAX coz ind>1 not always perform
    if(ind>1){
         right=f(ind-2,arr,dp)+abs(arr[ind]-arr[ind-2]);
    }
    return dp[ind]= min(left,right);
}
int frogJump(int n, vector<int> &heights)
{vector<int>dp(n,-1);
 return f(n-1,heights,dp);
  
}



// #METHOD TABULATIOn tc=O(n) and sc=O(n)


#include <bits/stdc++.h>

using namespace std;


int main() {

  vector<int> height{30,10,60,10,60,50};
  int n=height.size();
  vector<int> dp(n,-1);
  dp[0]=0;
  for(int ind=1;ind<n;ind++){
      int jumpTwo = INT_MAX;
        int jumpOne= dp[ind-1] + abs(height[ind]-height[ind-1]);
        if(ind>1)
            jumpTwo = dp[ind-2] + abs(height[ind]-height[ind-2]);
    
        dp[ind]=min(jumpOne, jumpTwo);
  }
  cout<<dp[n-1];
}










//SPACE optimisation tc=O(n) and sc=O(1)



#include <bits/stdc++.h>

using namespace std;


int main() {

  vector<int> height{30,10,60,10,60,50};
  int n=height.size();
  int prev=0;
  int prev2=0;
  for(int i=1;i<n;i++){
      
      int jumpTwo = INT_MAX;
      int jumpOne= prev + abs(height[i]-height[i-1]);
      if(i>1)
        jumpTwo = prev2 + abs(height[i]-height[i-2]);
    
      int cur_i=min(jumpOne, jumpTwo);
      prev2=prev;
      prev=cur_i;
        
  }
  cout<<prev;
}


// #coding ninjas

/*Problem statement
Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn?

You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. Your task is to calculate the maximum number of merit points that Ninja can earn.

For Example
If the given ‘POINTS’ array is [[1,2,5], [3 ,1 ,1] ,[3,3,3] ],the answer will be 11 as 5 + 3 + 3.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 100000.
1 <= values of POINTS arrays <= 100 .

Time limit: 1 sec
Sample Input 1:
2
3
1 2 5 
3 1 1
3 3 3
3
10 40 70
20 50 80
30 60 90
Sample Output 1:
11
210
Explanation of sample input 1:
For the first test case,
One of the answers can be:
On the first day, Ninja will learn new moves and earn 5 merit points. 
On the second day, Ninja will do running and earn 3 merit points. 
On the third day, Ninja will do fighting and earn 3 merit points. 
The total merit point is 11 which is the maximum. 
Hence, the answer is 11.

For the second test case:
One of the answers can be:
On the first day, Ninja will learn new moves and earn 70 merit points. 
On the second day, Ninja will do fighting and earn 50 merit points. 
On the third day, Ninja will learn new moves and earn 90 merit points. 
The total merit point is 210 which is the maximum. 
Hence, the answer is 210.
Sample Input 2:
2
3
18 11 19
4 13 7
1 8 13
2
10 50 1
5 100 11
Sample Output 2:
45
110

*/

#include<bits/stdc++.h>
using namespace std;

// #Method Recursion 

int f(int day,int last,vector<vector<int>>&points){

        if(day==0){
            int maxi=0;
            for(int i=0;i<=2;i++){
                if(i!=last)
                maxi=max(maxi,points[0][i]);
            }
            return maxi;
        }

        int maxi=0;
        for(int i=0;i<=2;i++){
            if (i != last) {
                int actvity = points[day][i] + f(day - 1, i, points);
                maxi = max(maxi, actvity);
            }
        }
        
        return maxi;

}


int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n,vector<int>(4,-1));
    return f(n-1,3,points);
}



//Method Memorization 

//  Time Complexity: O(N*4*3)
// Reason: There are N*4 states and for every state, we are running a for loop iterating three times.

// Space Complexity: O(N) + O(N*4)

// Reason: We are using a recursion stack space(O(N)) and a 2D array (again O(N*4)). Therefore total space complexity will be O(N) + O(N) ≈ O(N)

int f(int day,int last,vector<vector<int>>&points,vector<vector<int>>&dp){
if(dp[day][last]!=-1)return dp[day][last];
        if(day==0){
            int maxi=0;
            for(int i=0;i<=2;i++){
                if(i!=last)
                maxi=max(maxi,points[0][i]);
            }
            return  dp[0][last]=maxi;
        }

        int maxi=0;
        for(int i=0;i<=2;i++){
            if (i != last) {
                int actvity = points[day][i] + f(day - 1, i, points,dp);
                maxi = max(maxi, actvity);
            }
        }

        return dp[day][last]= maxi;

}


int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n,vector<int>(4,-1));
    return f(n-1,3,points,dp);
}



//Tabulation 
    
// Time Complexity: O(N*4*3)

// Reason: There are three nested loops

// Space Complexity: O(N*4)

// Reason: We are using an external array of size ‘N*4’’



int f(int n, vector<vector<int>>& points, vector<vector<int>>& dp) {
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max({points[0][0] , points[0][1] , points[0][2]}); // Fixing the initialization for dp[0][3]
    
    for (int day = 1; day < n; day++) {
        for (int last = 0; last < 4; last++) {
            for (int task = 0; task < 3; task++) { // Changing the condition to task < 3
                if (task != last) {
                    int activity = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], activity);
                }
            }
        }
    }
    
    return dp[n - 1][3]; // Returning dp[n-1][3] instead of dp[n][3] as arrays are 0-indexed in C++
}

int ninjaTraining(int n, vector<vector<int>>& points) {
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return f(n, points, dp); // Passing n (without -1) to function f
}

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    bool static compareSort(vector<int>&a,vector<int>&b){
            return  a[2]>b[2];
            //sort acc to profits

    }
    
    vector<int> JobScheduling(vector<vector<int>>&v, int n) 
    { 
       sort(v.begin(),v.end(),compareSort);
    //    { {3 1 40}, {4 1 30 },{1 4 20},{2 1 10}}
        int maxi=v[0][1];//max deadline
        for(int i=1;i<n;i++){
            maxi=max(maxi,v[i][1]);
        }
        vector<int>slots(maxi+1,-1); //slots since a job can complete before or on its deadline.
        int countJobs=0,profit=0;
        for(int i=0;i<n;i++){
            for(int j=v[i][1];j>0;j--){ //find slots on or before deadline
                if(slots[j]==-1){
                    slots[j]=v[i][0];
                    countJobs++;
                    profit+=v[i][2];
                    break;
                }
            }
        }

    for(auto ele:v){
        cout<<ele[0]<<" "<<ele[1]<<" "<<ele[2]<<endl;
    }
    cout<<profit<<" "<<countJobs;
    return {profit,countJobs};
    } 
};


int main(){
//  vector<vector<int>> Jobs = {
//         {1, 2, 100},
//         {2, 1, 19},
//         {3, 2, 27},
//         {4, 1, 25},
//         {5, 1, 15}
//     };
vector<vector<int>> Jobs = {
        {1, 4, 20},
        {2, 1, 10},
        {3, 1, 40},
        {4, 1, 30}
    };

    Solution obj;
   vector<int>ans= obj.JobScheduling(Jobs,Jobs.size());
}


//same above for finding slots iinstead of for loop use lower bound concept 
/*

#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    // Comparison function to sort jobs based on profit
    bool static compareSort(const vector<int>& a, const vector<int>& b) {
        return a[2] > b[2]; // Sort jobs in descending order of profit
    }
    
    vector<int> JobScheduling(vector<vector<int>>& v, int n) {
        // Step 1: Sort the jobs based on profit
        sort(v.begin(), v.end(), compareSort);
        
        // Step 2: Create a set to track available slots (days)
        set<int> availableSlots;

        // Assume the maximum deadline is at most 'n' (the number of jobs)
        for (int i = 1; i <= n; i++) {
            availableSlots.insert(i); // Add days 1 to n to available slots
        }

        int countJobs = 0;    // Count of scheduled jobs
        int profit = 0;       // Total profit from scheduled jobs

        // Step 3: Schedule jobs using lower_bound logic
        for (const auto& job : v) {
            int jobId = job[0];
            int deadline = job[1];
            int jobProfit = job[2];

            // Find the first available slot that is greater than or equal to the job's deadline
            auto it = availableSlots.lower_bound(deadline + 1);

            // If an available slot is found
            if (it != availableSlots.begin()) { // Check if there is a valid slot
                --it; // Move the iterator to the last valid slot
                // Schedule the job on this day
                countJobs++;            // Increment count of jobs scheduled
                profit += jobProfit;    // Add the profit
                availableSlots.erase(it); // Remove this day from available slots
            }
        }

        // Step 4: Return the result
        return {profit, countJobs}; // Return total profit and count of jobs
    } 
};

// Example usage
int main() {
    Solution sol;
    vector<vector<int>> jobs = { {3, 1, 40}, {4, 1, 30}, {1, 4, 20}, {2, 1, 10} };
    int n = jobs.size();
    
    vector<int> result = sol.JobScheduling(jobs, n);
    cout << "Total profit: " << result[0] << ", Number of jobs scheduled: " << result[1] << endl;

    return 0;
}
*/






//////////////////////////////////////////////////////////////////////////////////////

// //Acc to geek for Geeks
// struct Job 
// { 
//     int id;	 // Job Id 
//     int dead; // Deadline of job 
//     int profit; // Profit if job is over before or on deadline 
// };



// class Solution {
//    public:
//       bool static comparison(Job a, Job b) {
//          return (a.profit > b.profit);
//       }
//    //Function to find the maximum profit and the number of jobs done
//    vector<int> JobScheduling(Job arr[], int n) {

//       sort(arr, arr + n, comparison);
//       int maxi = arr[0].dead;
//       for (int i = 1; i < n; i++) {
//          maxi = max(maxi, arr[i].dead);
//       }

//       int slot[maxi + 1];

//       for (int i = 0; i <= maxi; i++)
//          slot[i] = -1;

//       int countJobs = 0, jobProfit = 0;

//       for (int i = 0; i < n; i++) {
//          for (int j = arr[i].dead; j > 0; j--) {
//             if (slot[j] == -1) {
//                slot[j] = i;
//                countJobs++;
//                jobProfit += arr[i].profit;
//                break;
//             }
//          }
//       }

//       return {countJobs, jobProfit};
//    }
// };


// int main() {
//     int t;
//     cin >> t; // Input number of test cases
//     while (t--) {
//         int n;
//         cin >> n; // Input number of jobs
//         Job arr[n];
        
//         for (int i = 0; i < n; i++) {
//             int x, y, z;
//             cin >> x >> y >> z; // Input job id, deadline, and profit
//             arr[i].id = x;
//             arr[i].dead = y;
//             arr[i].profit = z;
//         }

//         Solution obj;
//         int ans = obj.JobScheduling(arr, n); // Get maximum profit
//         cout << ans << endl; // Output the answer
//     }
//     return 0;
// }
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
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[2] != b[2]) {
            return a[2] < b[2]; // Sort by platform
        }
        return a[1] < b[1]; // Sort by departure time
    }
  
    int maxStop(int n, int m, vector<vector<int>>& v) {
        // Sort trains based on platform and departure time
        sort(v.begin(), v.end(), cmp);
      
        for (const auto& ele : v) {
            cout << ele[0] << " " << ele[1] << " " << ele[2] << endl;
        }
        
        int prevEnd = v[0][1]; // Departure time of the first train
        int prev_PF = v[0][2]; // Platform of the first train
        int ans = 1; // Count of stopped trains

        for (int i = 1; i < m; i++) {
            int curr_PF = v[i][2]; // Current train platform
            int currEnd = v[i][1]; // Current train departure time
            int currStart = v[i][0]; // Current train arrival time
            
            // If the current train is on a different platform
            if (curr_PF != prev_PF) {
                prev_PF = curr_PF; // Update previous platform
                prevEnd = currEnd; // Update previous end time
                ans++; // Increment answer
                continue;
            }
            
            // If the current train can be accommodated
            if (currStart > prevEnd) {
                ans++; // Increment answer
                prevEnd = currEnd; // Update end time
            }
        }
        return ans; // Return the maximum number of stopped trains
    }
};

int main() {
    // Hardcoded values
    int n = 3; // Number of platforms
    int m = 6; // Number of trains
    vector<vector<int>> trains = {
        {1000, 1030, 1},
        {1010, 1030, 1},
        {1000, 1020, 2},
        {1030, 1230, 2},
        {1200, 1230, 3},
        {900, 1005, 1}
    };

    Solution sol; // Create an object of Solution class
    int result = sol.maxStop(n, m, trains); // Call maxStop method
    
    cout << "Maximum Stopped Trains = " << result << endl; // Output result
    return 0; // Return success
}


// // Custom comparator function to sort by platform and then by departure time
// bool customComparator(const vector<int>& a, const vector<int>& b) {
//     if (a[2] != b[2]) {
//         return a[2] < b[2]; // Ascending order for platform
//     }
//     return a[1] < b[1]; // Ascending order for departure time
// }

// int main() {
//     vector<vector<int>> trains = {
//         {1010, 1030, 1},
//         {1000, 1030, 1},
//         {1000, 1020, 2},
//         {1030, 1230, 2},
//         {1200, 1230, 3},
//         {900, 1005, 1}
//     };

//     // Sort using the custom comparator
//     sort(trains.begin(), trains.end(), customComparator);

//     // Print the sorted vector
//     for (const auto& train : trains) {
//         cout << train[0] << " " << train[1] << " " << train[2] << endl;
//     }

//     return 0;
// }

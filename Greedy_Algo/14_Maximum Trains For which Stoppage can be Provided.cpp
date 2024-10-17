//Geek for Geeks ( below both solutions were failing for so many test cases )
#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    
    bool static cmp(pair<int,int>&a, pair<int,int>&b){
        return a.first < b.first;
    }
  
    int maxStop(int n, int m, vector<vector<int>> &arr) {
        vector<vector<pair<int,int>>> v(n+1);

        for(int i = 0; i < m; i++){
            v[arr[i][2]].push_back({arr[i][1], arr[i][0]});
        }

        for(int i = 0; i <= n; i++){
            sort(v[i].begin(), v[i].end(), cmp);
        }

        int ans = 0;
        for(int i = 0; i <= n; i++){
            if(v[i].size() == 0) continue;

            int prev = 0;
            ans++;

            for(int j = 1; j < v[i].size(); j++){
                if(v[i][j].second >= v[i][prev].first){
                    prev = j;
                    ans++;
                }
            }
        }

        return ans;
    }
};





/*class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[2] != b[2]) {
            return a[2] < b[2];  // Compare by the third element first
        }
        return a[1] < b[1];  // Then compare by the second element (end time)
    }

    int maxStop(int n, int m, vector<vector<int>>& v) {
        if (m == 0) return 0;  // Handle empty input case

        sort(v.begin(), v.end(), cmp);  // Sort the events
        
        int prevEnd = v[0][1];  // End of the first event
        int prev_PF = v[0][2];  // PF of the first event
        int ans = 1;  // Start with one event

        for (int i = 1; i < m; i++) {
            int curr_PF = v[i][2];
            int currEnd = v[i][1];
            int currStart = v[i][0];

            if (curr_PF != prev_PF) {
                prev_PF = curr_PF;
                prevEnd = currEnd;
                ans++;
                continue;
            }

            if (currStart > prevEnd) {
                ans++;
                prevEnd = currEnd;  // Update the end time to the current event's end time
            }
        }
        return ans;  // Return the maximum number of stops
    }
};


*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool static compareSort(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

            sort(intervals.begin(),intervals.end(),compareSort);
            //intervals= { {1,2},{1,3},{2,3},{3,4}}
            int c=0;//count overlapping intervals
            int prevEnd=intervals[0][1];
            for(int i=1;i<intervals.size();i++){
                if(intervals[i][0]<prevEnd)c++;
                else prevEnd=intervals[i][1];
            }
            return c;
    }
};


// intervals = [[1,2],[2,3],[3,4],[1,3]]

//TC=O(nlogn+n);
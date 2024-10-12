/*

You have a list of events, each defined by two days:

startDay: The day the event starts.
endDay: The day the event ends.
You can attend each event on any day between its start and end days. However, you can only attend one event at a time.
*/


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool static compareSort(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    int maxEvents(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), compareSort);

        set<int> st;//days
        int count = 0;
         for(int i=1;i<=100000;i++)
        {
            st.insert(i);//pool of availabale days when you can attend meeting
        }

        for (const auto& event : v) {
        int s=event[0];
        int e=event[1];
        auto it=st.lower_bound(s); //the first day in set that is just greater than equal to  day s
        if(it==st.end() || *it>e) { //if not found or available date > end time of current evenrt
            continue;
        }
        else{
            count++;
            st.erase(it); //once you use a day, u remove it from set
        }
        }

        return count;
    }
};

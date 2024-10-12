#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool static cmp(vector<int>&a,vector<int>&b){
        return a[1]>b[1];//sort acc to no of units (val/weight);
    }
    int maximumUnits(vector<vector<int>>& v, int truckSize) {
            sort(v.begin(),v.end(),cmp);
            int ans=0;
            int i=0;
            int n=v.size();
            while(i<n){
                if(v[i][0]<=truckSize){ //continue if no of boexes <=capcity
                    ans+=v[i][0]*v[i][1];//toal units=no of unitsperbox * no of boxes
                    truckSize-=v[i][0];
                }else{
                    ans+=v[i][1]*truckSize;
                    break;
                }
                i++;
            }
            return ans;
    }
};
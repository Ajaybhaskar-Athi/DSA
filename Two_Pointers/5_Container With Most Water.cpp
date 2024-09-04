

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
       int i=0,j=n-1;
       int max_area=INT_MIN;
       while(i<j){
        int curr_area=(j-i)*min(height[i],height[j]);
        max_area=max(max_area,curr_area);
        if(height[i]<height[j])i++;
        else j--;
       }    
       return max_area;
    

    }
};
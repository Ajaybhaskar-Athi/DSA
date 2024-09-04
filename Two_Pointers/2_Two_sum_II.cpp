#include<bits/stdc++.h>

using namespace std;

//here instaed of numbers return their positons


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({numbers[i],i+1});//element,positon;
        }
        int i=0,j=n-1;
        while(i<j){
            if(numbers[i]+numbers[j]==target)return {v[i].second,v[j].second};
            else if(numbers[i]+numbers[j] > target)j--;
            else i++;
        }
        return {};
    }
};
//return the elemnts x,y in an sorted array where x+y=target
#include<bits/stdc++.h>

using namespace std;
vector<int> twoSum(vector<int>&v,int target){
        int n=v.size();
        int start=0,end=n=1;
        while(start<end){
            if(v[start]+v[end]==target)return {v[start],v[end]};
            else if(v[start]+v[end]>target)end--;
            else start++;
        }
        return {};

}
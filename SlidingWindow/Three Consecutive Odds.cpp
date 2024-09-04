/*
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n=arr.size();
        if(n<3)return false;
        for(int i=2;i<n;i++){
            if(arr[i] & 1==1 && arr[i-1]&1==1 && arr[i-2]&1==1)return true;
        }
        return false;
    }
};

*/

//TC is same in above and sliding window 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n=arr.size();
        if(n<3)return false;
        int window=0;
        for(int i=0;i<3;i++){
            window+=arr[i]%2;
        }
        if(window==3)return true;
        for(int i=3;i<n;i++){
            window+=arr[i]%2;
            window-=arr[i-3]%2;
            if(window==3)return true;
        }
        return false;
    }
};
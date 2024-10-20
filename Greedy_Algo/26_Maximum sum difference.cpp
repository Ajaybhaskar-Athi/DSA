#include<bits/stdc++.h>
using namespace std;


class Solution{
public:
    int maxSum(int N){
        if(N==1)return 1;
        // code here
        vector<int>v;
        for(int i=1;i<=((N+1)/2);i++){
            v.push_back(i);
            if(i!=N-i+1){
                v.push_back(N-i+1);
            }
        }
        // for(int ele:v)cout<<ele<<" ";
        // cout<<endl;
        
        int maxSum=0;
        for(int i=0;i<v.size()-1;i++){
            maxSum+=abs(v[i]-v[i+1]);
        }
        return maxSum;
    }
};
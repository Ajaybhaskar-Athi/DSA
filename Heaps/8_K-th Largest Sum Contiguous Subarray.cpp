#include<bits/stdc++.h>
using namespace std;
//using PREFIX SUM




class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        priority_queue<int,vector<int>,greater<>>pq;
        vector<int>ps;//prefix sum
        ps.push_back(arr[0]);
        for(int i=1;i<n;i++){
            ps.push_back(ps[i-1]+arr[i]);
        }
        
            
            for(int i=0;i<n;i++){
                for(int j=i;j<n;j++){
                    int x=ps[j];
                    if(i!=0)x-=ps[i-1];//sum of subarray from i->j
                    if(pq.size()<k)pq.push(x);
                    else if(x>pq.top()){
                        pq.pop();
                        pq.push(x);
                    }
                    
                }
            }
            
        return pq.top();
        
    }
};
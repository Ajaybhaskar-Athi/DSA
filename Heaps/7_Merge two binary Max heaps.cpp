#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        priority_queue<int>pq;
        int i=0;
        for( ;i<min(n,m);i++){
            pq.push(a[i]);
            pq.push(b[i]);
        }
        while(i<n)pq.push(a[i++]);
        while(i<m)pq.push(b[i++]);
        vector<int>v;
        while(!pq.empty()){
            v.push_back(pq.top());
            pq.pop();
        }
        return v;
    }
};
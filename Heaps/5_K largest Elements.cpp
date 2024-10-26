#include<bits/stdc++.h>
using namespace std;

class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    priority_queue<int,vector<int>,greater<>>pq; //minHeap
        
	    for(int i=0;i<n;i++){
	     if(i<k)  pq.push(arr[i]);
	     else if(arr[i]>pq.top()){
	         pq.pop();
	         pq.push(arr[i]);
	     }
	    }
	   vector<int>v(pq.size());
	   for(int i=pq.size()-1;i>=0;i--){
	       v[i]=pq.top();
	       pq.pop();
	   }
	   return v;
	}

};

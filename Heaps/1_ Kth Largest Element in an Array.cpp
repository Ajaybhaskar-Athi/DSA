#include<bits/stdc++.h>
using namespace std;


//simply maintaining MAX priority queue and returning the kth starting elements since they are sorted in descedning order
//TC=o(n)+o(nLog k) for building and for sextracting k-1 elemennts out

 int findKthLargest(vector<int>& nums, int k) {
     //Max priority queue;
     priority_queue<int>max_heap;
     for(int ele:nums){
        max_heap.push(ele);
     } 
     //priority_queue<int>max_heap(nums.begin(),nums.end()); without for loop we can do this also which takes o(n) time , same tc but shortuct
     for(int i=1;i<k;i++)max_heap.pop();
     return max_heap.top();  
    }



    /*
    
    Using a Min-Heap (Priority Queue)
    
    
The min-heap approach is particularly efficient when 
𝑘
k is much smaller than the size of the array. By maintaining a min-heap of size 
𝑘
k, you ensure that the smallest element in the heap is the 
𝑘
kth largest element in the array once all elements are processed.


*/
//TC=o(n log k ) since we r not pushing all elements into the heap 
//sc=o(k)


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
   priority_queue<int,vector<int>,greater<> >min_heap;
    for(int i=0;i<k;i++){
        min_heap.push(nums[i]);
    }

    for(int i=k;i<nums.size();i++){
        if(nums[i]>min_heap.top()){
            min_heap.pop();
            min_heap.push(nums[i]);
        }
    }
    return min_heap.top();//since at last we r having the k largest elements in min queue

    }
};




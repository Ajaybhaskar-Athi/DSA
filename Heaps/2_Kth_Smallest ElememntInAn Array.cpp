#include<bits/stdc++.h>
using namespace std;

//approach 1
//Take Min Heap (min priority quuee) ,find the kth positioned element in the min heap 
//construction =o(n) and for extraction =o(nlogk)


//APPROCH 2
//TAke MAX HEAP
//1->push 1st k elemnts of array into heap it sorted descnding means i can get kth smallest at top of heap among k ele,mnts in heap
//2->push remaing into heap by checking if top of heap is smaller then remaing elemnts in array
//tc=o(n log k)

int kth_Smallest(vector<int>&nums,int k){
    priority_queue<int>max_heap;
    for(int i=0;i<k;i++){
        max_heap.push(nums[i]);
    }
    for(int i=k;i<nums.size();i++){
        if(nums[i]<max_heap.top()){
            max_heap.pop();
            max_heap.push(nums[i]);
        }
    }
    return max_heap.top();
}
/*
int kth_Smallest(vector<int>&nums,int k){
    priority_queue<int>max_heap;

    for(int i=0;i<nums.size();i++){
        if(i<k)max_heap.push(nums[i]);
        else if(nums[i]<max_heap.top()){
            max_heap.pop();
            max_heap.push(nums[i]);
        }
    }
    
    return max_heap.top();

}*/


int main(){
    vector<int>v={1,5,6,8,0,2};
    cout<<kth_Smallest(v,6);
}
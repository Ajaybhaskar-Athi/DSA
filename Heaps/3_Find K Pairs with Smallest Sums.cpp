

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue< pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>  > min_heap;
        int n1=nums1.size(),n2=nums2.size();
        for(int i=0;i<min(k,n1);i++){
            for(int j=0;j<min(k,n2);j++){
                int sum=nums1[i]+nums2[j];
                min_heap.push({sum,{nums1[i],nums2[j]}});
            }
        }
        vector<vector<int>>ans;
        while(!min_heap.empty() && ans.size()<k){
            auto p=min_heap.top();
             ans.push_back({p.second.first, p.second.second});
            min_heap.pop();
        }
        return ans;

    }
};
/*
Efficiency Consideration: Instead of iterating through the entire arrays nums1 and nums2 (which could be very large), 
we only need to consider the first k elements from both arrays. This is because: The smallest sums are likely to be among 
the initial pairs formed from the smallest elements of both arrays. Once we have found k smallest sums, continuing to iterate 
through more elements wouldn't change the fact that these are the smallest k sums.
*/

//Tc Time Complexity: O(k^2 log k)
// The priority queue can consume up to O(k^2) space.
// The output vector consumes O(k) space.
// Other variables consume O(1) space.


///APPROCACh 2

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue< pair<int,pair<int,int>>> max_heap;
        int n1=nums1.size(),n2=nums2.size();
        for(int i=0;i<min(k,n1);i++){
            for(int j=0;j<min(k,n2);j++){
                int sum=nums1[i]+nums2[j];

                if (max_heap.size() < k)
                max_heap.push({sum, {nums1[i], nums2[j]}});
            else if (sum < max_heap.top().first) {
                // If the current sum is smaller than the largest sum in the priority queue,
                // remove the largest sum and add the current sum
                max_heap.pop();
                max_heap.push({sum, {nums1[i], nums2[j]}});
            } else if (sum > max_heap.top().first) {
                // If the current sum is larger than the largest sum in the priority queue,
                // break the inner loop since sums will only increase from this point onwards
                break;
            }
            }
        }
        vector<vector<int>>ans;
        while(!max_heap.empty()){
            auto p=max_heap.top();
             ans.push_back({p.second.first, p.second.second});
            max_heap.pop();
        }
        return ans;

    }
};
/*
Time Complexity: O(min(k, n1) × min(k, n2) × log k)

Space Complexity: O(k)

*/
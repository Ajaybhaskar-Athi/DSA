/*Given two integer arrays nums1 and nums2, return an array of their intersection.
 Each element in the result must be unique and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>s1(nums1.begin(),nums1.end());
        unordered_set<int>s2(nums2.begin(),nums2.end());
vector<int>res;
        for(auto &ele:s1){
            // cout<<ele<<" ";
            if(s2.find(ele)!=s2.end())res.push_back(ele);
        }
        return res;
    }
};
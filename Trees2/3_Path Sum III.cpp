/*Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

 

Example 1:


Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.
Example 2:

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3
 

Constraints:

The number of nodes in the tree is in the range [0, 1000].
-109 <= Node.val <= 109
-1000 <= targetSum <= 1000*/


#include<bits/stdc++.h>
using namespace std;
#include<vector>
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  
// Logic - Like subarray sum equal to K
    // keep on storing psum in map and check if psum - target exists in map for some node
    // TC = SC = O(N)

class Solution {
public:
    void helper(TreeNode*root,unordered_map<long long,int>mp,int k,long long psum,int &ans){
        if(!root)return;
        
    //      x + target = psum ==> x = psum - target

        psum+=root->val;
        if(mp.find(psum-k)!=mp.end()){  //we r finding by removing any of previous element makes my sum equals target
            ans=ans+mp[psum-k];
        }
        mp[psum]++;
        helper(root->left,mp,k,psum,ans);
        helper(root->right,mp,k,psum,ans);
    }
    int pathSum(TreeNode* root, int targetSum) {
        long long psum=0;
        unordered_map<long long,int>mp;
        mp[0]=1;//suppose if we want to incliude the root itself.
        int ans=0;
        helper(root,mp,targetSum,psum,ans);
        return ans;
    }
};


//SAME LOGIC OF no of SUBBArrays Whose Sum Equals K
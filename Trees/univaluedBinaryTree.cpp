/*A binary tree is uni-valued if every node in the tree has the same value.

Given the root of a binary tree, return true if the given tree is uni-valued, or false otherwise.
Example 1:
Input: root = [1,1,1,1,1,null,1]
Output: true
Example 2:

Input: root = [2,2,2,5,2]
Output: false
 */


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
  

  
class Solution {
public:
bool helper(TreeNode*root,int val){
       if(!root)return true;
        if(root->val!=val)return false;
        return helper(root->left,val) && helper(root->right,val);
}
    bool isUnivalTree(TreeNode* root) {
     return helper(root,root->val);
    }
};
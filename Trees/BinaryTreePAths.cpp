/*Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

 

Example 1:


Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
Example 2:

Input: root = [1]
Output: ["1"]
 

Constraints:

The number of nodes in the tree is in the range [1, 100].
-100 <= Node.val <= 100*/


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
    void helper(TreeNode*root,vector<string>&v,string path){
        if(!root)return;   
            if(!root->left&&!root->right){
                path+=to_string(root->val);
                v.push_back(path);
                return;
            }
            path+=to_string(root->val)+"->";
            helper(root->left,v,path);
            helper(root->right,v,path);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>v;
   helper(root,v,"");
   return v;

    }
};
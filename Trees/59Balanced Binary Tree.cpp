

/*Given a binary tree, determine if it is 
height-balanced
.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104 */



#include<bits/stdc++.h>
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
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        int lh=height(root->left);
        int rh=height(root->right);
        return  abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right); 
        
            }

            int height(TreeNode*root){
                if(!root)return 0;
                int lh=height(root->left);
                int rh=height(root->right);
                return max(lh,rh)+1;
            }
};




// A tree is height balanced if for every node in the tree, the absolute difference
//  in height between its left and right subtrees (the balance factor) is at most 1.
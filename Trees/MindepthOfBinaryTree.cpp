#include<bits/stdc++.h>
using namespace std;

/*Base Case: If root is null, the depth is 0.

Leaf Node Case: If both left and right children are null, the depth is 1 (since its a leaf node).

Single Subtree Case: If one of the subtrees is null, you should return the depth of the other subtree plus one.
 This handles cases where one subtree is missing.

Both Subtrees Present: If both subtrees are non-null, compute the minimum depth of the left and right subtrees, 
and return the minimum of these depths plus one.
*/
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
    int minDepth(TreeNode* root) {
        if(!root)return 0;
        else if(!root->left && !root->right)return 1;
    if(!root->left) return minDepth(root->right)+1;
    if(!root->right)return minDepth(root->left)+1;
            int ld=minDepth(root->left);
            int rd=minDepth(root->right);
            return min(ld,rd)+1;
    }           
};
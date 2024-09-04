/*Given the root of a binary tree, return its maximum depth.
//is nothing but height of tree

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100

*/


/*
TC - O(num of nodes) as we are traversing all the nodes of the tree
SC - O(height of the tree) for the recursive stack*/
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
    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        int lh=maxDepth(root->left);
        int rh=maxDepth(root->right);
        return max(lh,rh)+1;
    }
};




// DEPTH: A binary tree's maximum depth is the number of nodes(vertices) along the longest path from the root node down to the farthest leaf node.

//Height can be solved by levelWise also but it taking extra spavce queue.

class bstNode{
    public:
    int data;
    bstNode*left,*right;
    bstNode(int val):data(val),left(NULL),right(NULL){}
};

int height(bstNode*root){
    if(!root)return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    return max(lh,rh)+1;
}


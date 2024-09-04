/*Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

 

Example 1:


Input: root = [3,1,4,null,2], k = 1
Output: 1
Example 2:


Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
 

Constraints:

The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104
 

Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?

*/


#include<bits/stdc++.h>
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };




 /*
// Method 1: Perform Inorder Traversal and stroe values in VEctor. kth samllest is found at kTh position or  k-1 index
// similarly Kth largest found from last i.e,, n-k index ;
// TIME COMPLEXITY =O(N) and SC=o(n) so we use below which takes TC=O(k)
//  */




class Solution {
public:

    int kthSmallest(TreeNode* root, int k) {
        int res=-1;
        int count=0;
        helper(root,k,count,res);
        return res;
    
    }
    
    void helper(TreeNode*root,int k,int &count,int &res){
            if(!root)return;
            helper(root->left,k,count,res);
            count++;
            if(k==count){
                res=root->val;
                return;
            }
            helper(root->right,k,count,res);
    }

};


/*
KTH LARGEST eLEMENT IN AN bst
so here same AbOVE method but RIght DATA and then LEFT
means
 helper(root->right);
 coutn==k ....
 helper(root->left);


 */
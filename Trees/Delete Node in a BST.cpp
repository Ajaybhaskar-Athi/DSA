/*Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
 

Example 1:


Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and its also accepted.

Example 2:

Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.
Example 3:

Input: root = [], key = 0
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-105 <= Node.val <= 105
Each node has a unique value.
root is a valid binary search tree.
-105 <= key <= 105
 */


//   Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

#include<bits/stdc++.h>
using namespace std;

//Here The required node is replaced by the minimum node in the right sub tree . 
//we can also replace the required node with the maxmimum node in the left sub tree which u can see in below of this code

class Solution {
public:
    TreeNode*findMinInRight(TreeNode*root){
        if(!root)return NULL;
        while(root->left)root=root->left;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return NULL;
        if(key<root->val)root->left=deleteNode(root->left,key);
        else if(key>root->val)root->right=deleteNode(root->right,key);
        else{
            if(!root->left && !root->right)return NULL;
            else if(!root->left || !root->right)return root->left==NULL?root->right:root->left;
            TreeNode*temp=findMinInRight(root->right);
            root->val=temp->val;
            root->right=deleteNode(root->right,temp->val);
            
        }
        return root;
    }
};







class Solution2 {
public:
    
    TreeNode*findMaxInLeft(TreeNode*root){
        if(!root)return NULL;
        while(root->right)root=root->right;
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return NULL;
        if(key<root->val)root->left=deleteNode(root->left,key);
        else if(key>root->val)root->right=deleteNode(root->right,key);
        else{
            if(!root->left && !root->right)return NULL;
            else if(!root->left || !root->right)return root->left==NULL?root->right:root->left;
        


            TreeNode*temp=findMaxInLeft(root->left);
            root->val=temp->val;
            root->left=deleteNode(root->left,temp->val);
            
        }
        return root;
    }
};
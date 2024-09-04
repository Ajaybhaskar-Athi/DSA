/*Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:


Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:

Input: root = [1,null,3]
Output: [1,3]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
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


//same as left view but here we r traverrsing right side first thats it

class Solution {
public:
    void helper(TreeNode*root,vector<int>&res,int curLevel,int &maxLevel){
        if(!root)return;
        if(curLevel>maxLevel){
            res.push_back(root->val);
            maxLevel=curLevel;
        }
        helper(root->right,res,curLevel+1,maxLevel);
        helper(root->left,res,curLevel+1,maxLevel);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        int maxLevel=-1;
        helper(root,res,0,maxLevel);
        return res;
    }
};


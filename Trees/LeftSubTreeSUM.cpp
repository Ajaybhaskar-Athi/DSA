
/*class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root->left); // Start from the left subtree
    }

    int dfs(TreeNode* root) {
        if (!root) return 0;

        int leftSum = dfs(root->left); // Sum of left subtree
        int rightSum = dfs(root->right); // Sum of right subtree

        return root->val + leftSum + rightSum; // Return the sum of current node and its subtrees
    }
};


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
        void helper(TreeNode*root,vector<int>&v){
            if(!root)return;
            if(!root->left&&!root->right)v.push_back(root->val);
            helper(root->left,v);
            helper(root->right,v);
            return;
        }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>v1;
        vector<int>v2;
        helper(root1,v1);
        helper(root2,v2);
        return v1==v2;
    }
};

#include <bits/stdc++.h>
using namespace std;

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
     void helper(TreeNode*& root,TreeNode*&prev){
        if(!root)return;
        helper(root->right,prev);
        helper(root->left,prev);
        root->right=prev;
            root->left=NULL;
        prev=root;
    
    
    }

    void flatten(TreeNode* root) {
        TreeNode*prev=NULL;
        //Right Left Root (Building preorder from last right root)
            helper(root,prev);
    }
};



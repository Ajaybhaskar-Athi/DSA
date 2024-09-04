#include<bits/stdc++.h>
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
    void inorder(TreeNode*root,vector<int>&v){
        if(!root)return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
        return;
    }
    TreeNode*solve(vector<int>v,int s,int e){
        if(s>e)return NULL;
        int mid=(s+e)>>1;
        TreeNode*root=new TreeNode(v[mid]);
        root->left=solve(v,s,mid-1);
        root->right=solve(v,mid+1,e);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int>sorted_tree;
        inorder(root,sorted_tree);
        return solve(sorted_tree,0,sorted_tree.size()-1);
    }
};
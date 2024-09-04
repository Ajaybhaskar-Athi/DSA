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


//BRUTFORCE
/*
This method doesn’t require the tree to be a BST. Following are the steps. 

Traverse node by node(Inorder, preorder, etc.) 
For each node find all the nodes greater than that of the current node, sum the values. Store all these sums. 
Replace each node value with their corresponding sum by traversing in the same order as in Step 1.
*/

//TC=O(n^2);

class Solution {
public:
    unordered_map<TreeNode*,int>mp;
    
    void solve(TreeNode*root,int data,int &sum){
        if(!root )return;
        if(root->val>data)sum+=root->val;
        solve(root->left,data,sum);
        solve(root->right,data,sum);
        return;
    }

    void  calc_sum(TreeNode*root,TreeNode*target){
        if(!root || !target)return;
        int sum=0;
        solve(root,target->val,sum);
        mp[target]=sum;
        calc_sum(root,target->left);
        calc_sum(root,target->right);

    }
void Build(TreeNode*root){
        if(!root)return;
        root->val+=mp[root];
        Build(root->left);
        Build(root->right);
    }
        
    TreeNode* bstToGst(TreeNode* root) {
        calc_sum(root,root);  
   
  
        Build(root);
        return root;
    }
};




//OPTIMISEd  tc=o(n) reverse inorder we get in descending order 
/*
By leveraging the fact that the tree is a BST, we can find an O(n) solution. The idea is to traverse BST in reverse inorder.
Reverse inorder traversal of a BST gives us keys in decreasing order. Before visiting a node, we visit all greater nodes of that node.
While traversing we keep track of the sum of keys which is the sum of all the keys greater than the key of the current node. 
*/



class Solution {
public:
        void rev_inorder(TreeNode*root,int &sum){
            if(!root)return;
            rev_inorder(root->right,sum);
            sum+=root->val;
            root->val=sum;
            rev_inorder(root->left,sum);
                   
                    }

    TreeNode* bstToGst(TreeNode* root) {
        int sum=0;
        rev_inorder(root,sum);
        return root;
    }
};



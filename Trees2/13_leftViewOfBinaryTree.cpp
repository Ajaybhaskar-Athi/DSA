
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


void helper(TreeNode*root,vector<int>&res,int curLevel,int&maxLevel){
    if(!root)return;
    //if it was the first node of level;
    if(curLevel>maxLevel){
        res.push_back(root->val);
        maxLevel=curLevel;
    }
    helper(root->left,res,curLevel+1,maxLevel);
    helper(root->right,res,curLevel+1,maxLevel);
}


  vector<int> leftView(TreeNode*root){
    vector<int>res;
    int maxLevel=-1;
    int curLevel=0;
    helper(root,res,curLevel,maxLevel);
    return res;

  }
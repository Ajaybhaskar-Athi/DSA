/*
In a binary tree, nodes are considered siblings only if they share the same parent
. Therefore, even if nodes are on the same level (depth) in the tree but do not have the same parent,
 they are not siblings. Nodes that are fully on the leftmost or rightmost position at the same level are not siblings 
 unless they share a common parent.
*/

#include<bits/stdc++.h>
using namespace std;

class btnode
{
public:
    int data;
    btnode *left;
    btnode *right;
    btnode(int d) : data(d), left(NULL), right(NULL) {}
};

// NotLevelWise or Depth First Search
btnode*make_dfs(){
    int n;
    cin>>n;
    if(n==-1)return nullptr;
    btnode*root=new  btnode(n);
    root->left=make_dfs();
    root->right=make_dfs();
    return root;
}
void print_dfs(btnode*root){
        if(!root)return;
        cout<<root->data<<"-";
        if(root->left)cout<<root->left->data<<" ";
        if(root->right)cout<<root->right->data<<" ";
        print_dfs(root->left);
        print_dfs(root->right);
        return ;
}

    void helper(btnode*root,vector<int>&res){
        if(!root)return;
        if(!root->left && !root->right)return;
      if(root->left &&!root->right){
        res.push_back(root->left->data);
      }
      if(root->right && !root->left){
        res.push_back(root->right->data);
      }
      helper(root->left,res);
      helper(root->right,res);

    }

vector<int> printNoSiblings(btnode*root){
    vector<int>res;
    helper(root,res);
    return res;
}
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
void helper(btnode*root,vector<int>&res){
    if(!root)return;
    if(!root->left && !root->right)return;
    
    if(root->left && root->right){
        res.push_back(root->left->data);
        res.push_back(root->right->data);
    }
    helper(root->left,res);
    helper(root->right,res);
}

vector<int> printSiblings(btnode*root){
    vector<int>res;
    helper(root,res);
    return res;
}
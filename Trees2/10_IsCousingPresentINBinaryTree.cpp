

#include<bits/stdc++.h>
using namespace std;



class btnode
{
public:
    int val;
    btnode *left;
    btnode *right;
    btnode(int d) : val(d), left(NULL), right(NULL) {}
};


class Solution {
public:
    void helper_dfs(btnode*root,int x,int y,pair<int,int>&xv,pair<int,int>&yv,int depth){
        if(!root)return;
        if(xv.first!=0 && yv.first!=0)return; //already found

    if(root->left && root->left->val==x){
        xv.first=root->val;
    xv.second=depth+1;return;
    }
    if(root->left && root->left->val==y){
        yv.first=root->val;
        yv.second=depth+1;return;
    }
    if(root->right&&root->right->val==x){
        xv.first=root->val;
        xv.second=depth+1;return;
    }
     if(root->right&&root->right->val==y){
        yv.first=root->val;
        yv.second=depth+1;return;
    }
    helper_dfs(root->left,x,y,xv,yv,depth+1);
    helper_dfs(root->right,x,y,xv,yv,depth+1);

    }


    bool isCousins(btnode* root, int x, int y) {
        pair<int,int>xValues,yValues;//to store parent and their depths.Their by default values are zeroes
        helper_dfs(root,x,y,xValues,yValues,0);
        cout<<xValues.first<<" "<<yValues.first<<" "<<xValues.second<<" "<<yValues.second<<endl;
        if(xValues.first!=yValues.first && xValues.second==yValues.second)return true;
        return false;
    }
};
#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



vector<int> bottomView(TreeNode*root){
    if(!root)return {};
    map<int,int>mp;//hd,node->val
    queue<pair<TreeNode*,int>>q; 
    q.push({root,0});
    while(!q.empty()){
        TreeNode*f=q.front().first;
        int hd=q.front().second;
        q.pop();
        mp[hd]=f->val;//if we get same hd even we r adding it since its BFS and i want BOTTOM view. so last occured will be my ans

        if(f->left){
            q.push({f->left,hd-1});
        }
        if(f->right){
            q.push({f->right,hd+1});
        }


    }
    vector<int>res;
    for(auto v:mp){
        res.push_back(v.second);
    }
    return res;
    
}
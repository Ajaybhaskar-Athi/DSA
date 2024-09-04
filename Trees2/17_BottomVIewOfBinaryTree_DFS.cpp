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

void helper(TreeNode*root,map<int,pair<TreeNode*,int>>&mp,int hd,int level){
    if(!root)return;
     // Update the map if the current level is greater than the stored level for the same HD
  
    if(mp.find(hd)==mp.end() || level>mp[hd].second){
        mp[hd]={root,level};
    }
    helper(root->left,mp,hd-1,level+1);
    helper(root->right,mp,hd+1,level+1);

}
vector<int> bottomView(TreeNode*root){
    map<int,pair<TreeNode*,int>>mp;// hd,{node,level}
    helper(root,mp,0,0);
    vector<int>res;
    for(auto v:mp){
        res.push_back(v.second.first->val);
    }
    return res;
}

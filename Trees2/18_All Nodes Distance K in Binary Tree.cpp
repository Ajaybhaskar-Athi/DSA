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
  
    void populate_map(TreeNode*curr,TreeNode*parent,unordered_map<TreeNode*,TreeNode*>&mp){
        if(!curr)return;
        mp[curr]=parent;
        populate_map(curr->left,curr,mp);
        populate_map(curr->right,curr,mp);

    }
    
    void helper( unordered_map<TreeNode*,TreeNode*>&parentMap,set<TreeNode*>&s,vector<int>&ans,TreeNode*root,int k){
        if(!root)return;
        if(s.find(root)!=s.end())return;//already visited

        s.insert(root);
        if(k==0){ //reached kth distance node   
        ans.push_back(root->val);
        return;//dont go further no need
        }

        helper(parentMap,s,ans, root->left,k-1);//left 
        helper(parentMap,s,ans, root->right,k-1);//right
        helper(parentMap,s,ans, parentMap[root],k-1);//parent call


    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
      unordered_map<TreeNode*,TreeNode*>parentMap;//node & its parent
      set<TreeNode*>s;//if we traverse through parent and its childs then dont visit already visited one
      populate_map(root,nullptr,parentMap);

        vector<int>ans;
        helper(parentMap,s,ans,target,k);
        return ans;

    }
};

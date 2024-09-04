

#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    void findDepths(TreeNode*root,unordered_map<TreeNode*,int>&depths,int depth){
        if(!root)return;
        depths[root]=depth;
        findDepths(root->left,depths,depth+1);
        findDepths(root->right,depths,depth+1);

    }
    int find(TreeNode* root) {
        if(!root)return 0;
        unordered_map<TreeNode*,int>depths;
        findDepths(root,depths,0);
        int res=INT_MIN;
        for(auto v:depths){
            cout<<v.first->val<<" : "<<v.second<<endl;
            res=max(res,v.second);
        }
        return res+1;
    }
};


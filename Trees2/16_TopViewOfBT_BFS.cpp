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

vector<int> topView(TreeNode *root)
{
    vector<int> res;
    // int hd = 0; // horizontal distance
    unordered_map<int, TreeNode *> mp;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        TreeNode*f=q.front().first;
        int hd=q.front().second;
        q.pop();
            if(mp.find(hd)==mp.end()){
                mp[hd]=f;
            }

        if(f->left){
            q.push({f->left,hd-1});
        }
        if(f->right){
            q.push({f->left,hd+1});
        }
    }
    for(auto v:mp){
        res.push_back(v.second->val);
    }
    return res;
}

#include<bits/stdc++.h>
using namespace std;
/*


                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \      
                  10    14


                  In LevelORderTraversal we will do directly that if hd not occur then that must be included in top view since we r traversing level wise.


But in dfs if hd is occur again then we need to check whether its  current occured hd ka level  is less then  stored hd ka level, then add curr hd 

like in above at 14 hd value is 1 and its level is 2 , at 22 hd is 1 and its level is 1 . so lower level included in top view

*/
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

void helper(TreeNode* root, map<int, pair<TreeNode*, int>>& mp, int hd, int level) {
    if (!root) return;
    // Check if the current hd is seen for the first time or the current level is less than or equal to the stored level
    if (mp.find(hd) == mp.end() || level < mp[hd].second) {
        mp[hd] = {root, level};
    }
    helper(root->left, mp, hd - 1, level + 1);
    helper(root->right, mp, hd + 1, level + 1);
}

vector<int> topView(TreeNode* root) {
    vector<int> res;
    int hd = 0; // horizontal distance
    map<int, pair<TreeNode*, int>> mp; // hd, {node, level}
    helper(root, mp, hd, 0);
    for (auto v : mp) {
        res.push_back(v.second.first->val);
    }
    return res;
}

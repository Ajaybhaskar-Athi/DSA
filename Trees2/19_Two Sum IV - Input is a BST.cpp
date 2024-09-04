
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

//or u can use set also


class Solution {
public:
    bool helper(unordered_map<int,int>&mp,TreeNode*root,int k){
        if(!root)return false;
        if(mp.find(k-root->val)!=mp.end())return true;
            mp[root->val]=1;
            bool left=helper(mp,root->left,k);
            bool right=helper(mp,root->right,k);
        return left || right;

    }

    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int>mp;
      return  helper(mp,root,k);

    }
};


//Like Two sum II  we can use same method  by sorting (inorder ) and finding the target.
// /but above one is better since we no need to store elements and then iteration again


class Solution {
public:
    void inorder(TreeNode* root, vector<int>& elements) {
        if (!root) return;
        inorder(root->left, elements);
        elements.push_back(root->val);
        inorder(root->right, elements);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> elements;
        inorder(root, elements);

        // Use two pointers to find if there exist two numbers that add up to k
        int left = 0, right = elements.size() - 1;
        while (left < right) {
            int sum = elements[left] + elements[right];
            if (sum == k) {
                return true;
            } else if (sum < k) {
                ++left;
            } else {
                --right;
            }
        }

        return false;
    }
};


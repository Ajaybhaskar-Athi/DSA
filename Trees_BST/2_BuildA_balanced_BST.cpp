 //building balanced binary tree will be easyu wehn we have that elemnts are in sorted array

 /*
 If Elements are Sorted
Middle Element as Root: Choose the middle element of the sorted array to be the root of the BST. This ensures that the left and right subtrees are balanced.
Recursion: Recursively apply the same process to the left and right halves of the array to construct the left and right subtrees.
*/
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//Binary partiton will always built u a balanced binary search tree

class Solution {
public:
    TreeNode* helper(vector<int>&nums,int s,int e){
            if(s>e)return NULL;
                int mid=(s+e)/2;
    TreeNode*root= new TreeNode(nums[mid]);
        root->left=helper(nums,s,mid-1);
        root->right=helper(nums,mid+1,e);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
    return helper(nums,0,nums.size()-1);
    }
};

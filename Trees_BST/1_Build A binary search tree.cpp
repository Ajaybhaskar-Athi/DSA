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

TreeNode* make_BST(TreeNode*root,int data){
    if(!root)return new TreeNode(data);
    if(data<=root->val){
        root->left=make_BST(root->left,data);
    }else root->right=make_BST(root->right,data);
}
void print(TreeNode*root){
    if(!root)return;
    cout<<root->val<<" ";
    print(root->left);
    print(root->right);
}

int main(){
    TreeNode*root=NULL;
    vector<int>v={23,45,67,12,8};
    for(int ele:v){
        root=make_BST(root,ele);
    }
    print(root);
}


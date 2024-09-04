#include<bits/stdc++.h>
using namespace std;


class btNode{
    public:
    int data;
    btNode*left,*right;
    btNode(int val):data(val),left(NULL),right(NULL){}
};


btNode*deleteNodeInBT(btNode*root,int val){
    if(!root)return NULL;
    if(root->data==val){
        if(!root->left && !root->right)return nullptr;
        else if(!root->left || !root->right) return root->left==NULL?root->right:root->left;
        root->data=root->left->data;
        root->left=deleteNodeInBT(root->left,root->data);
        return root;
    }
    root->left=deleteNodeInBT(root->left,val);
    root->right=deleteNodeInBT(root->right,val);
}

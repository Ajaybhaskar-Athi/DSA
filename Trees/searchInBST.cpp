#include<bits/stdc++.h>
using namespace std;

class bstNode{
    public:
    int data;
    bstNode*left,*right;
    bstNode(int val):data(val),left(NULL),right(NULL){}
};


bstNode*make_breadth(){
    int val;
    cout<<"Enter the Root value: ";
    cin>>val;
    if(val==-1)return NULL;
    bstNode*root=new bstNode(val);
    queue<bstNode*>q;
    q.push(root);
    while(!q.empty()){
        bstNode*f=q.front();
        q.pop();
        cout<<"Enter left and Right childs of "<<f->data<<" ";
        int lc=-1,rc=-1;
        cin>>lc>>rc;
        if(lc!=-1){
            f->left=new bstNode(lc);
            q.push(f->left);
        }
        if(rc!=-1){
            f->right=new bstNode(rc);
            q.push(f->right);
        }

    }
    return root;
}

void print_levelWise(bstNode*root){
    if(!root)return;
    queue<bstNode*>q;
    q.push(root);
    while(!q.empty()){
        bstNode*f=q.front();
        q.pop();
        cout<<f->data<<"-";
        if(f->left){
            cout<<f->left->data<<" ";
            q.push(f->left);
        }
        if(f->right){
            cout<<f->right->data<<" ";
            q.push(f->right);
        }
        cout<<endl;
    }
    return;
}

bool search(bstNode*root,int val)
{
    if(!root)return false;
    if(root->data==val)return true;
    else if(root->data>val)return search(root->left,val);
    else return search(root->right,val);
}

int main(){
    bstNode*root=make_breadth();
    print_levelWise(root);
    cout<<"Enter the searching value: ";
    int n;cin>>n;
    bool res=search(root,n);
    if(res)cout<<"Found";
    else cout<<"not found";
}
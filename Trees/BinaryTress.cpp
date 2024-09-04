#include <bits/stdc++.h>
using namespace std;

class btnode
{
public:
    int data;
    btnode *left;
    btnode *right;
    btnode(int d) : data(d), left(NULL), right(NULL) {}
};

// NotLevelWise or Depth First Search
btnode*make_dfs(){
    int n;
    cin>>n;
    if(n==-1)return nullptr;
    btnode*root=new  btnode(n);
    root->left=make_dfs();
    root->right=make_dfs();
    return root;
}
void print_dfs(btnode*root){
        if(!root)return;
        cout<<root->data<<"-";
        if(root->left)cout<<root->left->data<<" ";
        if(root->right)cout<<root->right->data<<" ";
        print_dfs(root->left);
        print_dfs(root->right);
        return ;
}




//LevelWise 

btnode*make_level(){
    int n;
    cin>>n;
    queue<btnode*>q;
    if(n==-1)return nullptr;
    btnode*root=new btnode(n);
    q.push(root);
    while(!q.empty()){
        btnode*f=q.front();
        q.pop();
        int lc=-1;
        int rc=-1;
        cout<<"Enter Left and Right Childs of "<<f->data<<" ";
        cin>>lc>>rc;
        if(lc!=-1){
          f->left=new btnode(lc);
            q.push(f->left);
        }
        if(rc!=-1){
          f->right=new btnode(rc);
            q.push(f->right);
        }
        
        
    }
    return root;
}

void print_levelWise(btnode*root){
    if(!root)return;
    queue<btnode*>q;
    q.push(root);
    while(!q.empty()){
        btnode*f=q.front();
        q.pop();
        cout<<f->data<<"-";
        if(f->left){
            cout<<f->left->data<<" ";
            q.push(f->left);
    }
    if(f->right){
        cout<<f->right->data;
        q.push(f->right);
    }
    cout<<endl;

}
return;
}

int main(){
    btnode*root=make_level();
    print_levelWise(root);
}
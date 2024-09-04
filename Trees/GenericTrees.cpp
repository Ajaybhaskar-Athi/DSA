// Depth First Search Traversal
/*

#include<bits/stdc++.h>
using namespace std;
class GTnode{
    public:
    int data;
vector<GTnode*>child;
GTnode(int d):data(d){}
};

GTnode*make(){

    cout<<"Enter the Root value: ";
    int val;
    cin>>val;
    if(val==-1)return NULL;
    GTnode*root=new GTnode(val);
    int n;
    cout<<"Enter No of Childs it have: ";
    cin>>n;
    for(int i=0;i<n;i++){
        root->child.push_back(make());
    }

    return root;
}


void print(GTnode*root){
    cout<<root->data<<"->";
    for(int i=0;i<root->child.size();i++){
            cout<<root->child[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->child.size();i++){
        print(root->child[i]);
    }
    return;
}
int main(){
    GTnode*root=make();
        print(root);
}

*/



// LEvel Wise Traversal




#include<bits/stdc++.h>
using namespace std;
class gtnode{
    public:
    int data;
    vector<gtnode*>child;
    gtnode(int d):data(d){}
};

gtnode*make(){
    queue<gtnode*>q;

    cout<<"enter root value:";
    int val;
    cin>>val;
    if(val==-1)return nullptr;
gtnode*root=new gtnode(val);
q.push(root);
while(!q.empty()){
    gtnode*f=q.front();
    q.pop();
    cout<<"Enter the no of childs "<<f->data<<" have: ";
    int n;cin>>n;
    cout<<"Enter the child values: ";
    for(int i=0;i<n;i++){
        int cv;
        cin>>cv;
        gtnode*childNode=new gtnode(cv);
        f->child.push_back(childNode);
        q.push(childNode);
    }
}

return root;

}

void print(gtnode*root){

    queue<gtnode*>q;
    q.push(root);
    while(!q.empty()){
        gtnode*f=q.front();
        q.pop();
        cout<<f->data<<"-";
        for(int i=0;i<f->child.size();i++){
            cout<<f->child[i]->data<<" ";
            q.push(f->child[i]);
        }
        cout<<endl;
    }
    return;
}
////////////////////////////////
int maxDepth(gtnode*root){
    if(!root)return 0;
    int ans=0;
    for(int i=0;i<root->child.size();i++){
        int tempans=maxDepth(root->child[i]);
        ans=max(ans,tempans);
    }
    return ans+1;
}
///////////////////////
void preorder(gtnode*root){
    if(!root)return ;
    cout<<root->data<<" ";
    for(int i=0;i<root->child.size();i++){
         preorder(root->child[i]);
    }
    return;
}

void postorder(gtnode*root){
    if(!root)return;
    for(int i=0;i<root->child.size();i++){
        postorder(root->child[i]);
    }
    cout<<root->data<<" ";
    return;
}
int main(){
    gtnode*root=make();
    print(root);
}
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> make_matrix(){
    int n,e;
    cout<<"Enter No of Nodes And Edges In a graph: ";
    cin>>n>>e; //n=vertices and e=edges
    //make Mtarix;
    vector<vector<int>>g(n,vector<int>(n,0));
    for(int i=0;i<e;i++){
    int a,b;
    cout<<"Give Nodes With Direct Edges: ";
    cin>>a>>b;
    if(a<n && b<n){
        g[a][b]=1;
        g[b][a]=1;
    }
    }
    return g;
}
void print(vector<vector<int>>g){
    for(auto v:g){
        for(int e:v){
            cout<<e<<" ";
        }cout<<endl;
    }
}

int main(){
    vector<vector<int>>g=make_matrix();
    print(g);

}
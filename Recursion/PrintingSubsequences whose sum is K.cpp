#include<bits/stdc++.h>
using namespace std;

void fun(int ind,vector<int>&ds,int s,int sum,int arr[],int n){
    if(ind==n){
        if(s==sum){
                for(int ele:ds){
                    cout<<ele<<" ";
                }
                if(ds.size()==0)cout<<"{}";
                cout<<endl;
        }
        return;
    }

    ds.push_back(arr[ind]);
    s+=arr[ind];
    fun(ind+1,ds,s,sum,arr,n);

    ds.pop_back();
    s-=arr[ind];
      fun(ind+1,ds,s,sum,arr,n);

}

int main(){
    int arr[]={1,2,1};
    int n=3;
    int sum=2;
    vector<int>ds;
    fun(0,ds,0,sum,arr,n);
}

//TC=O(2^n); since for every element we have two options take or not so 2^n

// 1 1 
// 2
#include<bits/stdc++.h>
using namespace std;

bool fun(int ind,vector<int>&ds,int s,int sum,int arr[],int n){
    if(ind==n){
        if(s==sum){
                for(int ele:ds){
                    cout<<ele<<" ";
                }cout<<endl;
                return true;
        }
        return false;
    }

    ds.push_back(arr[ind]);
    s+=arr[ind];
    if(fun(ind+1,ds,s,sum,arr,n)==true){
        return true;
    }

    ds.pop_back();
    s-=arr[ind];
    if(  fun(ind+1,ds,s,sum,arr,n)==true){
        return true;
    }
    return false;

}

int main(){
    int arr[]={1,2,1};
    int n=3;
    int sum=2;
    vector<int>ds;
    fun(0,ds,0,sum,arr,n);
}

//TC=O(2^n);

// 1 1 

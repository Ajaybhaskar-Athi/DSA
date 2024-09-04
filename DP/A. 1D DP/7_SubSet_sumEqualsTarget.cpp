#include<bits/stdc++.h>
using namespace std;

//Helper2 or Helper1 Anything is fine


    bool helper2(int idx,vector<int>arr,int k,int sum){
        int n=arr.size();
        if(idx==n){
            if(sum==k)return true;
            return false;
        }
        sum+=arr[idx];
       if(helper2(idx+1,arr,k,sum)){
        return true;
       }
       
        sum-=arr[idx];
       if( helper2(idx+1,arr,k,sum))return true;
        return false;
        
    }
    

bool helper(int idx,vector<int>arr,int k){
    if(k==0)return true;
    if(idx==0)return arr[idx]==k;
    
    bool take=false;
    if(k>=arr[idx]){
        take=helper(idx-1,arr,k-arr[idx]);
    }
    bool NotTake=helper(idx-1,arr,k);
    return take || NotTake;
}

bool subset_sum(vector<int>arr,int target){
    // return helper(arr.size()-1,arr,target);
    return helper2(0,arr,target,0);
}






int main(){
    vector<int>arr={1,2,3,4};
    int k=2;
    if(subset_sum(arr,k)){
        cout<<"Yes it Was Present";
    }else cout<<"No";
}


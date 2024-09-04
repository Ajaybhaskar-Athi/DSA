#include<bits/stdc++.h>
using namespace std;

int fun(int ind,int s,int sum,int arr[],int n){
    if(ind==n){
        if(s==sum){
             return 1;
        }
      else   return 0;
    }

    s+=arr[ind];
   int left= fun(ind+1,s,sum,arr,n);

    s-=arr[ind];
     int right= fun(ind+1,s,sum,arr,n);

     return left+right;

}

int main(){
    int arr[]={1,2,1};
    int n=3;
    int sum=2;
    fun(0,0,sum,arr,n);
}
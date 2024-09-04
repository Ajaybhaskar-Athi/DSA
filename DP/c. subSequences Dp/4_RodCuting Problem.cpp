#include<bits/stdc++.h>
using namespace std;

// method 1: RECURSION TC =O(2^N) this is exponenetial time compplexity which was bad when N becomes large

int f(int idx,int N,vector<int>&price){
    if(idx==0)return  N*price[0];
    int notTake=0+f(idx-1,N,price);
    int take=INT_MIN;
    int rodLen=idx+1; //small part length
    if(rodLen<=N){
        take=price[idx]+f(idx,N-rodLen,price);
    }
    return max(take,notTake);

}


int cutRod(vector<int>&price,int n){
    return f(n-1,n,price);
}

int main(){
    vector<int>v{2,5,7,8,10};
    cout<<cutRod(v,5); //output is 12.

}

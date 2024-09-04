#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    // int count=0;
    void helper(vector<int>arr,int idx,int p,int k,int &count){
        int n=arr.size();
        if(idx==n){
            if(p<k)count++;
            return;
        }
        p*=arr[idx];
        helper(arr,idx+1,p,k,count);
        p/=arr[idx];
        helper(arr,idx+1,p,k,count);

    }
int count_sub(vector<int>v,int k){
        int count=0;
   helper(v,0,1,k,count);
    return count-1; //subtarcting empty subsequence
    
}

};

int main(){
    solution  obj;
    int k=10;
   int ans= obj.count_sub({4,8,7,2},50);
        cout<< ans;

}
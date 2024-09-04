#include<bits/stdc++.h>
using namespace std;



void fun(int ind,vector<int>ds,int arr[],int n){
    if(ind==n){
        for(auto it:ds){
            cout<<it<<" ";
        }
        
        if(ds.size()==0){
           cout<<"{}";
        }
         cout<<endl;
        return;
    }
    //take or pick the particular index into the subsequence
    ds.push_back(arr[ind]);
    fun(ind+1,ds,arr,n);
    ds.pop_back();
    //Not pick,or not take conditio ,this element is adde to your subSequence
      fun(ind+1,ds,arr,n);
        

}

int main(){
    int arr[]={3,1,2};
    int n=3;//size;
    vector<int>ds;
    fun(0,ds,arr,n);
}
// the time complexity of the fun function is O(2^N) (ofcourse bad), where N is the size of the input array arr.

//output: it was printing 

// 3 1 2 
// 3 1 
// 3 2 
// 3
// 1 2
// 1
// 2
// {}

// we can reverse it by doing  this
//   //Not pick,or not take conditio ,this element is adde to your subSequence
//       fun(ind+1,ds,arr,n);
//       before ds.push_back();


// {}
// 2
// 1
// 1 2
// 3
// 3 2
// 3 1
// 3 1 2
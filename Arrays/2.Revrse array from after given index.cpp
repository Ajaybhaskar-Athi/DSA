// #include<bits/stdc++.h>
// using namespace std;

// vector<int> rev(vector<int>& arr, int m) {
//     int len = arr.size();
//     int mid = (m + len) / 2;
//     for (int i = m + 1; i < mid; ++i) {
//         swap(arr[i], arr[len - (i - m)]);
//     }
//     return arr;
// }

// int main() {
//     vector<int> v = {1, 2, 3, 4, 5, 6};
//     v = rev(v, 1);
//     for (auto ele : v) {
//         cout << ele << " ";
//     }
// }




#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v={1,2,3,4,5,6};
    int n=v.size();
    int idx=1;
    int mid=(idx+1+n)/2;

    for(int i=idx+1;i<=mid;i++){
        int temp=v[i];
        v[i]=v[n-i+1];
        v[n-i+1]=temp;
    }
    for(int ele:v)cout<<ele<<" ";

    

    }



    // int s=1;
   
    // int e=v.size()-1;
    // while(s<e){
    //     swap(v[s],v[e]);
    //     s++;
    //     e--;
    // }
    // for(int e:v)cout<<e<<" ";
//its also done same withs same o(n/2) complexity
#include<bits/stdc++.h>
using namespace std;


//Tc=O(n*n)
class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        int ans=1;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int c=1;
            for(int j=i+1;j<n;j++){
                if( (arr[i]<=arr[j] && dep[i]>=arr[j] ) ||  (arr[j]<=arr[i] && dep[j]>=arr[i])   ){
                    c++;
                }
            }
            ans=max(ans,c);
        }
        return ans;
    }
};


//Tc=O(n log n);

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int n=dep.size();
        
        
        int i = 1;  // Pointer for arrivals
         int j = 0;  // Pointer for departures
            int plat_needed = 1;  // At least one platform needed initially
            int ans = 1;  // ans to keep track of maximum platforms required
            
            while(i<n && j<n){ 
                if(arr[i]<=dep[j]){ //one more platform needed
                    plat_needed++;
                    i++;
                }else{  //one platform can be reduced
                    j++;
                    plat_needed--;
                }
                 ans=max(plat_needed,ans);
            }
            return ans;
    }
};

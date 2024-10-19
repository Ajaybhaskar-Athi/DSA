#include<bits/stdc++.h>
using namespace std;
/*
Input:
N = 10, K = 5
arr[] = {5, -2, 5, -4, 5, -12, 5, 5, 5, 20}
Output:
68
Explanation:
Here  we have k=5 so we turn -2, -4, -12 to
2, 4, and 12 respectively. Since we have
performed 3 operations so k is now 2. To get
maximum sum of array we can turn positive
turned 2 into negative and then positive
again so k is 0. Now sum is
5+5+4+5+12+5+5+5+20+2 = 68
*/

class Solution{
    public:
    int find_min(long long int a[],int n){
        return min_element(a,a+n)-a;
    }
    long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
        while(k>0){
        int mini=find_min(a,n);
         a[mini]=-a[mini];
        k--;
        }
long long int sum=accumulate(a,a+n,0);
return sum;
    }
};

//But TC =O(n*K) => leads to TLE error

// II Method:

/*- sort the array
- negate all negative elements 
- After negating negative elements if remeaining k is even then it will be cancelled out 
- if remaing k is odd then remove the least absolute value 
*/



class Solution{
    public:
    
    long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
        sort(a,a+n);
      for(int i=0;i<n && k>0;i++){
          if(a[i]<0){
              k--;
              a[i]=-a[i];
          }else break;
      }
      //suppose if k is remaing and it is odd
      if(k%2!=0) {
          int mini=min_element(a,a+n)-a;
          a[mini]=-a[mini];
      }
long long int sum=accumulate(a,a+n,0);
return sum;
    }
};

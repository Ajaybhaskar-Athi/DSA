#include<bits/stdc++.h>
using namespace std;

//GFG
//in cpp direct number % 10**9+7 is not allowed u need to decalre it as constant in ellaborated way and then perform modulo

class Solution {
  public:
  const long long MOD = 1000000007;
    int Maximize(vector<int> &arr) {
        // Complete the function
        sort(arr.begin(),arr.end());
        int sum=0,n=arr.size();
        for(int i=0;i<n;i++){
            sum+=(arr[i]*i)%MOD;
        }
        return sum % MOD;
    }
};

//Even after this some large inputs give TLE error
//so use sum datatype as long long to prevent overflow and typecast it

class Solution {
public:
    const long long MOD = 1000000007;

    int Maximize(std::vector<int> &arr) {
        std::sort(arr.begin(), arr.end());

        long long sum = 0;  
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            // Calculate the sum with modulo
            sum = (sum + (static_cast<long long>(arr[i]) * i) % MOD) % MOD;
        }
        
        return static_cast<int>(sum); // Cast back to int for return
    }
};

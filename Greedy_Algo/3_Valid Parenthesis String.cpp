#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool checkValidString(string s) {
        int left=0,right=0,n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='*')left++;
             else left--;
            if(s[n-1-i]==')' || s[n-1-i]=='*')right++;
            else right--;

            if(left<0 || right<0)return false;
        }
        return true;
      
    }
};

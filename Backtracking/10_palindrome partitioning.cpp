
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<string>>ans;
    
    bool isPalindrome(string s){
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    
    
  void helper(int idx,string s,vector<string>v){
        int n=s.size();
        
        if(idx==n){
            ans.push_back(v);
            return;
        }
        
            string t="";
        for(int i=idx;i<n;i++){
         t+=s[i];
         if(isPalindrome(t)){
             v.push_back(t);
             helper(i+1,s,v);
             v.pop_back();
         }
        }
      
  }
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        vector<string>v;
        helper(0,S,v);
            return ans;
        
    }
    
};
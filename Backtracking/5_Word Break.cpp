#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
        bool helper(int start,string s,unordered_set<string>&dict,unordered_map<int,bool>&dp){
            if(start==s.length())return true;
            if(dp.find(start)!=dp.end())return  dp[start];
            for( string w:dict){
                int end=start+w.length();
                if(end<=s.length()  && s.substr(start,w.length())==w){
                    if(helper(end,s,dict,dp))return dp[start]= true;
                }
            }
            return dp[start]= false;
        }


    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>dict(wordDict.begin(),wordDict.end());//searching is easy in this with o(1) tc
        unordered_map<int,bool>dp;
        return helper(0,s,dict,dp);
    }
};




/*

  vector<string> d = { "mobile", "samsung",  "sam",  "sung", "man",
                         "mango",  "icecream", "and",  "go",   "i",
                         "like",   "ice",      "cream" };

s="ilikelikeimangoiii";



In the given problem, when checking the string s = "ilikelikeimangoiii" against the dictionary, 
once we find a valid word (e.g., "i" at index 11), we don't need to recheck the substrings after it (like "like" or "ice"), 
as we already know that those segments lead to a successful decomposition. This is where memoization becomes useful:
 it stores the results of previously computed indices, allowing us to skip redundant checks and improve efficiency,
  ensuring that once we determine the feasibility of segmenting the string from a specific index, 
  we can reuse that result instead of recalculating it.

*/


//tabulation



class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end()); // For O(1) lookups
        int n = s.length();
        
        vector<bool> dp(n + 1, false);
        dp[n] = true; 

        for (int start = n - 1; start >= 0; start--) {
            for (const string& w : dict) {
                int end = start + w.length(); 
                if (end <= n && s.substr(start, w.length()) == w) { 
                    dp[start] = dp[start] || dp[end]; 
                    if (dp[start]) break; // Break if a valid segmentation is found
                }
            }
        }

        return dp[0]; // Return if the whole string can be segmented
    }
};

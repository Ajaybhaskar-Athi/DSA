


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
       vector<string>ans;
        void helper(int idx,string s,string curr_s,unordered_set<string>&wordSet){
                int n=s.length();
                if(idx==n){   
                    cout<<curr_s<<" ";
                    curr_s.pop_back();
                    ans.push_back(curr_s);
                    return;
                }

            string word="";             
            for(int i=idx;i<n;i++){    
                word+=s[i];
                if(wordSet.find(word)!=wordSet.end()) helper(i+1,s,curr_s+word+" ",wordSet);
            }
        }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>wordSet(wordDict.begin(),wordDict.end());
        helper(0,s,"",wordSet);
        return ans;
    }
};


#include<bits/stdc++.h>
using namespace std;

//leetcode

class Solution {
public:
    string reorganizeString(string s) {
       priority_queue<pair<int,char>>pq;//max heap: count,char
        vector<int>max_char(26,0);
        for (char c : s) {
            max_char[c - 'a']++;
        }
      for (char c = 'a'; c <= 'z'; c++) {
            if (max_char[c - 'a'] > 0) {
                pq.push({max_char[c - 'a'], c}); // Only push if count > 0
            }
        }


        pair<int,char>prev={-1,'#'};
        string res="";
        while(!pq.empty()){
            pair<int,char>key=pq.top();
              pq.pop();
            res+= key.second;
            if(prev.first>0){
                pq.push(prev);
            }  
            prev={--key.first,key.second};
        }

      return res.length() == s.length() ? res : "";
    
    }
};
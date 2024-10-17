#include<bits/stdc++.h>
using namespace std;

//Leetcode
class Solution {
public:
// Each frog must complete the sequence "croak" in the exact order: 'c' -> 'r' -> 'o' -> 'a' -> 'k'
    int minNumberOfFrogs(string s) {
            int n=s.size();
            if(n%5!=0)return -1;
            unordered_map<char,int>mp;
            int active_frogs=0,ans=0;
            for(char ch:s){
                if(ch=='c')active_frogs++,mp['c']++;
                else if(ch=='r' && mp['c']>mp['r'])mp['r']++;
                else if(ch=='o' && mp['r']>mp['o'])mp['o']++;
                else if(ch=='a' && mp['o']>mp['a'])mp['a']++;
                else if(ch=='k' && mp['a']>mp['k']){
                    ans=max(ans,active_frogs);
                    active_frogs--; // A frog finishes its croak
                    mp['k']++;
                }
                else return -1;
            }
            return active_frogs==0 ? ans:-1;
    }
};
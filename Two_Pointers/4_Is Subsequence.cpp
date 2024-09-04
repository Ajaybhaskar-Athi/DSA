#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isSubsequence(string s, string t) {
        int si=0,ti=0; //s index and t index
        while( si< s.size() && ti<t.size()){
            if(s[si]==t[ti])si++;
            ti++;
        }
        return si==s.size();
    }
};

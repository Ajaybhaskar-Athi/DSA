#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (s.size() == 0) return 0; //if no coookies
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int j = 0;
        int ans = 0; 
            //Traversing through Childrens
        for (int i = 0; i < g.size(); i++) {
            // cookie that satisfies  current child's greed factor
            while (j < s.size() && g[i] > s[j]) {
                j++;
            }
            if (j < s.size() && s[j] >= g[i]) { //cookie is Found
                ans++;
                j++;
            }
            if(j>=s.size())break; //if cookies over
        }
        
        return ans; 
    }
};


//Traversing THrpugh Cookies Array

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (s.size() == 0) return 0; //if no coookies
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int l=0;//cookie size arr s
        int r=0;//greed factor child arr g
        //traversing through cookies
        while(l<s.size() && r<g.size() ){
            if(s[l]>=g[r])r++;
            l++;
        }
        return r; 
    }
};


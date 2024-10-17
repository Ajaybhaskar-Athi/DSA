#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    
    bool static cmp(pair<int,int>&a,pair<int,int>&b){
        if(a.first!=b.first)return a.first<b.first;
        return a.second<b.second;
    }

    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({price[i],i+1});
        }
        sort(v.begin(),v.end(),cmp);
        int ans=0;
        for(int i=0;i<n;i++){
            int j=1;
            while(v[i].first<=k  && j<=v[i].second){
                    ans++;
                    k-=v[i].first;
                    j++;
            }
        }
        return ans;
    }
};


//Else u can do without while loop



class Solution {
public:
    bool static cmp(pair<int,int>&a,pair<int,int>&b){
        if(a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    }

    int buyMaximumProducts(int n, int k, int price[]){
        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++){
            v.push_back({price[i], i + 1});
        }
        sort(v.begin(), v.end(), cmp);
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            int maxStocks = min(v[i].second, k / v[i].first);
            ans += maxStocks;
            k -= maxStocks * v[i].first;
            if(k <= 0) break;
        }
        return ans;
    }
};

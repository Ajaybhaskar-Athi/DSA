#include<bits/stdc++.h>
using namespace std;

class Solution {
public:


    vector<vector<int>> merge(vector<vector<int>>& v) {

            sort(v.begin(),v.end()); //default sorting sorts acc to 1st element
            vector<vector<int>>ans;
            ans.push_back({v[0][0],v[0][1]});
            
            for(int i=1;i<v.size();i++){
                if(v[i][0]<=ans.back()[1]){
                    ans.back()[1]=max(ans.back()[1],v[i][1]);
                }
                else{
                    ans.push_back({v[i]});
                }
            }
            return ans;
    }
};







//same but without ans.back() method  

class Solution {
public:

        bool static compareSort(vector<int>&a,vector<int>&b){
            return a[0]<b[0];
        }

    vector<vector<int>> merge(vector<vector<int>>& v) {

            sort(v.begin(),v.end(),compareSort);
            vector<vector<int>>ans;
            int pe=v[0][1]; //previous end
            int ps=v[0][0];//previous start
            ans.push_back({ps,pe});
        
            for(int i=1;i<v.size();i++){
                if(v[i][0]<=pe){
                    ans.pop_back();
                    if(v[i][1]>pe)pe=v[i][1];
                    ans.push_back({ps,pe});
                }
                else{
                    ps=v[i][0];
                    pe=v[i][1];
                    ans.push_back({ps,pe});
                }
            }
            return ans;
    }
};

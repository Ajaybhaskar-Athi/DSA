#include<bits/stdc++.h>
using namespace std;

class solution{
    public:

        bool static comparePairs(const pair<int,int>&a,pair<int,int>&b){
            return a.second<b.second; //sorting acc to end time
        }
      void maxMeetings( vector<int>&s, vector<int>&e) {
                vector<pair<int,int>>v;
                for(int i=0;i<s.size();i++){
                    v.push_back({s[i],e[i]});
                }
                //after sorting v= { {1,2},{3,4},{0,5},{5,7},{5,9},{8,9} }
                sort(v.begin(),v.end(),comparePairs);
                int count=1;
                int prevEnd=v[0].second;
                for(int i=1;i<v.size();i++){
                    if(v[i].first>prevEnd){
                        count++;
                        prevEnd=v[i].second;
                    }
                }
                cout<<count<<endl;
                

            }

};

int main(){
    vector<int>s={0,3,1,5,5,8};
    vector<int>e={5,4,2,9,7,9};
    //  vector<int> s = {10, 12, 20};
    // vector<int> e = {20,25,30};
    solution obj;
    obj.maxMeetings(s,e);
}
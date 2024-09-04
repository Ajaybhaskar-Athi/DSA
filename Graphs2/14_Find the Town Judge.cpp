#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>outDegree(n+1,0);//judge doesnt trust anyone
        vector<int>inDegree(n+1,0);
    
            for(auto  v:trust){
                    int a=v[0];
                    int b=v[1];
                    outDegree[a]++;
                    inDegree[b]++;
            }
    //1-->2-->3    this is a graph no trust relation exists here 
    for(int i=1;i<=n;i++){
        if(outDegree[i]==0 && inDegree[i]==n-1){ //judge doenst trust anyone And Judge was trusted by all people except him
          return i;
        }
    }
    return -1;
    }

};
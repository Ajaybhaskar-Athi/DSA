#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indeg(numCourses,0);
        vector<vector<int>>g(numCourses);
        for(auto v:prerequisites){
            int a=v[0];
            int b=v[1];
            g[b].push_back(a); //b->a edge
            indeg[a]++;
        }
        queue<int>q;
        for( int i=0;i<numCourses;i++){
            if(indeg[i]==0)q.push(i);
        }
       

        int processed=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            processed++;
            for(int nbr:g[node]){
                indeg[nbr]--;
                if(indeg[nbr]==0)q.push(nbr);
            }

        }
        return processed==numCourses;
    }
};
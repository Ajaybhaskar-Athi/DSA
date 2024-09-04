#include<bits/stdc++.h>
using namespace std;

//Will work only if graph has no cycl;e
/*
class Solution {
public:
        void toposort(vector<vector<int>>&g,vector<int>&vis,stack<int>&stk,int node){
            vis[node]=1;
            for(int nbr:g[node]){
             if(!vis[node])   toposort(g,vis,stk,nbr);
            }
            stk.push(node);
        }

    vector<int> findOrder(int numCourses, vector<vector<int>>& edges) {
        //same as toplogical sorting .in topo sort if a->b edge then a will come before b
        //here i a->b b will come before a .so in making edges u should make b->a since given b happen before a;
        vector<vector<int>>g(numCourses);
        for(auto v:edges){
            int a=v[0];
            int b=v[1];
            g[b].push_back(a);
        }
        vector<int>vis(g.size(),0);
            stack<int>stk;
       for(int i=0;i<vis.size();i++){
        if(!vis[i])toposort(g,vis,stk,i);
       }
       
        vector<int>res;
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }   
};

These Will Work untill THERES No Cycle in A Graph BUt When The Grah Have Cycle It Doesnot handle to return empty Array .
Thats Why we are not doing this problem using dfs_toposorting. Use kahns Algorithm

*/

//Before doing kahns algo Lets COmbine this DFS toposort with our Detection Of Cylce by maintaing path And if cycle detect false
//THis Code Works Fine.

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool toposort(vector<vector<int>>& g, vector<int>& vis, vector<int>& rec_stack, vector<int>& stk, int node) {
        vis[node] = 1;         // Mark node as visited
        rec_stack[node] = 1;   // Mark node as in recursion stack

        for (int nbr : g[node]) {
            if (rec_stack[nbr]) return true; // Cycle detected
            if (!vis[nbr]) {
                if (toposort(g, vis, rec_stack, stk, nbr)) return true; // Propagate cycle detection
            }
        }

        rec_stack[node] = 0; // Unmark node as in recursion stack
        stk.push_back(node); // Push node to stack after all neighbors are visited
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        for (auto& v : prerequisites) {
            int a = v[0];
            int b = v[1];
            g[b].push_back(a); // Directed edge from b to a SInce given that if [a,b] then a course completed after b .so b->a;
        }

        vector<int> vis(numCourses, 0);
        vector<int> rec_stack(numCourses, 0);
        vector<int> stk; // Use vector as stack for topological sort

        for (int i = 0; i < numCourses; ++i) {
            if (!vis[i]) {
                if (toposort(g, vis, rec_stack, stk, i)) return {}; // Cycle detected
            }
        }

        reverse(stk.begin(), stk.end()); // Topological order
        return stk;
    }
};


//Refer CousrseSchedule_II_kahnsAlgo File to get that Algo

//Ssame as M coloring problem


/*

You have n gardens, labeled from 1 to n, and an array paths where paths[i] = [xi, yi] describes a bidirectional path between garden xi to garden yi. In each garden, you want to plant one of 4 types of flowers.

All gardens have at most 3 paths coming into or leaving it.

Your task is to choose a flower type for each garden such that, for any two gardens connected by a path, they have different types of flowers.

Return any such a choice as an array answer, where answer[i] is the type of flower planted in the (i+1)th garden. The flower types are denoted 1, 2, 3, or 4. It is guaranteed an answer exists.

 

Example 1:

Input: n = 3, paths = [[1,2],[2,3],[3,1]]
Output: [1,2,3]
Explanation:
Gardens 1 and 2 have different types.
Gardens 2 and 3 have different types.
Gardens 3 and 1 have different types.
Hence, [1,2,3] is a valid answer. Other valid answers include [1,2,4], [1,4,2], and [3,2,1].
Example 2:

Input: n = 4, paths = [[1,2],[3,4]]
Output: [1,2,1,2]
Example 3:

Input: n = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
Output: [1,2,3,4]
 

Constraints:

1 <= n <= 104
0 <= paths.length <= 2 * 104
paths[i].length == 2
1 <= xi, yi <= n
xi != yi
Every garden has at most 3 paths coming into or leaving it.
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isPossible(int flow,int node,vector<vector<int>>graph,vector<int>flowers,int n){
        for(int nbr:graph[node]){
            if(flowers[nbr]==flow)return false;
        }
        return true;
    }

    bool solve(int node,vector<vector<int>>&graph,vector<int>&flowers,int n){
        if(node==n){
            return true;//all gardens colored
        }

        for(int i=1;i<=4;i++){ //coloring evry node with either one of 4 colors and checking which color will fit
            if(isPossible(i,node,graph,flowers,n)){
                flowers[node]=i;
                if(solve(node+1,graph,flowers,n)) return true;
                flowers[node]=0;
            }
        }
        return false;
    }


    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>>g(n);//we are labelling from 0->n-1 .g[0] is 1st garden
        for(auto v:paths){
                g[v[0]-1].push_back(v[1]-1);//doing -1 since we r taking 0 baseed indexing.use this  g[v[0]].push(v[1])  when we initailse graph with g(n+1)
                g[v[1]-1].push_back(v[0]-1);
            }
        
        vector<int>flowers(n,0);//simply like colors array in M coloring problem

        solve(0,g,flowers,n);
        return flowers;
    }
};




//But It Taking So much Long time in doing backtracking of unnecessary color combonations
//Use BFs/DFS/Greedy



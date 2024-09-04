
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size()+1; //given edges length no of verties =edges +1;
        vector<int>deg(n+1,0);
        for(auto v:edges){
            int a=v[0];
            int b=v[1];
                deg[a]++;
                deg[b]++;
        }
        for(int i=1;i<=n;i++){
            if(deg[i]==n-1)return i;
        }
        return -1;
    }
};


//Method 2
/*The center node is the one that is connected to all other nodes.
Input: edges = [[1,2],[2,3],[4,2]]
Output: 2
Explanation: Node 2 is connected to every other node, so 2 is the center.

in a star graph, the center node will appear in both of the first two edges.
  So, we just need to check the common node in these two edges. ✨

 */

/*class Solution {
    public int findCenter(int[][] edges) {
        if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) {
            return edges[0][0];
        } else {
            return edges[0][1];
        }
    }
}
*/
#include<bits/stdc++.h>
using namespace std;



class Solution {
  public:
  
    void helper(int i,int j,vector<vector<int>>&mat,vector<vector<int>>&vis,vector<string>&ans,string sr){
                int n=mat.size();
                    if(i==n-1 && j==n-1) {
                        ans.push_back(sr);

                        return;
                    }
                
            if ( i+1<n && !vis[i+1][j] && mat[i+1][j]==1){
              
                vis[i][j]=1;
                helper(i+1,j,mat,vis,ans,sr+"D");
                vis[i][j]=0;
            }
            if(j+1<n&& !vis[i][j+1]&& mat[i][j+1]==1){
                    vis[i][j]=1;
                helper(i,j+1,mat,vis,ans,sr+"R");
                    vis[i][j]=0;
            }
            if(i-1>=0 && !vis[i-1][j] &&mat[i-1][j]==1){
                    vis[i][j]=1;
                helper(i-1,j,mat,vis,ans,sr+"U");
                    vis[i][j]=0;
            }
            if(j-1>=0&& !vis[i][j-1] && mat[i][j-1]==1){
                    vis[i][j]=1;
                helper(i,j-1,mat,vis,ans,sr+"L");
                    vis[i][j]=0;
            }
            
        
    }    
    
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        int n=mat.size();
        vector<string>ans;
        vector<vector<int>>vis(n,vector<int>(n,0));
       if (mat[0][0] == 1) helper(0,0,mat,vis,ans,"");
        return ans;
    }
};


int main(){
    Solution s;
    std::vector<std::vector<int>> matrix = {
    {1, 0, 0, 0},
    {1, 1, 0, 1},
    {1, 1, 0, 0},
    {0, 1, 1, 1}
};

vector<string>ans=s.findPath(matrix);
for(string ele:ans){
    cout<<ele<<" ";
}
}
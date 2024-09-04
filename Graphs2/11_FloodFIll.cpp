#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    void helper(vector<vector<int>>&g,int row,int col,int m,int n,int initColor,int newColor){
        if( row<0 || col<0 ||row>=m ||col>=n|| g[row][col]==newColor||g[row][col]!=initColor)return;
            g[row][col]=newColor;
            //call for left neighbour
            helper(g,row,col-1,m,n,initColor,newColor);
            //call for right neighbour
             helper(g,row,col+1,m,n,initColor,newColor);
            //call for upper neighbour
             helper(g,row-1,col,m,n,initColor,newColor);
             //call for down neighbour
              helper(g,row+1,col,m,n,initColor,newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int m=image.size();
    int n=image[0].size();
    int initColor=image[sr][sc];
     if (initColor == color) return image;
    helper(image,sr,sc,m,n,initColor,color);
    return image;

    }
};




#include<bits/stdc++.h>
using namespace std;



//Im fillig Here ROW wise (means i fill 1st row and then i go to 2nd row)
class Solution {
public:
  
            vector<vector<string>>ans;


        bool isSafe(int row,int col,int n,vector<string>&board){

                int dupRow=row,dupCol=col;
                //check left upper diagonals

                while(row>=0 &&col>=0){
                    if(board[row][col]=='Q')return false;
                    row--;
                    col--;
                }
                row=dupRow;
                col=dupCol;
                //check right upper diagonals
                while(row>=0 &&col<n){
                    if(board[row][col]=='Q')return false;
                    row--;
                    col++;
                }
                row=dupRow;
                col=dupCol;
                //check upper column;
                while(row>=0){
                    if(board[row][col]=='Q')return false;
                    row--;
                }

                //we will not check diagnoals in left &right, and lower column elemnts as they are not inserted yet
                return true;
        }

        void solve(int row,int n,vector<string>&board){
            if(row==n){
                ans.push_back(board);
                return;
            }

            for(int col=0;col<n;col++){
                    if(isSafe(row,col,n,board)){
                        board[row][col]='Q';
                        solve(row+1,n,board);
                        board[row][col]='.';
                    }
            }


        }


    vector<vector<string>> solveNQueens(int n) {
            vector<string>board(n);
            string sr(n,'.');
            for(int i=0;i<n;i++){
                board[i]=sr;
                }

                solve(0,n,board);
                return ans;



    }
};



//Im fillig Here COLUMN wise (means i fill 1st col and then i go to 2nd col)



class Solution {
public:
        vector<vector<string>>ans;
      
    bool isSafe(int row,int col,vector<string>board,int n){

            //check for left upper diagonals
            int dupRow=row,dupCol=col;
            while(row>=0 && col>=0){
                if(board[row][col]=='Q')return false;
                row--;
                col--;
            }
            row=dupRow;
            col=dupCol;
            //check for same row elemtns on left side 
                while(col>=0){
                    if(board[row][col]=='Q')return false;
                    col--;
                }
                row=dupRow;
                col=dupCol;
            //check for left lower diagonals

            while(row<n&&col>=0){
                if(board[row][col]=='Q')return false;
                row++;
                col--;
            }

            //No need to check right upper diagonal ,lower diagonal and side elemtns since we didnt even insert at there and all they are marked default '-'
            return true; 

    }

    void solve(int col,vector<string>board,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,board,n);
                board[row][col]='.';//after iteration of that particular column we need to remove the queens placed if it return by failure
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
     vector<string>board(n);    
        string sr(n,'.');
        for(int i=0;i<n;i++){
            board[i]=sr; 
        }
     solve(0,board,n); 
     return ans;
    }
};

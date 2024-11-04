#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }

    bool solve(vector<vector<char>> &board)
    {

        for (int row = 0; row < board.size(); row++)
        {
            for (int col = 0; col < board[0].size(); col++)
            {
                if (board[row][col] == '.')
                { // if empty inside . no row or col got to inside if all filled .
                    // check which value to bve inserted there among from 1-9
                    for (char c = '1'; c <= '9'; c++)
                    {
                        if (isValidPlace(board, row, col, c))
                        {
                            board[row][col] = c;
                            // so its valid keep it and go for next recursion
                            if (solve(board) == true)
                                return true;
                            else
                            {
                                // if not true go back that sudoko u made wrong and remove the number u placed
                                board[row][col] = '.';
                            }
                        }
                    }
                    return false; // if none of 1-9 not fitted return false
                }
            }
        }
        return true; // if not returned anyhting it means sudoko is already filled
    }

    bool isValidPlace(vector<vector<char>> board, int row, int col, char c)
    {
        for (int i = 0; i < 9; i++)
        { // iterate through row and columns
            // check rows
            if (board[row][i] == c)
                return false;
            if (board[i][col] == c)
                return false; // checking columns
            if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == c)
                return false;
        }
        return true;
    }
};
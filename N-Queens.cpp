#include<bits/stdc++.h>
using namespace std;
class Solution {
    bool isSafe(int row, int col, vector<string>&board, int n ){
        int dupRow  = row, dupCol = col;
        //<----
        while(dupRow>=0){
            if(board[dupRow][col]=='Q')return false;
            dupRow--;
        }
        dupRow = row;
        //Upper left diag
        while(--dupRow>=0 && --dupCol>=0){
            if(board[dupRow][dupCol]=='Q')return false;
        }
        //Bottom left Diag
        dupRow  = row, dupCol = col;
        while(++dupRow<n && --dupCol>=0){
            if(board[dupRow][dupCol]=='Q')return false;
        }
        return true;
    }
    void solve(int col , vector<string>&board , vector<vector<string>>&ans, int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row = 0;row<n;row++){
            if(isSafe(row,col,board,n)==true){
                board[row][col] = 'Q';
                solve(col+1, board , ans, n);
                board[row][col] = '.';
            }
        }
    }
    void OptimalSolve(int col , vector<string>&board , vector<vector<string>>&ans, int n, vector<int>&leftRow , vector<int>&upperDiagonal , vector<int>&bottomDiagonal){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row = 0;row<n;row++){
            if(leftRow[row] == 0 && bottomDiagonal[row + col] ==0 && upperDiagonal[(n-1) + (col-row)]==0){
                 board[row][col] = 'Q';
                 leftRow[row] = 1;
                 bottomDiagonal[row + col] =1;
                 upperDiagonal[(n-1) + (col-row)]=1;
                 OptimalSolve(col+1, board, ans, n, leftRow, upperDiagonal, bottomDiagonal);
                 board[row][col] = '.';
                 leftRow[row] = 0;
                 bottomDiagonal[row + col] =0;
                 upperDiagonal[(n-1) + (col-row)]=0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string>board;
        string s(n,'.');
        for(int i =0;i<n;i++)board.push_back(s);
        vector<int>leftRow(n, 0), upperDiagonal(2*n-1,0) , bottomDiagonal(2*n-1,0);
        //solve(0, board, ans, n);
        OptimalSolve(0, board, ans, n, leftRow, upperDiagonal, bottomDiagonal);
        return ans;
    }
};
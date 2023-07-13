#include <bits/stdc++.h> 
using namespace std;
int f(int i , int j, int n , int m,vector<vector<int>> &grid, vector<vector<int>> &dp ){
    // Base Case
    if(i>=n || j>=m)return 1e9;
    if(i==n-1 && j==m-1)return grid[n-1][m-1];
    if(dp[i][j]!= -1)return dp[i][j];
    // Do all Stuffs
    int down = grid[i][j] + f(i,j+1, n,m,grid, dp);
    int right = grid[i][j] + f(i+1,j,n,m,grid, dp);
    // Return Minimal
    return dp[i][j] =  min(down,right);
}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m+1,-1));

    return f(0,0,n,m,grid, dp);
}
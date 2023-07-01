#include<bits/stdc++.h>
using namespace std;
class Solution{
    void dfs(int r, int c, vector<vector<char>>& mat, vector<vector<int>>&vis){
        int n = mat.size(), m = mat[0].size();
        vis[r][c] = 1;
        int dx[4] = {-1,1, 0,0}, dy[4] = {0,0,-1,1};
        for(int i = 0;i<4;i++){
            int newX = r+dx[i] , newY = c + dy[i];
            if(newX>=0 && newX < n && newY>=0 && newY<m && !vis[newX][newY] && mat[newX][newY] =='O'){
                dfs(newX,newY,mat,vis);
            }
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat){
        // code here
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int j =0;j<m;j++){
            if(!vis[0][j] && mat[0][j]=='O'){
                dfs(0,j,mat,vis);
            }
            if(!vis[n-1][j] && mat[n-1][j] =='O'){
                dfs(n-1,j,mat,vis);
            }
        }
        for(int i =0;i<n;i++){
            if(!vis[i][0] && mat[i][0]=='O'){
                dfs(i,0,mat,vis);
            }
            if(!vis[i][m-1] && mat[i][m-1]=='O'){
                dfs(i,m-1,mat,vis);
            }
        }
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j] && mat[i][j] == 'O')mat[i][j] = 'X';
            }
        }
        return mat;
    }
};
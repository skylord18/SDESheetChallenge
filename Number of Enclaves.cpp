#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> todo;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(grid[i][j]==1){
                        todo.push({i,j});
                        vis[i][j] = 1;
                    }
                }
            }
        }
        while(!todo.empty()){
            int x = todo.front().first;
            int y = todo.front().second;
            todo.pop();
            int dx[4] = {-1,1, 0,0}, dy[4] = {0,0,-1,1};
            for(int i = 0;i<4;i++){
                int newX = x+dx[i] , newY = y + dy[i];
                if(newX>=0 && newX<n && newY>=0 && newY<m && !vis[newX][newY] && grid[newX][newY]==1){
                    todo.push({newX,newY});
                    vis[newX][newY] = 1;
                }
            }
        }
        int cnt = 0;
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1)cnt++;
            }
        }
        return cnt;
    }
};
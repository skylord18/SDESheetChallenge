#include <bits/stdc++.h> 
using namespace std;
int minTimeToRot(vector<vector<int>>& grid, int n, int m){
    // Write your code here. 
    queue<pair<int, int>> rotten;
    int leftToRot = 0, cntFresh = 0, time = 0;
    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(grid[i][j]==1)cntFresh++;
            else if(grid[i][j] == 2)rotten.push({i,j});
        }
    }
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1, -1, 0,0};
    while(!rotten.empty()){
        int k = rotten.size();
        leftToRot+=k;
        while(k--){
            int i = rotten.front().first, j = rotten.front().second;
            rotten.pop();
            for(int dir = 0;dir<4;dir++){
                int newX = i + dx[dir] , newY = j+dy[dir];
                if(newX< 0 || newY<0 || newX==n || newY == m || grid[newX][newY] == 0)continue;
                grid[newX][newY ] = 2;
                rotten.push({newX, newY});
            }
        }
        if(!rotten.empty())time++;
    }
    
    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(grid[i][j]==1)return -1;
        }
    }
    
    return time;
}
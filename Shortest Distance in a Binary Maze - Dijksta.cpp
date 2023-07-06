#include <bits/stdc++.h> 
using namespace std;
class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,pair<int, int> destination) {
        // code here
      int n = grid.size(), m = grid[0].size();
      vector<vector<int>> distance(n,vector<int>(m,1e9));
      distance[source.first][source.second] = 0;
      queue<pair<int,pair<int,int>>> todo;      //{dist, {x,y}}
      int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};
      todo.push({0,{source.first, source.second}});
      while(!todo.empty()){
        auto data = todo.front();
        todo.pop();
        int dist = data.first;
        int x = data.second.first;
        int y = data.second.second;
        if(x==destination.first && y==destination.second)return dist;
        for(int i =0;i<4;i++){
          int newX = x + dx[i], newY = y + dy[i];
          if(newX>=0 && newX<n && newY>=0 && newY<m && grid[newX][newY] == 1 && 1 + dist < distance[newX][newY]){
            distance[newX][newY] = 1 + dist;
            todo.push({distance[newX][newY], {newX, newY}});
          }
        }
        
      }
      return -1;
    }
};
#include <bits/stdc++.h> 
using namespace std;
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> distance(n,vector<int>(m, 1e9));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;             //{dist, {x,y}}
        pq.push({0,{0,0}});
        distance[0][0] =0;
        int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};
        while(!pq.empty()){
          auto data = pq.top();
          pq.pop();
          int diff = data.first;
          int x = data.second.first, y = data.second.second;
          if(x== n-1 && y==m-1)return diff;
          for(int i =0;i<4;i++){
            int newX = x + dx[i], newY = y + dy[i];
            if(newX>=0 && newX<n  && newY>=0 && newY<m){
              int newEffort = max(abs(heights[x][y] - heights[newX][newY]), diff);
              if(newEffort<distance[newX][newY]){
                distance[newX][newY] = newEffort;
                //pq.push({})
                pq.push({distance[newX][newY], {newX, newY}});
              }
            }
          }
        }
        return 0;
    }
};
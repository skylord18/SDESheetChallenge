#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
      vector<pair<int,int>> adj[n];
      for(auto it : roads){
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
      }
      int MOD =(int) 1e9+7;
      vector<int> dist(n,1e9), ways(n,0);
      dist[0] = 0, ways[0] = 1;
      priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
      pq.push({0,0});
      while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it : adj[node]){
          int AdjNode = it.first;
          int EdgeW = it.second;
          if(EdgeW + dis < dist[AdjNode]){
            dist[AdjNode] = EdgeW + dis;
            pq.push({dist[AdjNode], AdjNode});
            ways[AdjNode] = ways[node];
          }else if(EdgeW + dis == dist[AdjNode]){
            ways[AdjNode] = (ways[AdjNode] + ways[node]) % MOD;
          }
        }
      }
      return ways[n-1] % MOD;
    }
};
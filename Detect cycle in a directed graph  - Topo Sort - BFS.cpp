#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
      vector<int>indegree(V,0);
      for(int i =0;i<V;i++){
        for(auto it : adj[i]){
          indegree[it]++;
        }
      }
      queue<int> todo;
      vector<int>topo;
      for(int i =0;i<V;i++){
        if(indegree[i]==0)todo.push(i);
      }
      while(!todo.empty()){
        int node = todo.front();
        todo.pop();
        topo.push_back(node);
        for(auto it : adj[node]){
          indegree[it]--;
          if(indegree[it]==0)todo.push(it);
        }
      }
      if(topo.size()==V)return false;
      return true;
    }
};
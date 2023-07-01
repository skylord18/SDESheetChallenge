 bool dfs(int src,int parent,vector<int> adj[],int vis[]){
     vis[src]=1;
     for(auto it:adj[src]){
         if(!vis[it]){
            if(dfs(it,src,adj,vis))
            return true;
         }
         else if(it!=parent)
            return true;
        }
     return false;
 }
string cycleDetection (vector<vector<int>>& edges, int n, int m){
    vector<int> adj[n+1];
   for(int i=0;i<m;i++){
       int u=edges[i][0];
       int v=edges[i][1];
       adj[u].push_back(v);
       adj[v].push_back(u);
   }
    int vis[n+1]={0};
   for(int i=1;i<=n;i++){
       if(!vis[i]){
          if(dfs(i,-1,adj,vis))
            return "Yes";
       }
   }
   return "No";
}
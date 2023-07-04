#include<bits/stdc++.h>
using namespace std;
class Solution {
  void solve(int row, int col, vector<vector<int>>&vis,vector<pair<int,int>>&ans, int row1, int col1, vector<vector<int>>&grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        vis[row][col]=1;
        q.push({row,col});
        int delx[]={-1,0,1,0};
        int dely[]={0,-1,0,1};
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            ans.push_back({r-row1,c-col1});
            for(int i=0; i<4; i++)
            {
                int nr=r+delx[i];
                int nc=c+dely[i];
                if(nr>=0 and nr<n and nc>=0 and nc<m and !vis[nr][nc] and grid[nr][nc]==1)
                {
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
            
        }
    }
    public:
    int countDistinctIslands(vector<vector<int>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        set<vector<pair<int,int>>>s;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!vis[i][j] and grid[i][j]==1)
                {
                    vector<pair<int,int>>v;
                    solve(i,j,vis,v,i,j,grid);
                    s.insert(v);
                }
            }
            
        }
        int size=s.size();
        return size;
    }
};
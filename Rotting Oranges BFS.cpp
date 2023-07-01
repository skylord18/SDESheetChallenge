int rottenOranges(vector<vector<int>>& grid) {
    // Write your code here.
    // Write your code here. 
    int n = grid.size(), m = grid[0].size();
    queue<pair<pair<int,int>, int>> todo;
    //x,y,t
    for(int i=0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(grid[i][j]==2)todo.push({{i,j},0});
        }
    }
    int t = 0;
    while(!todo.empty()){
        auto front = todo.front();
        int sz = todo.size();
        todo.pop();
        int x = front.first.first;
        int y = front.first.second;
        int time = front.second;
        t = max(t, time);
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        for(int i = 0;i<4;i++){
            int newX = x + dx[i];
            int newY = y + dy[i];
            if(newX>=0 && newX<n && newY>=0 && newY<m && grid[newX][newY]==1){
                grid[newX][newY] = 2;
                todo.push({{newX,newY},time+1});
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(grid[i][j]==1)return -1;
        }
    }
    return t;
}
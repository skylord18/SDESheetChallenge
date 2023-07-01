#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int bfsSolve(int start, int end,vector<int> arr,int  n){
    int vis[end+1] = {0};
    vis[start] = 1;
    queue<pair<int,int>>todo;
    todo.push({start, 0});
   // cout<<"Pushing: "<< start<<" "<<0<<endl;
    while(!todo.empty()){
        int prod = todo.front().first;
        int moves = todo.front().second;
        //cout<<"Current :"<<prod<<" "<<moves<<endl;
        todo.pop();
        if(prod==end)return moves;
        for(int i =0;i<n;i++){
            if(prod*arr[i]<=end && !vis[prod*arr[i]]){
                todo.push({prod*arr[i], moves+1});
                //cout<<"Pushing: "<< prod*arr[i]<<" "<<moves+1<<endl;
                vis[prod*arr[i]] = 1;
            }
        }
    }
    return -1;
}
int main() {
	int start, end, n;
	cin>>start>>end>>n;
	vector<int> v(n,0);
	for(int i = 0;i<n;i++)cin>>v[i];
	cout<<bfsSolve(start,end,v, n)<<endl;
	return 0;
}
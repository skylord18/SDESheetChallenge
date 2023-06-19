#include <bits/stdc++.h> 
using namespace std;
vector<int> KMostFrequent(int n, int k, vector<int> &arr){
    // Write your code here.
    map<int,int> mpp;
    for(int i =0;i<n;i++)mpp[arr[i]]++;
    priority_queue<pair<int,int>>pq;
    for(auto it: mpp){
        pq.push({it.second,it.first});
    }
    vector<int> ans;
    while(k--){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}
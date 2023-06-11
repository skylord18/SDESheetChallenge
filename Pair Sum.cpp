#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
   set<pair<int,int>>st;
   map<int,int> mpp;
   vector<vector<int>>vv;
   
   for(int i =0;i<arr.size();i++){
      int req = s- arr[i];
      if(mpp.find(req)!=mpp.end()){
         vector<int> ans;
         ans.push_back(arr[i]);
         ans.push_back(req);
         sort(ans.begin(), ans.end());
         vv.push_back(ans);
      }
      mpp[arr[i]] = i;
      
   }
   sort(vv.begin(), vv.end());
   return vv;
   
}
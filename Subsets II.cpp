#include <bits/stdc++.h> 
using namespace std;
void solve(int Idx, vector<int>&ds, vector<vector<int>>&ans, vector<int>&nums){
    ans.push_back(ds);
    for(int i = Idx;i<nums.size();i++){
        if(i!=Idx && nums[i]==nums[i-1])continue;
        ds.push_back(nums[Idx]);
        solve(Idx+1, ds, ans, nums);
        ds.pop_back();
    }
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr){
    // Write your code here.
    vector<vector<int>>ans;
    vector<int>ds;
    set<vector<int>>st;
    
    sort(arr.begin(), arr.end());
    solve(0,ds,ans,arr);
    
    for(auto it: ans)st.insert(it);
    ans.clear();
    for(auto it : st)ans.push_back(it);
    return ans;
}
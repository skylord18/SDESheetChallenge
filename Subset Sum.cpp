#include <bits/stdc++.h> 
using namespace std;
#include <bits/stdc++.h> 
void solve(int Idx,int sum,  vector<int>&num, vector<int>&ans){
    if(Idx>=num.size()){
        ans.push_back(sum);
        return;
    }
    solve(Idx+1, sum, num, ans);
    sum +=num[Idx];
    solve(Idx+1, sum, num, ans);
}
vector<int> subsetSum(vector<int> &num){
    // Write your code here.
    vector<int> ans;
    int sum = 0;
    solve(0, 0, num, ans);
    sort(ans.begin(), ans.end());
    return ans;
}
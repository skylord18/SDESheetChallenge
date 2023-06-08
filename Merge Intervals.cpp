#include <bits/stdc++.h> 
using namespace std;
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals){
    // Write your code here.
    vector<vector<int>> ans;
    if(intervals.size()==0)return ans;
    sort(intervals.begin(), intervals.end());
    vector<int>tempInterval = intervals[0];
    for(auto it : intervals){
        if(it[0]<=tempInterval[1]){
            tempInterval[1] = max(tempInterval[1], it[1]);
        }else{
            ans.push_back(tempInterval);
            tempInterval = it;
        }
    }
    ans.push_back(tempInterval);
    return ans;
}

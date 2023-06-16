#include <bits/stdc++.h> 
using namespace std;
int func(vector<int>matrix, int target){
    int cnt = 0, low = 0, high = matrix.size()-1;
    while(low<=high){
        int mid = (low +high)/2;
        if(matrix[mid]<=target){
            cnt = mid+1;
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return cnt;
}
int getMedian(vector<vector<int>> &matrix){
    // Write your code here.
    int low = 0, high = INT_MAX, ans  = 0, totalEl = 0;
    for(int i = 0;i<matrix.size();i++)totalEl+=matrix[i].size();
    while(low<=high){
        int mid = low +(high - low)/2, cnt = 0;
        // Count el <= mid in mat
        for(int i =0;i<matrix.size();i++)
            cnt+=func(matrix[i], mid);
        if(cnt<=totalEl/2){
            ans = mid+1;
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return ans;
}
#include <bits/stdc++.h> 
using namespace std;
int f(int i, int j, vector<int> &arr, vector<vector<int>>&dp){
    if(i==j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int mini =INT_MAX;
    for(int k =i;k<j;k++){
        int steps = (arr[i-1] * arr[k] * arr[j]) + f(i,k, arr,dp) + f(k+1, j, arr,dp);
        mini = min(mini, steps);
    }
    return dp[i][j] = mini;
}
int matrixMultiplication(vector<int> &arr, int N){
    // Write your code here.
    int i  = 1, j = arr.size()-1;
    vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
    return f(i,j,arr,dp);
}
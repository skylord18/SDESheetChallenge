#include <bits/stdc++.h> 
using namespace std;
int f(int Idx, int N, vector<int> &price, vector<vector<int>> &dp){
	//base case
	if(Idx==0){
		return price[0] * N;
	}
	//Do all Stuffs
	if(dp[Idx][N]!=-1)return dp[Idx][N];
	int notTake = f(Idx-1, N,price, dp);
	int take = INT_MIN;
	int rodL = Idx + 1;
	if(rodL<=N)
		take = price[Idx] + f(Idx, N-rodL,price, dp);
	//return maximal/minimal
	return dp[Idx][N] = max(take, notTake);
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<vector<int>> dp(price.size(), vector<int>(n+1,-1));
	return f(price.size()-1, n,price, dp);
}
// Tabulation
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<vector<int>> dp(price.size(), vector<int>(n+1,0));
	//return f(price.size()-1, n,price, dp);
	for(int j = 0;j<=n;j++)dp[0][j] = price[0] * j;
	for(int Idx = 1;Idx<n;i++){
		for(int N = 0;N<=n;N++){
			int nonTake = dp[Idx-1][N];
			int rodL = Idx+1;
			int take = INT_MIN;
			if(rodL<=N)take = price[Idx] + dp[idx][N-rodL];
			dp[Idx][N] = max(take, nonTake);
		}
	}
	return dp[n-1][n];
}

// Space Optimization

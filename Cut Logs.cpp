class Solution {
	int f(int i, int j, vector<int>& cuts){
		if(i>j)return 0;
		int ans = INT_MAX;
		for(int cut = i;cut<=j;cut++){
			int cost = (cuts[j+1] - cuts[i-1]) + f(i, cut-1, cuts) + f(cut+1, j, cuts);
			if(cost<ans)ans = min(ans,cost);
		}
		return ans;
	}
public:
    int minCost(int n, vector<int>& cuts) {
        vector<int> nonCut;
        nonCut.push_back(0);
        sort(cuts.begin(), cuts.end());
        for(int i = 0;i<cuts.size();i++)nonCut.push_back(cuts[i]);
        nonCut.push_back(n);
    	return f(1,nonCut.size()-2, nonCut);
    }
};
//Memoization
class Solution {
	int f(int i, int j, vector<int>& cuts, vector<vector<int>>&dp){
		if(i>j)return 0;
		if(dp[i][j]!=-1)return dp[i][j];
		int ans = INT_MAX;
		for(int cut = i;cut<=j;cut++){
			int cost = (cuts[j+1] - cuts[i-1]) + f(i, cut-1, cuts, dp) + f(cut+1, j, cuts, dp);
			if(cost<ans)ans = min(ans,cost);
		}
		return dp[i][j] = ans;
	}
public:
    int minCost(int n, vector<int>& cuts) {
        vector<int> nonCut;
        nonCut.push_back(0);
        sort(cuts.begin(), cuts.end());
        for(int i = 0;i<cuts.size();i++)nonCut.push_back(cuts[i]);
        nonCut.push_back(n);
    	vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
    	return f(1,nonCut.size()-2, nonCut);
    }
};
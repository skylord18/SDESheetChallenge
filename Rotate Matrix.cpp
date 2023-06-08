#include <bits/stdc++.h>
using namespace std;
void rotateMatrix(vector<vector<int>> &matrix, int n, int m){
	vector<vector<int>> ans (n,vector<int>(m,0));
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			ans[j][n-i-1] = matrix[i][j];
		}
	}
	matrix = ans;
}
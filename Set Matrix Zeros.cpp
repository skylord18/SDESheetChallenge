#include <bits/stdc++.h>
using namespace std;
void setZeros(vector<vector<int>> &matrix){
	int n = matrix.size(),m = matrix[0].size();
        vector<int>row(n+1,0), col(m+1,0);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(matrix[i][j]==0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(row[i]==1 || col[j]==1)
                    matrix[i][j] =0;
            }
        }
}
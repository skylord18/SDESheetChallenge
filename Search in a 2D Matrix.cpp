#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size(), m = mat[0].size();
        int low = 0, high = m*n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(mat[mid/m][mid%m]==target)return true;
            else if(mat[mid/m][mid%m]>target)high = mid-1;
            else low = mid+1;
        }
        return false;
}
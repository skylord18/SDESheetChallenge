#include <bits/stdc++.h>
using namespace std;
vector<long long int> generateRow(int n ){
    long long int ans = 1;
    vector<long long int> ansRow;
    ansRow.push_back(ans);
    for(int col = 1;col<n;col++){
        ans*=(n-col);
        ans/=col;
        ansRow.push_back(ans);
    }
    return ansRow;
}
vector<vector<long long int>> printPascal(int n) {
  // Write your code here.
    vector<vector<long long int>> ans;
    for(int i = 1;i<=n;i++){
        vector<long long int> temp = generateRow(i);
        ans.push_back(temp);
    }
    return ans;
}

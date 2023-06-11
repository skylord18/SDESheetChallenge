#include <bits/stdc++.h>
using namespace std;
int LongestSubsetWithZeroSum(vector < int > arr) {
    int sum  = 0, maxi = 0;
    map<int,int>mpp;
    for(int i =0;i<arr.size();i++){
      sum+=arr[i];
      if(sum==0)maxi = i+1;
      else if (mpp.find(sum)==mpp.end()){
        mpp[sum] = i;
      }else{
        maxi = max(maxi,i-mpp[sum]);
      }
    }
    return maxi;
}